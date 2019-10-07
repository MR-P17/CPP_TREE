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

void iterative_pre(Node *root)
{
	stack<Node *>st;
	st.push(root);
	while(!st.empty())
	{
		Node*tmp=st.top();
		st.pop();
		cout<<tmp->data<<" ";
		if(tmp->right!=NULL)st.push(tmp->right);
		if(tmp->left!=NULL)st.push(tmp->left);
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


	iterative_pre(root);


	return 0;
}