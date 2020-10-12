#include <bits/stdc++.h>
#include <stdio.h>

using namespace std ;

void print_matrix(int (*matrix)[3])
{
    int row = matrix[0][0] ;
    int col = matrix[0][1] ;
    int non = matrix[0][2] ;
    for(int i = 1 ; i < row+1 ; i ++)
    {
        for(int j = 0 ; j < col ; j ++)
        {
            cout << "0";
        }
        cout << "\n" ;
    }
}

int main()
{
    int choice = 0 ;
    cout << "請輸入你想要的功能\n1. 由鍵盤輸入一個 matrix M\n" ;

    int matrix_a[4][3] = {{3,3,3},{0,0,1},{1,1,1},{2,2,1}};

    print_matrix(matrix_a);

    return 0 ;

    //1. type in a matrix
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
    
    //2.print out the spare matrix you type in
    cout << " row " << " col " << " val " << endl ;
    for(int i = 0 ; i < non+1 ; i ++)
    {
        for(int j = 0 ; j < 3 ; j ++)
            printf("%3d  " , matrix_1[i][j]);
        cout << "\n" ;
    }//by spare matrix

    //3.print out the submatrix by given row and column
    int element_r , element_c ;
    cout << "請輸入你想知道的row與column" << endl ;
    cin >> element_r >> element_c ;
    for(int i = 1 ; i  < non+1 ; i ++)
    {
        cout << "in progress" << endl ;
    }

    //4.print out the tranfer matrix of M
}