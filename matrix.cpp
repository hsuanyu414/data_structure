#include <iostream>
#include <cstring>
#include <string>

using namespace std ;

int (*m[128])[3] = {0} ;
string name[128];


int matrix_index(string input)
{
	cout << "you want to find " << input << endl;
	for(int i = 0 ; i < 128 ; i ++)
		if(input == name[i])
			return i ;
	return 0 ;
}//for the given name to find the matrix index, if there are no matrix matched, it will return 0 as defalut.


void print_menu()
{
	cout << "請輸入你想要的功能" << endl ;
	cout << "1. 由鍵盤輸入一個 matrix M" << endl; ;
	cout << "2. 由螢幕顯示 matrix M 的內容" << endl ;
	cout << "3. 指定 matrix M 之 submatrix 的行編號及列編號，顯示該 submatrix 的內容" << endl ;
	cout << "4. 顯示 M 的轉置矩陣內容" << endl ;
	cout << "5. 讀入兩個 matrix M1 及 M2，做 M1 及 M2 的加法，並顯示 M1+M2 的結果" << endl ;
	cout << "6. 讀入一個 square matrix M，計算 Mk(k 為大於等於 2 的整數)，並顯示 Mk 的結果" << endl ;
	cout << "7. 離開" << endl ;
}//print out the menu.

void print_matrix(int (*matrix)[3] )
{
	int row = matrix[0][0] ;
	int col = matrix[0][1] ;
	int non = matrix[0][2] ;
	int k = 1 ;
	for(int i = 0 ; i < row ; i ++)
	{
		for(int j = 0 ; j < col ; j ++)
		{
			if(k <= matrix[0][2] && i == matrix[k][0] && j == matrix[k][1])
			{
				printf("%3d ",matrix[k][2]);
				k ++ ;
			}
			else
				cout << "  0 " ;
		}
		cout << "\n" ;
	}
}//2. print out the matrix you type in(in sparse matrix)

void submatrix(int (*matrix)[3])
{
	int max_row = matrix[0][0] ;
	int max_col = matrix[0][1] ;
	int row_print[max_row] = {0} ;
	int col_print[max_col] = {0} ;

	cout << "請輸入你想印出的子矩陣的列號(中間以空格隔開)結束請輸入-1" << endl ;
	int input = 0 ;
	while(1)
	{
		cin >> input ;
		if(input == -1)
			break ;
		else if(input < max_row)
			row_print[input] = 1 ;
		else
			cout << "沒有這一列" << endl ;
	}
	cout << "請輸入你想印出的子矩陣的行號(中間以空格隔開)結束請輸入-1" << endl ;
	while(1)
	{
		cin >> input ;
		if(input == -1)
			break ;
		else if(input < max_col)
			col_print[input] = 1 ;
		else
			cout << "沒有這一行" << endl ;
	}
	int non = matrix[0][2] ;
	int k = 1 ;
	for(int i = 0 ; i < max_row ; i ++)
	{
		int j = 0 ;
		for(j = 0 ; j < max_col ; j ++)
		{
			if(k <= matrix[0][2] && i == matrix[k][0] && j == matrix[k][1])
			{
				if(row_print[i]&&col_print[j])
					printf("%3d ",matrix[k][2]);
				k ++ ;
			}
			else
				if(row_print[i]&&col_print[j])
					cout << "  0 " ;
		}
		if(row_print[i]&&col_print[j])
			cout << "\n" ;
	}

}
//3.show the submatrix

void t_matrix(int (*matrix)[3])
{
	int row = matrix[0][0] ;
	int col = matrix[0][1] ;
	int non = matrix[0][2] ;
	int answer[non+1][3] = {0};
	answer[0][0] = row ;
	answer[0][1] = col ;
	answer[0][2] = non ;
	int pos = 1	 ;
	int check[col][2] = {0};
	for(int i = 1 ; i < non+1 ; i ++)
		check[matrix[i][1]][0] ++ ;
	for(int i = 0; i < col ; i ++)
	{
		check[i][1] = pos ;
		pos += check[i][0] ;	
	}
	for(int i = 1 ; i < non+1 ; i ++)
	{
		int index = matrix[i][1] ;
		answer[check[index][1]][0] = matrix[i][1] ;
		answer[check[index][1]][1] = matrix[i][0] ;
		answer[check[index][1]][2] = matrix[i][2] ;
		check[index][1] ++ ;
	}
	cout << "matrix" << endl ;
	print_matrix(matrix);
	cout << "answer" << endl ;
	print_matrix(answer);
}//4.show the tranpose matrix(in progress)

//5.given two matrix and do the addition
void matrix_addition(int (*a)[3] , int (*b)[3])
{
	if((a[0][0]!=b[0][0])||(a[0][1]!=b[0][1]))
	{
		cout << "這兩個矩陣不能做加法" << endl ;
		return ;
	}
	else
	{
		int row = a[0][0];
		int col = a[0][1];
		//int non = a[0][2] + b[0][2] + 1;
		int answer[row][col] = {0};
		for(int i = 0 ; i < a[0][2] ; i ++)
			answer[a[i+1][0]][a[i+1][1]] += a[i+1][2];
		for(int i = 0 ; i < b[0][2] ; i ++)
			answer[b[i+1][0]][b[i+1][1]] += b[i+1][2];
		for(int i = 0 ; i < row ; i ++)
		{
			for(int j = 0 ; j < col ; j++)
				printf("%3d ", answer[i][j]);
			cout << "\n" ;
		}//by common matrix

	}
}

void matrix_pow(int (*a)[3] , int p)
{
	if(a[0][0]!=a[0][1])
	{
		cout << "你輸入的矩陣不是方陣" << endl;
		return ;
	}
	else if(p == 0)
	{
		for(int i = 0 ; i < a[0][0] ; i ++)
		{
			for(int j = 0 ; j < a[0][1] ; j ++)
			{
				if(i == j)
					cout << "   1";
				else
					cout << "   0";
			}
			cout << "\n" ;
		}
	}
	else
	{
		int row = a[0][0] ;
		int col = a[0][1] ;
		int non = a[0][2] ;
		int answer[row][col] = {0} ;
		int matrix[row][col] = {0} ;
		for(int i = 0 ; i < row ; i ++)
			for(int j = 0 ; j < col ; j ++)
			{
				answer[i][j] = 0 ;
				matrix[i][j] = 0 ;
			}
		for(int i = 1 ; i < non+1 ; i ++)
		{
			answer[a[i][0]][a[i][1]] = a[i][2];
			matrix[a[i][0]][a[i][1]] = a[i][2];
		}
		for(int i = 1 ; i < p ; i ++)
		{
			int temp[row][col] = {0} ;	
			for(int j = 0 ; j < row ; j ++)
				for(int k = 0 ; k < col ; k ++)
					for(int l = 0 ; l < row ; l ++)
					{
						temp[j][k] += answer[j][l]*matrix[l][k];
						cout << answer[j][l] << " * " << matrix[l][k] << endl;
						cout << i << j << "is "<< temp[j][k] << endl ;
					}
			for(int j = 0 ; j < row ; j ++)
				for(int k = 0 ; k < col ; k ++)
					answer[j][k] = temp[j][k] ;
		}
			cout << "finish" << endl;
		for(int i = 0 ; i < row ; i ++)
		{
			for(int k = 0 ; k < col ; k ++)
				printf("%4d", answer[i][k]);
			cout << "\n" ;
		}
	}
	return;
}
//6. given a square matrix and calculate M^k

//7. exit

int main()
{
	int choice = 0 ;
	int test[3][3] = {{2,2,2},{0,0,9},{1,1,7}};
	matrix_pow(test,2);
	return 0 ;
	int matrix_count = 0 ;
   
	while(1)
	{
		print_menu();
		cin >> choice ;
		cout << "The option you choose is " << choice << endl ;
		if (choice == 0)
			continue ;
		else if(choice == 1)
		{
			cout << "請輸入你矩陣的名字(不能有空格)" ;
			string temp_name;
			cin >> temp_name ;
			int valid = 1;
			for(int i = 0 ; i <= matrix_count ; i ++)
				if(name[i]==temp_name)
				{
					cout << "請勿輸入重複的名字" << endl ;
					valid = 0 ;
				}
			if(!valid)
				continue ;
			name[matrix_count] = temp_name ;
			int row,col,non ;
			cout << "請輸入row、column與non的數量(中間以空格隔開)" << endl ;
			cin >> row >> col >> non;
			int matrix[non+1][3] = {0};//如果说建中校庆纪念品所以你买多少钱帽t预购价660然后你买160哈哈哈哈哈嗯 其实我也没便宜多好我对我对可疑开到580
			matrix[0][0] = row ;//你所原购价的部分吗 我在想要开多少 帽t 还行吧 还有短t 还有风衣 没差啦 长t 后面有字的 字体没有对到我的频率
			matrix[0][1] = col ;//你没有嘻哈魂 这礼拜换谁 过一个礼拜了 哇哈哈哈哈哈哈哈哈 礼拜五好像没事也 好像可以可是我的台会有人看也 会有外人
			matrix[0][2] = non;//会有switch好朋友想一下我想一下很多看的都是国外的拿什么dj台 那个呀
			if(non)
				cout << "請輸入你的陣列(以稀疏矩陣方式輸入)" << endl ;
			for(int i = 0 ; i < non ; i ++)
				cin >> matrix[i+1][0] >> matrix[i+1][1] >> matrix[i+1][2] ;

			int (*temp)[3] = (int(*)[3])malloc(sizeof(int)*(non+1)*3);
			memcpy(temp,matrix,sizeof(int)*(non+1)*3);
			m[matrix_count] = temp ;

			cout << "temp" << endl ;
			print_matrix(temp) ;
			//return 0 ;

			//m[matrix_count] = &p ;
			
			cout << "--------" << endl ;
			cout << "matrix" << endl;
			print_matrix(matrix);
			matrix_count ++ ;  		
			//1. type in a matrix
		}
		else if(choice == 2)
		{
			cout << "請輸入你想印出的陣列" << endl ;
			string input ;
			cin >> input ;
			print_matrix(m[matrix_index(input)]) ;
		}
		else if(choice == 3)
		{
			cout << "請輸入矩陣" << endl ;
			string input ;
			cin >> input ;
			submatrix(m[matrix_index(input)]);
		}
		else if(choice == 4)
		{
			cout << "請輸入你想轉置的矩陣" << endl ;
			string input ;
			cin >> input ;
			t_matrix(m[matrix_index(input)]);
		}
		else if(choice == 5)
		{
			cout << "請輸入M1的名字" << endl ;
			string input_1 ;
			cin >> input_1 ;
			cout << "請輸入M2的名字" << endl ;
			string input_2 ;
			cin >> input_2 ;
			matrix_addition(m[matrix_index(input_1)],m[matrix_index(input_2)]);
		}
		else if(choice == 6)
		{
			int pow;
			string input;
			cout << "請輸入M的名字" << endl ;
			cin >> input ;
			cout << "請輸入p" << endl ;
			cin >> pow ;
			matrix_pow(m[matrix_index(input)], pow);
		}
		else if(choice == 7)
			break ;
	}
	
	return 0 ;

}