#include <iostream>
#include <termios.h>
#include <unistd.h> 
#include <cstring>
#include "stack.h"
#include <stdio.h>
#include "error.h"

using namespace std ;

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

int pri(char op)//for the infix to postfix to judge the priority of the operation
{
	if(op == '+' || op == '-')
		return 1 ;
	else if(op == '*' || op == '/')
		return 2 ;
	return 0 ;
}

void infix_minus(char* infix , char* minus_infix)
{
	char test[MAX] = {0} ;
	int index = 0 ; 
	for(int i = 0 ; i < strlen(infix) ; i ++)
	{
		if(infix[i]>='0' && infix[i]<='9')
			test[index++] = infix[i] ;
		else if(infix[i] == '(' && infix[i+1] == '-')//(-1
		{
			test[index++] = '(' ;
			test[index++] = '0' ;
		}
		else
			test[index++] = infix[i] ;
	}
	for(int i = 0 ; i < strlen(test) ; i++)
		minus_infix[i] = test[i] ;
}

void infix_space(char* infix )//plus some space to seperate the oprander
{
	char test[MAX] = {0} ;
	int index = 0 ; 
	for(int i = 0 ; i < strlen(infix) ; i ++)
	{
		if(infix[i]>='0' && infix[i]<='9')
			test[index++] = infix[i] ;
		else
		{
			test[index++] = 32 ;
			test[index++] = infix[i] ;
		}
	}
	for(int i = 0 ; i < strlen(test) ; i++)
		infix[i] = test[i] ;
}

void infix_to_postfix(char* infix, char* postfix)
{ //change the infix to postfix
	infix_space(infix) ;
    STACK<char> s;
    s.push(0);
    int i = 0 , j = 0 , top = 0 ;
    for(; infix[i] != '\0'; i++)
	{
    	switch(infix[i])
    	{ 
	        case '(': 
	            s.push(infix[i]); 
	            break; 
	        case '+': case '-': case '*': case '/': 
	            while(pri(s.top()) >= pri(infix[i])) {//比較優先順序 
	                postfix[j++] = s.top();
	                s.pop();
	            } 
	            s.push(infix[i]); 
	            break; 
	        case ')': 
	            while(s.top() != '(') {
	                postfix[j++] = s.top();
	                s.pop();
	            } 
	            s.pop(); 
	            break; 
	        default:
	            postfix[j++] = infix[i];
        }
    }
    while(!s.empty()) { 
        postfix[j++] = s.top();
        s.pop() ;
    }
} 




float cal(char op , float oprand1 , float oprand2)
{
	switch(op)
	{
		case '*': return (oprand1*oprand2) ;
		case '/': return (oprand1/oprand2) ;
		case '-': return (oprand1-oprand2) ;
		case '+': return (oprand1+oprand2) ;
	}
	return 0 ;
}

float postfix_to_ans(char* postfix)
{
	STACK<float> s;
	int index = 0 ;
	while(postfix[index]!='\0')
	{
		//cout << "NOW PROCEEDING " << postfix[index] << endl; 
		if(postfix[index]>='0' && postfix[index]<='9')//if is number than calaulate what is it
		{	
			float val = postfix[index++]-48 ;
			while(postfix[index]>='0' && postfix[index]<='9')
			{
				val *= 10 ;
				val += postfix[index++]-48 ;
			}
			s.push(val) ;
		}
		else if(postfix[index] == 32) //if it is space than escape
			index ++ ;//just skip
		else
		{
			float a = s.top(); s.pop() ;
			float b = s.top(); s.pop() ;
			float temp = cal(postfix[index++] , b , a);
			s.push(temp) ;
		}
	}
	return s.top();
}


int main()
{

	while(1)
	{
		int index = 0 ;
		char infix[MAX] = {0} ;
		char infix_back[MAX] = {0} ;
		char minus_infix[MAX] = {0} ;
		char postfix[MAX] = {0} ;
	
		cout << "Please enter an infix expression and press enter:" ;
		while(1)
		{
			char a = getch() ;
			if( a == '\e')
			{
				cout << "\n你按了ESC﹑跳出程序中..." << endl ;
				return 0 ;
			}
			else if( a == '\n')
			{
				cout << endl ;
				break ;
			}
			else
			{
				cout << a ;
				infix[index++] = a ;
			}
		}
		illegal_character(infix) ;
		illegal_operand(infix) ;
		first_character_an_operator(infix) ;
		last_character_an_operator(infix) ;
		right_parenthesis_followed_by_an_identifier(infix) ;
		operator_followed_by_an_operator(infix) ;
		left_parenthesis_followed_by_an_operator(infix) ;
		identifier_followed_by_a_left_parenthesis(infix) ;
		right_parenthesis_followed_by_a_left_parenthesis(infix) ;
		operator_followed_by_a_right_parenthesis(infix) ;
		left_parenthesis_followed_by_a_right_parenthesis(infix) ;
		unmatched_parenthesis(infix) ;
		too_long(infix) ;

		if(error==0)
		{
			for(int i = 0 ; i < strlen(infix) ; i ++ )
				infix_back[i] = infix[i] ;

			cout << "The postfix expression:" ;
			infix_to_postfix(infix , postfix) ;
			for(int i = 0 ; i < strlen(postfix) ; i ++)
			{
				if(postfix[i] != 32)
					cout << postfix[i] ;
			}
			cout << endl ;
			//上面四行是純粹轉為postfix	的東西

			infix_minus(infix_back,minus_infix);
			infix_to_postfix(minus_infix , postfix);
			float ans = postfix_to_ans(postfix) ;
			if(ans-(int)ans != 0.0)
				printf("=%.2f\n", ans);
			else
				printf("=%.0f\n", ans);
		}
		else
			error = 0 ;
	}


	return 0 ;
}