#pragma once

int error = 0 ;

int illegal_character(char* infix)
{
	int index = 0 ;
	char legal[] = "0123456789+-*/()" ;
	while(infix[index]!='\0')
		if(!strchr(legal,infix[index++]))
		{
			cout << "Illegal character" << endl ;
			error = 1 ;
			return 1 ;
		}
	return 0 ;
}

int illegal_operand(char* infix)
{
	int index = 0 ;
	int not_found = 1 ;
	char legal[] = "+-*/" ;
	while(infix[index]!='\0')
		if(strchr(legal,infix[index++]))
			not_found = 0;
	if(not_found)
	{
		cout << "Illegal Operand" << endl ;
		error = 1 ;
	}
	return not_found ;
}

int first_character_an_operator(char* infix)
{
	char illegal[] = "+-*/" ;
	if(strchr(illegal,infix[0]))
	{
		cout << "First character an operator" << endl ;
		error = 1 ;
		return 1 ;
	}
	return 0 ;
}

int last_character_an_operator(char* infix)
{
	char illegal[] = "+-*/" ;
	if(strchr(illegal,infix[strlen(infix)-1]))
	{
		cout << "Last character an operator" << endl ;
		error = 1 ; 
		return 1 ;
	}
	return 0 ;
}

int right_parenthesis_followed_by_an_identifier(char* infix)
{
	int index = 0 ;
	char illegal[] = "0123456789" ;
	while(infix[index]!='\0')
	{
		if(infix[index] == ')' && infix[index+1]!='\0' && strchr(illegal,infix[index+1]))
		{
			cout << "Right parenthesis followed by an identifier" << endl ;
			error = 1 ;
			return 1 ;
		}
		index ++ ;
	}
	return 0 ;
}

int operator_followed_by_an_operator(char* infix)
{
	int index = 0 ;
	char op[] = "+-*/" ;
	while(infix[index]!='\0')
	{
		if(strchr(op, infix[index]) && infix[index+1]!='\0' && strchr(op , infix[index+1]))
		{
			cout << "Operator followed by an operator" << endl ;
			error = 1 ;
			return 1;
		}
		index ++ ;
	}
	return 0 ;
}

int left_parenthesis_followed_by_an_operator(char* infix)
{
	int index = 0 ;
	char op[] = "+*/" ;
	while(infix[index]!='\0')
	{
		if(infix[index] == '(' && infix[index+1]!='\0' && strchr(op, infix[index+1]))
		{
			cout <<  "Left parenthesis followed by an operator"  << endl ;
			error = 1 ;
			return 1 ;
		}
		else if(infix[index] == '(' && infix[index+1]!='\0' && infix[index++]=='-')
		{
			int count = index ;
			char num[] = "0123456789" ;
			while(infix[count]!=')')
			{
				if(strchr(num,infix[count++]))
				{
					cout <<  "Left parenthesis followed by an operator"  << endl ;
					error = 1 ;
					return 1 ;
				}
			}
		}
		index ++ ;
	}
	return 0 ;
}

int identifier_followed_by_a_left_parenthesis(char* infix)
{
	int index = 0 ;
	char num[] = "0123456789" ;
	while(infix[index]!='\0')
	{
		if(strchr(num , infix[index]) && infix[index+1]!='\0' && infix[index+1] == '(')
		{
			cout << "Identifier followed by a left parenthesis" << endl ;
			error = 1 ;
			return 1 ;
		}
		index ++ ;
	}
	return 0 ;
}

int right_parenthesis_followed_by_a_left_parenthesis(char* infix)
{
	char illegal[] = ")(" ;
	if(strstr(infix,illegal))
	{
		cout << "Right parenthesis followed by a left parenthesis" << endl ;
		error = 1 ;
		return 1 ;
	}
	return 0 ;
}

int operator_followed_by_a_right_parenthesis(char* infix)
{
	int index =  0 ;
	char op[] = "+-*/" ; 
	while(infix[index]!='\0')
	{
		if(strchr(op, infix[index]) && infix[index+1]!='\0' && infix[index+1] == ')')
		{
			cout << "Operator followed by a right parenthesis" << endl ;
			error = 1 ;
			return 1 ;
		}
		index ++ ;
	}
	return 0 ;
}

int left_parenthesis_followed_by_a_right_parenthesis(char* infix)
{
	char illegal[] = "()" ;	if(strstr(infix,illegal))
	{
		cout << "Left parenthesis followed by a right parenthesis" << endl ;
		error = 1 ;
		return 1 ;
	}
	return 0 ;

}

int unmatched_parenthesis(char* infix)
{
	int count = 0 ;
	int index = 0 ;
	while(infix[index]!='\0')
	{
		if(infix[index] == '(')
			count ++ ;
		else if(infix[index] == ')')
			count -- ;
		index ++ ;
	}
	if(count > 0)
	{
		cout << "Unmatched left parenthesis" << endl ;
		error = 1 ;
		return 1 ;
	}
	else if(count < 0 )
	{
		cout << "Unmatched right parenthesis" << endl ;
		error = 1 ;
		return 1 ;
	}
	return 0 ;
}

int too_long(char* infix)
{
	if(strlen(infix)>20)
	{
		cout << "Error - line contains more characters than allowed." << endl ;
		error = 1 ;
		return 1 ;
	}
	return 0 ;
}