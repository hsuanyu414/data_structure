#include <bits/stdc++.h>

using namespace std ;

int main()
{
    int choice = 0 ;
    count << "請輸入你想要的功能\n1. 由鍵盤輸入一個 matrix M\n"

    int row,col,non ;
    cout << "請輸入row、column與non的數量(中間以空格隔開)" << endl ;
    cin >> row >> col >> non;
    int matrix_1[non+1][3];
    matrix_1[0][0] = row ;
    matrix_1[0][1] = col ;
    matrix_1[0][2] = 0 ;
    cout << "請輸入你的陣列(以稀疏矩陣方式輸入)" << endl ;
    for(int i = 0 ; i < non ; i ++)
        cin >> matrix_1[i+1][0] >> matrix_1[i+1][1] >> matrix_1[i+1][2] ;
    
    
    cout << " row " << " col " << " val " << endl ;
    for(int i = 0 ; i < non+1 ; i ++)
    {
        for(int j = 0 ; j < 3 ; j ++)
            printf("%3d  " , matrix_1[i][j]);
        cout << "\n" ;
    }//print out the spare matrix you type in
}