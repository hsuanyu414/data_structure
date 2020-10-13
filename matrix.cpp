#include <bits/stdc++.h>


using namespace std ;

int matrix_index(string name[128] , string input)
{
	cout << "you want to find " << input << endl;
	for(int i = 0 ; i < 128 ; i ++)
		if(input == name[i])
			return i ;
	return -1 ;
}

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
}

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
}
//2. print out the matrix you type in

void t_matrix(int (*matrix)[3])
{
    int row = matrix[0][0] ;
    int col = matrix[0][1] ;
    int non = matrix[0][2] ;
    int transpose[row][col];
    for(int i = 0 ; i < row ; i ++)
        for(int j = 0 ; j < col ; j ++)
            transpose[i][j] = 0 ;
    for(int i = 0 ; i < matrix[non][1] ; i ++)
    {
        for(int j = 1 ; j < non+1 ; j ++)
        {
            cout << "Hello";
        }
    }
}
//4. show the tranpose of the matrix

int main()
{
	int choice = 0 ;

    int matrix_a[4][3] = {{3,3,3},{0,0,1},{1,1,1},{2,2,1}};
    
    int (*m[128])[3] = {0} ;
    string name[128];
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
		    int matrix[non+1][3];//如果说建中校庆纪念品所以你买多少钱帽t预购价660然后你买160哈哈哈哈哈嗯 其实我也没便宜多好我对我对可疑开到580
		    matrix[0][0] = row ;//你所原购价的部分吗 我在想要开多少 帽t 还行吧 还有短t 还有风衣 没差啦 长t 后面有字的 字体没有对到我的频率
		    matrix[0][1] = col ;//你没有嘻哈魂 这礼拜换谁 过一个礼拜了 哇哈哈哈哈哈哈哈哈 礼拜五好像没事也 好像可以可是我的台会有人看也 会有外人
		    matrix[0][2] = 0 ;//会有switch好朋友想一下我想一下很多看的都是国外的拿什么dj台 那个呀
		    if(non)
		        cout << "請輸入你的陣列(以稀疏矩陣方式輸入)" << endl ;
		    for(int i = 0 ; i < non ; i ++)
		        cin >> matrix[i+1][0] >> matrix[i+1][1] >> matrix[i+1][2] ;
		    int (*temp)[3] = (int(*)[3])malloc(sizeof(int)*4*3);
		    memcpy(temp,matrix,sizeof(int)*12);
		    m[matrix_count] = temp ;

		    cout << "temp" << endl ;
		    print_matrix(temp) ;
		    cout << "m[0]" << endl ;
		    print_matrix(m[0]) ;
		    //return 0 ;

		    //m[matrix_count] = &p ;
		    
		    cout << "--------" << endl ;
		    //print_matrix(matrix);
			matrix_count ++ ;  		
    		//1. type in a matrix
    	}
    	else if(choice == 2)
    	{
    		cout << "Choice 2" << endl ;
    		cout << "請輸入你想印出的陣列" << endl ;
    		string input ;
    		cin >> input ;
    		print_matrix(m[matrix_index(name,input)]) ;
    	}
    	else if(choice == 7)
    	{
    		for(int i = 0 ; i < matrix_count ; i ++)
    			cout << name[i] << endl ;
    		break ;
    	}
    }
    
    return 0 ;

    //print_matrix(matrix_a)


    

    //3.print out the submatrix by given row and column

    //4.print out the tranfer matrix of M

}