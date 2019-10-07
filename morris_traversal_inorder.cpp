#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
	int data;
	Node *left;
	Node *right;
};
Node *newnode(int data)
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
           	curr=curr->left;
           }
           else
           {
           	pre->right=NULL;
           	cout<<curr->data<<" ";
           	curr=curr->right;
           }
		}
	}
}
int main()
{
  Node *root=newnode(1);
  root->left=newnode(2);
  root->right=newnode(3);
  root->left->left=newnode(4);
  root->left->right=newnode(5);


  morris_traversal(root);
  return 0;
}