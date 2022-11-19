#include <bits/stdc++.h>
using namespace std;

int main()
{ 
    // size of image
    int row = 4;
    int col = 5;

    int normal[row][col] = {{10, 14, 12, 13, 8},
                            {14, 14, 12, 10, 8},
                            {15, 11, 12, 13, 14},
                            {8, 15, 11, 9, 7}};
    int after_error[row][col];

    int error[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 0 || j == 0)
            {
                after_error[i][j] = normal[i][j];
            }
            else
            {
                if (after_error[i - 1][j - 1] <= min(after_error[i][j - 1], after_error[i - 1][j]))
                {
                    after_error[i][j] = max(after_error[i][j - 1], after_error[i - 1][j]);
                }
                else if (after_error[i - 1][j - 1] >= max(after_error[i][j - 1], after_error[i - 1][j]))
                {
                    after_error[i][j] = min(after_error[i][j - 1], after_error[i - 1][j]);
                }
                else
                {
                    after_error[i][j] = after_error[i][j - 1] + after_error[i - 1][j] - after_error[i - 1][j - 1];
                }
            }
            error[i][j] = normal[i][j] - after_error[i][j];
        }
    }

    cout << "Normal : \n";

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << normal[i][j] << "    ";
        }
        cout << "\n";
    }

    cout << "After : \n";

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << after_error[i][j] << "     ";
        }
        cout << "\n";
    }

    cout << "Error : \n";

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << error[i][j] << "    ";
        }
        cout << "\n";
    }

    string bin_I[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            string str = "";

            for (int k = 7; k >= 0; k--)
            {
                int p = normal[i][j] >> k;
                if (p & 1)
                    str = str + "1";
                else
                    str = str + "0";
            }

            bin_I[i][j] = str;
        }
    }

    cout << "Binary original : \n";

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << bin_I[i][j] << "      ";
        }
        cout << "\n";
    }

    int R[row][col] = {{15, 24, 72, 5, 23},
                       {15, 12, 19, 21, 44},
                       {11, 3, 16, 19, 18},
                       {19, 13, 13, 5, 8}};
    // int R[row][col] = {15, 24, 72, 5, 23,
    //                    15, 12, 19, 21, 44,
    //                    11, 3, 16, 19, 18,
    //                    19, 13, 13, 5, 8};

    string bin_R[row][col];


for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            string binary = bitset<8>(R[i][j]).to_string();
            bin_R[i][j]=binary;
        }
    }

    cout << "Binary R : \n";

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << bin_R[i][j] << "      ";
        }
        cout << "\n";
    }

    string XOR_mat[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            string str = "";
            for (int k = 0; k < 8; k++)
            {
                if (bin_I[i][j][k] == '0' && bin_R[i][j][k] == '0')
                {
                    str += "0";
                }
                else if (bin_I[i][j][k] == '1' && bin_R[i][j][k] == '1')
                {
                    str += "0";
                }
                else
                {
                    str += "1";
                }
            }
            XOR_mat[i][j] = str;
        }
    }

    cout << "XOR Matrix : \n";

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << XOR_mat[i][j] << "      ";
        }
        cout << "\n";
    }

    int XOR_matrix[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            XOR_matrix[i][j] = stoi(XOR_mat[i][j]);
        }
    }

    cout << "XOR Matrix Int : \n";

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << XOR_matrix[i][j] << "      ";
        }
        cout << "\n";
    }

    int encrypted[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            int num = XOR_matrix[i][j];
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

            encrypted[i][j] = dec_value;
        }
    }

    cout << "Encrypted Image : \n";

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << encrypted[i][j] << "      ";
        }
        cout << "\n";
    }

    string encrypted_string[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            encrypted_string[i][j] = XOR_mat[i][j];
        }
    }

    int beeta = 2;
    int alpha = 3;

    int n_alpha = (pow(2, beeta) - 1) * (pow(2, alpha - beeta));

    int lower = ceil(-n_alpha / 2);
    int upper = floor((n_alpha - 1) / 2);

    char group[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (i == 0 || j == 0)
            {
                group[i][j] = 'r';
            }
            else if(i==3 && j==4){
                group[i][j] = 's';
            }
            else if (error[i][j] >= lower && error[i][j] <= upper)
            {
                group[i][j] = 'e';
            }
            else
            {
                group[i][j] = 'n';
            }
        }
    }

    cout << "Grouping : \n";

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << group[i][j] << "      ";
        }
        cout << "\n";
    }

    string reversed[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            reversed[i][j] = encrypted_string[i][j];
        }
    }

    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (i == 3 && j == 4)
            {
                continue;
            }
            for (int k = 0; k < 4; k++)
                swap(reversed[i][j][k], reversed[i][j][8 - k - 1]);
        }
    }

    cout << "8-bit reversed : \n";

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << reversed[i][j] << "      ";
        }
        cout << "\n";
    }

    string label[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            label[i][j] = reversed[i][j];
        }
    }

    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (i == 3 && j == 4)
            {
                label[i][j] = "00110010";
            }
            else if (group[i][j] == 'e')
            {
                if (error[i][j] == 2)
                {
                    label[i][j][0] = '1';
                    label[i][j][1] = '1';
                    label[i][j][2] = '1';
                }
                else if (error[i][j] == 1)
                {
                    label[i][j][0] = '1';
                    label[i][j][1] = '1';
                    label[i][j][2] = '0';
                }
                else if (error[i][j] == 0)
                {
                    label[i][j][0] = '1';
                    label[i][j][1] = '0';
                    label[i][j][2] = '1';
                }
                else if (error[i][j] == -1)
                {
                    label[i][j][0] = '1';
                    label[i][j][1] = '0';
                    label[i][j][2] = '0';
                }
                else if (error[i][j] == -2)
                {
                    label[i][j][0] = '0';
                    label[i][j][1] = '1';
                    label[i][j][2] = '1';
                }
                else if (error[i][j] == -3)
                {
                    label[i][j][0] = '0';
                    label[i][j][1] = '1';
                    label[i][j][2] = '0';
                }
            }
            else if (group[i][j] == 'n')
            {
                label[i][j][0] = '0';
                label[i][j][1] = '0';
            }
        }
    }

    cout << "label : \n";

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << label[i][j] << "      ";
        }
        cout << "\n";
    }

    string label_final[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            label_final[i][j] = label[i][j];
        }
    }

    for (int i = 1; i < row; i++)
    {
        for (int j = 1; j < col; j++)
        {
            if (i == 3 && j == 4)
            {
                continue;
            }
            for (int k = 0; k < 4; k++)
                swap(label_final[i][j][k], label_final[i][j][8 - k - 1]);
        }
    }

    cout << "Label Original : \n";

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << label_final[i][j] << "      ";
        }
        cout << "\n";
    }

    string marked_encrypted[row][col];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            marked_encrypted[i][j] = label_final[i][j];
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (group[i][j] == 'e')
            {
                for (int k = 0; k < 5; k++)
                {
                    marked_encrypted[i][j][k] = '_';
                }
            }
        }
    }

    cout << "Marked Encrypted Image :       ";

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            cout << marked_encrypted[i][j] << "      ";
        }
        cout << "\n";
    }


}
