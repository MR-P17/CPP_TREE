#include<bits/stdc++.h>
using namespace std;

class Node
{
   public:
     int data;
     Node *left;
     Node *right;
};

Node * new_node(int data)
{
	Node *tmp=new Node();
	tmp->data=data;
	tmp->left=NULL;
	tmp->right=NULL;
	return tmp;
}

bool reverse_path(Node *root,vector<Node *>&v,int &flag,int data)
{
	if(root==NULL)return false;

    if(root->data==data && flag==0)
    {
    	v.push_back(root);
    	flag=1;
    	return true;
    }
    if(flag==0)
    {
    	bool l=reverse_path(root->left,v,flag,data);
    	if(l==true)v.push_back(root);
        
        else if(l==false)
        {
        	bool r=reverse_path(root->right,v,flag,data);
        	if(r==true)v.push_back(root);
        }
    }
}
void rotate_vector(vector<Node *> &v)
{
	int n=v.size();
	for(int i=0;i<n/2;i++)
	{
		int tmp=v[i]->data;
		v[i]->data=v[n-1-i]->data;
		v[n-1-i]->data=tmp;
	}
}
void inorder_print(Node *root)
{
	if(root==NULL)return;
	inorder_print(root->left);
	cout<<root->data<<" ";
    inorder_print(root->right);
}
int main()
{
	Node* root=new_node(7);
	root->left=new_node(6);
	root->left->left=new_node(4);
	root->left->right=new_node(3);
	root->right=new_node(5);
	root->right->left=new_node(2);
	root->right->right=new_node(1);

	inorder_print(root);
	cout<<endl;

	vector<Node *>v;
	int flag=0;
	bool a=reverse_path(root,v,flag,4);

	rotate_vector(v);

	for(int i=0; i<v.size();i++)
	{
		cout<<v[i]->data<<" ";
	}
	cout<<endl;

	inorder_print(root);


	return 0;
}