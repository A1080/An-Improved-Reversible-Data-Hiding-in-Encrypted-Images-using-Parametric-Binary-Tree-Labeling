#include<bits/stdc++.h>
using namespace std;

void dataExtraction(){
    int row=4;
    int col=5;
    // encrypted image matrix
    int encryptImage[row][col]={{5, 22, 68, 8, 31 },
{1 ,181, 5, 2, 29},
{4 ,8, 1, 5 ,28},
{27, 0, 4, 3, 50}};

    // decimal to binary conversion of encrypt image
    string encryptImage_Bin[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            string binary = bitset<8>(encryptImage[i][j]).to_string();
            encryptImage_Bin[i][j]=binary;
        }
    }

cout<<"Encrypted Image in binary format:\n";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<encryptImage_Bin[i][j]<<" ";
        }
        cout<<endl;
    }

    
// reversing the binary matrix
    string encryptImage_Bin_reverse[row][col];
        string temp;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            temp=encryptImage_Bin[i][j];
            reverse(temp.begin(),temp.end());
            encryptImage_Bin_reverse[i][j]=temp;
        }
    }

cout<<"Encrypted Image in reverse format:"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<encryptImage_Bin_reverse[i][j]<<" ";
        }
        cout<<endl;
    }

//find the pe pixel and extracting the hidden data
string message;
string s1;
string check;
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            check=encryptImage_Bin_reverse[i][j].substr(0,3);
            if(i==3 && j==4){
                continue;
            }
            if(check=="111" || check=="110" || check=="101" || check=="100" || check=="011" || check=="010"){
                s1=encryptImage_Bin_reverse[i][j].substr(3,5);
                reverse(s1.begin(),s1.end());
                message.append(s1);
            }
        }
    }
    cout<<endl;
    cout<<message;   
    reverse(message.begin(),message.end());
    cout<<endl;
    cout<<message;
    string final_msg;
    int cnt_dash=3;
    message=message.substr(cnt_dash,message.size()-1);
    cout<<endl;
    // cout<<final_msg;
    cout<<message;
    vector<int>message_dec;
    int i=0;
    // string message_dec;
    int bin_to_dec_msg;
// converting the message 5 bits into int and storing in the vector
    for(int i=0;i<message.size();i+=8){
        s1=message.substr(i,8);
        bin_to_dec_msg=stoi(s1, 0, 2);
        message_dec.push_back(bin_to_dec_msg);
    }

    cout<<endl;
    // cout<<bin_to_dec_msg;
    for(auto it:message_dec){
        cout<<it<<" ";
    }

    string dec_msg_str;
    string k;
    for(int i=0;i<message_dec.size();i++){
        k=to_string(message_dec[i]);
        dec_msg_str.append(k);
    }

    cout<<endl;
    cout<<dec_msg_str;
    cout<<endl;
    int dec_msg_int=stoi(dec_msg_str);
    cout<<endl;
    cout<<dec_msg_int;

    string mymessage;
    for(int i=0;i<message_dec.size();i++){
        char convertedChar = (char)('a' + message_dec[i]);
        mymessage.push_back(convertedChar);
    }

    cout<<endl;
    // cout<<mymessage;
    cout<<"---------Extracted data: "<<mymessage;
}

void imageDecryption(){
    int row=4;
    int col=5;

    int encryptImage[row][col]={{5, 22, 68, 8, 31 },
{1 ,181, 5, 2, 29},
{4 ,8, 1, 5 ,28},
{27, 0, 4, 3, 50}};
    // decimal to binary conversion of encrypt image
    string encryptImage_Bin[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            string binary = bitset<8>(encryptImage[i][j]).to_string();
            encryptImage_Bin[i][j]=binary;
        }
    }
    cout <<"\nEncrypted image bin-> \n";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<encryptImage_Bin[i][j]<<" ";
        }
        cout<<endl;
    }


    // reversing the binary matrix
    string encryptImage_Bin_reverse[row][col];
        string temp;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            temp=encryptImage_Bin[i][j];
            reverse(temp.begin(),temp.end());
            encryptImage_Bin_reverse[i][j]=temp;
        }
    }

    cout<<"Encrypted matrix reverse:"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<encryptImage_Bin_reverse[i][j]<<" ";
        }
        cout<<endl;
    }


    string message;
    string s1;
    string check1;
    string check2;
    int prediction_error_value[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            check1=encryptImage_Bin_reverse[i][j].substr(0,3);
            check2=encryptImage_Bin_reverse[i][j].substr(0,2);
            if((i==3 && j==4) || (i==0 || j==0) || check2=="00"){
                // continue;
                prediction_error_value[i][j]=5;
            }
            else if(check1=="111"){;
                prediction_error_value[i][j]=2;
            }
            else if(check1=="110"){
                prediction_error_value[i][j]=1;
            }
            else if(check1=="101"){
                prediction_error_value[i][j]=0;
            }
            else if(check1=="100"){
                prediction_error_value[i][j]=-1;
            }
            else if(check1=="011"){
                prediction_error_value[i][j]=-2;
            }
            else if(check1=="010"){
                prediction_error_value[i][j]=-3;
            }
        }
    }

cout<<"Prediction error value:\n";
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cout<<prediction_error_value[i][j]<<" ";
        }
        cout<<endl;
    }

  
int pseudo_random_mtx[row][col] = {{15, 24, 72, 5, 23},
                       {15, 12, 19, 21, 44},
                       {11, 3, 16, 19, 18},
                       {19, 13, 13, 5, 8}};

string pseudo_random_mtx_bin[row][col];
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            string binary = bitset<8>(pseudo_random_mtx[i][j]).to_string();
            pseudo_random_mtx_bin[i][j]=binary;
        }
    }

string prediction_mtx[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            prediction_mtx[i][j] = encryptImage_Bin[i][j];
        }
    }



    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 0 || j == 0)
            {
                for (int k = 0; k < 8; k++)
                {
                    if (encryptImage_Bin[i][j][k] == '0' && pseudo_random_mtx_bin[i][j][k] == '0')
                    {
                        prediction_mtx[i][j][k] = '0';
                    }
                    else if (encryptImage_Bin[i][j][k] == '0' && pseudo_random_mtx_bin[i][j][k] == '1')
                    {
                        prediction_mtx[i][j][k] = '1';
                    }
                    else if (encryptImage_Bin[i][j][k] == '1' && pseudo_random_mtx_bin[i][j][k] == '1')
                    {
                        prediction_mtx[i][j][k] = '0';
                    }
                    else
                    {
                        prediction_mtx[i][j][k] = '1';
                    }
                }
            }else{
                prediction_mtx[i][j] = '00000000';
            }
        }
    } 

    cout << "Prediction matrix : \n";

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << prediction_mtx[i][j] << "  ";
        }
        cout << "\n";
    }






    int prediction_mtx_int[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            prediction_mtx_int[i][j] = stoi(prediction_mtx[i][j]);
        }
    }



    cout << "Dec Int : \n";

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << prediction_mtx_int[i][j] << "      ";
        }
        cout << "\n";
    }


    int prediction_mtx_final[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int num = prediction_mtx_int[i][j];
            int dec_value = 0;

            // Initializing base value to 1, i.e 2^0
            int base = 1;

            int temp = num;
            while (temp)
            {
                int last_digit = temp % 10;
                temp = temp / 10;

                dec_value += last_digit * base;

                base = base * 2;
            }

            prediction_mtx_final[i][j] = dec_value;
        }
    }


    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 0 || j == 0)
            {
                continue;
            }
            else
            {
                if (prediction_mtx_final[i - 1][j - 1] <= min(prediction_mtx_final[i][j - 1], prediction_mtx_final[i - 1][j]))
                {
                    prediction_mtx_final[i][j] = max(prediction_mtx_final[i][j - 1], prediction_mtx_final[i - 1][j]);
                }
                else if (prediction_mtx_final[i - 1][j - 1] >= max(prediction_mtx_final[i][j - 1], prediction_mtx_final[i - 1][j]))
                {
                    prediction_mtx_final[i][j] = min(prediction_mtx_final[i][j - 1], prediction_mtx_final[i - 1][j]);
                }
                else
                {
                    prediction_mtx_final[i][j] = prediction_mtx_final[i][j - 1] + prediction_mtx_final[i - 1][j] - prediction_mtx_final[i - 1][j - 1];
                }
            }
            // error[i][j] = normal[i][j] - after_error[i][j];
        }
    }

        cout<<"Prediction matrix final : \n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << prediction_mtx_final[i][j] << "      ";
        }
        cout << "\n";
    }

int final_mtx[row][col]={
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0},
    {0,0,0,0}
};
int k=0;
vector<int>prediction_error_value_pn={-4,6,7,3};
int special_pixel_error=-1;
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        if(i==0 || j==0){
            final_mtx[i][j]=prediction_mtx_final[i][j];
        }
        else if(i==3 && j==4){
            final_mtx[i][j]=prediction_mtx_final[i][j]+special_pixel_error;
        }
        else if(prediction_error_value[i][j]==5){
            final_mtx[i][j]=prediction_mtx_final[i][j]+prediction_error_value_pn[k];
            k++;
        }
        else{
            final_mtx[i][j]=prediction_mtx_final[i][j]+prediction_error_value[i][j];
        }
    }
}

cout<<"Original Image matrix after decryption: "<<endl;
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        cout<<final_mtx[i][j]<<" ";
    }
    cout<<"\n";
}

}
int main(){
    cout<<"----------------Data Extraction start---------------\n";
    dataExtraction();
    cout<<"\n\n";
    cout<<"----------------Image Decryption start--------------\n";
    imageDecryption();
    return 0;
}
