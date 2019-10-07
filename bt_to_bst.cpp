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
void give_inorder(Node *root,vector<int> &v)
{
	if(root==NULL)return;

	give_inorder(root->left,v);

	v.push_back(root->data);

	give_inorder(root->right,v);
}
int search(int data,vector<int>v)
{
	for(int i=0;i<v.size();i++)
		if(v[i]==data)
			return i;
}
void change_val(Node *root,vector<int> v,vector<int> v1)
{
	if(root==NULL)return;

	int i=search(root->data,v);
	root->data=v1[i];

	change_val(root->left,v,v1);
	change_val(root->right,v,v1);
}
void binaryTreeToBst(Node *root)
{
	vector<int>v,v1;
	give_inorder(root,v);
  	v1=v;
  	sort(v1.begin(),v1.end());

  	change_val(root,v,v1);

}
void preorder(Node *root)
{
	if(root==NULL)return;

	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}
int main()
{
    Node *root=new_node(10);
    root->left = new_node(30); 
    root->right = new_node(15); 
    root->left->left = new_node(20); 
    root->right->right = new_node(5); 

    binaryTreeToBst(root);

    preorder(root);

	return 0;
}