string message,binary_message;
int count=0,counter=0;
cout<< "\ndon't use spaces and Enter the message: ";
cin>>message;
cout<<message<<"\n";
vector<double> length_char;


vector<int>alph_to_num;
int val;
for(int i=0;i<message.size();i++){
    val=(int)message[i] - 97;
    alph_to_num.push_back(val);
}
cout<<endl;
    for(auto it:alph_to_num){
        cout<<it<<" ";
    }
// string msg_bin;
for(int i=0;i<alph_to_num.size();i++){
        string bnry = bitset<8>(alph_to_num[i]).to_string();
        binary_message.append(bnry);
}
cout<<endl;
cout<<binary_message;


 cout<<"\nbefore encryption: "<<binary_message<<"\n";
 reverse(binary_message.begin(), binary_message.end());
cout<<"\nafter encryption: "<<binary_message<<"\n\n";



    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
           if((group[i][j]=='e') && (count!=binary_message.length()) ){
            for(int k=0;k<5;k++){
                if((marked_encrypted[i][j][k] == '_') && (count!=binary_message.length())){
                    marked_encrypted[i][j][k] = binary_message[count];
                    count += 1;
                }
                
            }
           } 
        }
            }
   
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << marked_encrypted[i][j] << " ";
        }
        cout << "\n";
    }

string  bin_dash_check;
int cnt_dash=0;
for(int i=1;i<row;i++){
    for(int j=1;j<col;j++){
        bin_dash_check=marked_encrypted[i][j];
        for(int k=0;k<bin_dash_check.size();k++){
            if(bin_dash_check[k]=='_'){
                marked_encrypted[i][j][k]='0';
                cnt_dash++;
            }
        }
    }
}
cout<<endl;
cout<<"dash count: "<<cnt_dash;
// printing marked encrypted after changing _ to 0
cout<<endl;
cout<<"Final encrypted matrix in binary format: \n";
for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
        cout<<marked_encrypted[i][j]<<" ";
    }
    cout<<"\n";
}
    //binary to decimal
     int embeded_mtx_dec[row][col];
     for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            
           
            // else{
                embeded_mtx_dec[i][j]=stoi(marked_encrypted[i][j], 0, 2);
            // }
        }
     }

cout<<"Final encrypted matrix in decimal format: "<<endl;
    for(int i=0;i<row;i++){
        cout<<"{";
        for(int j=0;j<col;j++){
            cout<<embeded_mtx_dec[i][j]<<",";
        }
        cout<<"}";
        cout<<"\n";
    }