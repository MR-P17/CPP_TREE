#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left;
	Node *right;
};
Node *new_node(int data)
{
	Node *tmp=new Node();
	tmp->data=data;
	tmp->left=NULL;
	tmp->right=NULL;
	return tmp;
}
void morris_traversal(Node *root)
{
	Node *pre,*curr;
	if(root==NULL)return;

	curr=root;
	while(curr!=NULL)
	{
		if(curr->left==NULL)
		{
			cout<<curr->data<<" ";
			curr=curr->right;
		}
		else
		{
			pre=curr->left;
			while(pre->right!=NULL && pre->right!=curr)
				pre=pre->right;

			if(pre->right==NULL)
			{
			  pre->right=curr;	
			  cout<<curr->data<<" ";
			  curr=curr->left;
			  	
			}
			else
			{
				pre->right=NULL;
				curr=curr->right;
			}
		}
	}
}
int main()
{
   Node *root=new_node(1);
   root->left=new_node(2);
   root->right=new_node(3);
   root->left->left=new_node(4);
   root->left->right=new_node(5);
   root->right->left=new_node(6);
   root->right->right=new_node(7);
   root->left->left->left=new_node(8);
   root->left->left->right=new_node(9);
   root->left->right->left=new_node(10);
   root->left->right->right=new_node(11);

   morris_traversal(root);

   return 0;
}