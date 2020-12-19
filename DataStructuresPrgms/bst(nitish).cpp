#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
	int val;
	node * right;
	node * left;
};

node * root=(node*)malloc(sizeof(node));
node * t=(node*)malloc(sizeof(node));

void add_node(node * p,node * t)
{
	if((p->val) <= (t->val))
	{
		if(t->left==NULL)
			t->left=p;
		
		else
			add_node(p,t->left);
		
	}
	
	else
	{
		if((t->right==NULL))
			t->right=p;
		
		else
			add_node(p,t->right);
		
	}
}

void display(node *temp)
{
		if(temp->left!=NULL)
		{
			display(temp->left);
			cout<<temp->left->val<<"\t";
		}
		
		if(temp->right!=NULL)
		{
			display(temp->right);
			cout<<temp->right->val<<"\t";
		}
		
}
int main()
{
	root->right=root->left=NULL;
	t=root;
	int x;
	
	
	cout<<"Enter values to be added to the binary search tree. Enter any character to stop."<<endl;
	cin>>x;
	root->val=x;
	t=root;
	while((cin>>x)&&(x!='d'))
	{
		node * add=(node*)malloc(sizeof(node));
		add->right=add->left=NULL;
		add->val=x;
		add_node(add,t); 
		cout<<"doing.."<<endl;
	}
	
	display(t);
	
	return 0;
}
