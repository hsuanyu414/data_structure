#include <iostream>
#include <fstream>
#include <cstring>
#include "tree.h"
#include <termios.h>
#include <unistd.h> 

int getch (void)
{
    int ch;
    struct termios oldt, newt;
 
    tcgetattr(STDIN_FILENO, &oldt);
    memcpy(&newt, &oldt, sizeof(newt));
    newt.c_lflag &= ~( ECHO | ICANON | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ICRNL);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return ch;
}


using namespace std ;

int main()
{
	fstream file ;
	char buffer[100] ;
	
	BST store ;

	file.open("product.txt",ios::in) ;
	if(!file)
		cout << "檔案開啟失敗" << endl ;
	else 
	{
		while(!file.eof())
		{
			file.getline(buffer , sizeof(buffer)) ;
			//cout << buffer << endl ;
			int key_,price_,amount_ ;
			char *p = strtok(buffer , " ");//切三次
			key_ = (int)strtol(p , NULL , 10) ;//tag
			p = strtok(NULL," ");
			price_ = (int)strtol(p , NULL , 10) ;//price
			p = strtok(NULL," ");
			amount_ = (int)strtol(p , NULL , 10) ;//amount
			store.insert_bst(key_, price_, amount_) ;
		}
		file.close() ;
	}

	int choice = 0 ;
	char filename[100] = { 0 } ;
	// cout << "請輸入文字檔名字" << endl ;
	// cin >> filename ;
	while(1)
	{
		cout << "\n請輸入你要的功能" << endl ;
		cout << "1. 尋找商品" << endl ;
		cout << "2. 進口商品" << endl ;
		cout << "3. 刪除商品" << endl ;
		cout << "4. 出口商品" << endl ;
		cout << "5. 列出所有商品" << endl ;
		cout << "6. 更改商品編號" << endl ;
		cout << "7. 尋找最貴的商品的商品編號" << endl ;
		cout << "8. 輸出至一個檔案" << endl ;
		cout << "9. 離開" << endl ;
		cin >> choice ;
		if(choice == 1 )//找東西
		{
			cout << "請輸入商品編號 " << endl ;
			int product_key = 0 ;
			cin >> product_key ;
			tree_node *target = store.search(product_key) ;
			if(target == NULL)
				cout << "查無此商品" << endl ;
			else
			{
				print_data(target) ;
				while(1)
				{
					char a = getch();
					if(a == 'N' || a == 'n')
					{
						cout << "下一個商品" << endl ;
						target = store.successor(target) ;
						if(target == NULL)
						{
							cout << "已經到最後一個商品了" << endl ;
							break ;
						}
						else
							print_data(target) ;
					}
					else if(a == 'R' || a == 'r')
					{
						cout << "Return to the menu" << endl ;
						break ;
					}
				}
			}
		}
		else if(choice == 2 )//進口東西
		{
			cout << "請輸入商品編號及進口數量" ;
			int key_,price_,amount_ ;
			cin >> key_ >> amount_ ;
			tree_node *target = store.search(key_) ;
			if(target == NULL)//增加這個商品
			{
				cout << "\nThe product you want to insert is not in the database" << endl ;
				cout << "Please input the price: " ;
				cin >> price_ ;
				store.insert_bst(key_, price_, amount_) ;
				target = store.search(key_) ;
				cout << "\n=== you have inserted: ===" << endl ;
				print_data(target) ;
				cout << "=== into the tree ===" << endl ;
			}
			else
			{
				print_data(target) ;
				target->amount += amount_ ;
				cout << "\n=== you have inserted: ===" << endl ;
				print_data(target) ;
			}

		}
		else if(choice == 3 )//刪除商品
		{
			cout << "請輸入你要刪除的商品編號"  ;
			int product_key ;
			cin >> product_key ;
			tree_node *target = store.search(product_key) ;
			if(target == NULL)
				cout << "查無此商品" << endl ;
			else
			{
				cout << "=== you have just deleted: ===" << endl ;
				print_data(target) ;
				store.delete_bst(product_key) ;
			}
		}
		else if(choice == 4 )
		{
			int key_,amount_ ;
			cout << "請輸入出口的商品編號及數量" << endl ;
			cin >> key_ >> amount_ ;
			tree_node *target = store.search(key_) ;
			if(target == NULL)
				cout << "The product you want to export is not exists in database." << endl ;
			else
			{
				if(target->get_amount() < amount_)
					cout << "The product you want to export is not enough in database." << endl ;
				else
				{
					cout << "=== you have just export: ===" << endl ;
					print_data(target) ;
					target->amount -= amount_ ;
					cout << "=== remains: ===" << endl ;
					print_data(target) ;
				} 
			}
		}
		else if(choice == 5 )
		{
			cout << "choice 5" << endl ;
			store.list_all() ;
		}
		else if(choice == 6 )//更改商品編號
		{
			cout << "choice 6" << endl ;
		}
		else if(choice == 7)//找最貴的東西
		{
			cout << "choice 7" << endl ;
		}
		else if(choice == 8)//輸出至一個檔案
		{
			cout << "choice 8" << endl ;
		}
		else if(choice == 9)//離開
			break ;
		else
			cout << "THIS FUNCTION DOES NOT EXIST" << endl ;
	}

	return 0 ;
}