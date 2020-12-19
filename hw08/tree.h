
#pragma once

#include <stdio.h>
#include <iostream>

using namespace std ;


class BST ;
class tree_node
{
private:
	tree_node *lchild ;
	tree_node *rchild ;
	tree_node *parent ;
	int key ;
public:
	int price ;
	int amount ;
	tree_node():lchild(0),rchild(0),parent(0),key(0),price(0),amount(0){};
	tree_node(int a ,int b , int c):lchild(0),rchild(0),parent(0),key(a),price(b),amount(c){};	
	int get_key(){return key;}
	int get_price(){return price;}
	int get_amount(){return amount;}

	friend class BST ;//BST可以存取這邊的東西
}  ;

class BST
{
private:
	tree_node *root;
	tree_node* leftmost(tree_node *current);
public:
	BST():root(0){};
	tree_node* search(int key_) ;
	tree_node* successor(tree_node *current);
	void insert_bst(int key_ , int price , int amount) ;
	void inorder_print() ;
	void level_order() ;
	void list_all() ;
	void delete_bst(int key_);
};

tree_node* BST::search(int key_)
{
	tree_node *now = root ;
	while(now != NULL && key_!= now->key)
	{
		if(key_ < now->key)//現在這一個位置比要找的東西大
			now = now->lchild ;
		else
			now = now->rchild ;
	}
	return now ;
}

void BST::insert_bst(int key_ , int price , int amount)
{
	tree_node *temp = root ;
	tree_node *last = 0 ;
	tree_node *new_node = new tree_node(key_,price,amount) ;
	while(temp!=NULL)
	{
		last = temp ;
		if( new_node->key < temp->key )
			temp = temp->lchild ;
		else
			temp = temp->rchild ;
	}
	new_node->parent = last ;
	if( last == NULL)
		this->root = new_node ;
	else if( new_node->key < last->key)
		last->lchild = new_node ;
	else
		last->rchild = new_node ;
}

tree_node* BST::successor(tree_node* now)
{
	if(now->rchild != NULL)
	{
		now = now->rchild ;
		while(now->lchild != NULL)
			now = now->lchild ;
		return now ;
	}
	tree_node *next = now->parent ;
	while(next != NULL && now == next->rchild)
	{
		now = next ;
		next = next->parent ;
	}
	return next ;
}

void print_data(tree_node* a)
{
	printf("product number: %03d\n", a->get_key()   );
	printf("price: %d\n"           , a->get_price() );
	printf("amount: %d\n"          , a->get_amount());
	return ;
}

//NOT YET
void BST::delete_bst(int key_)
{
	tree_node *del = search(key_) ;
	if(del == NULL)
	{
		cout << "The product you want to delete is not exists in database." << endl ;
		return ;
	}
	else
	{
		tree_node *a = 0 ;
		tree_node *b = 0 ;
		if(del->lchild == NULL || del->rchild == NULL)
			a = del ;
		else
			a = successor(del) ;
		if( a->lchild != NULL )
			b = a->lchild ;
		else
			b = a->rchild ;
		if( b != NULL)
			b->parent = a->parent ;
		if( a->parent == NULL )
			this->root = b ;
		else if(a == a->parent->lchild)
			a->parent->lchild = b ;
		else 
			a->parent->rchild = b ;
		if( a != del )
		{
			del->key    = a->key ;
			del->price  = a->price ;
			del->amount = a->amount ;
		}

		delete a ;
		a = 0 ;

	}






}

void BST::list_all(void)
{
	tree_node *now = root ;
	while(now->lchild != NULL)
		now = now->lchild ;
	while(now != NULL)
	{
		printf("%03d %d %d\n", now->get_key() , now->get_price() , now->get_amount());
		now = successor(now) ;
	}
}
