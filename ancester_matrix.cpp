#include<bits/stdc++.h>
using namespace std;
#define n 100

int mat[n][n];
class Node 
{
public:
	int data;
	Node*left;
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
int matrics(Node *root,vector<int>&v)
{
	if(root==NULL)return 0;

	int data=root->data;
	for(int i=0;i<v.size();i++)
		mat[v[i]][data]=1;

	v.push_back(data);

	int l=matrics(root->left,v);
	int r=matrics(root->right,v);
    
    v.pop_back();
	return l+r+1;
}
int main()
{
    Node *root        = newnode(5); 
    root->left        = newnode(1); 
    root->right       = newnode(2); 
    root->left->left  = newnode(0); 
    root->left->right = newnode(4); 
    root->right->left = newnode(3); 
     vector<int>v;
     int len=matrics(root,v);

     for(int i=0;i<len;i++){
     	for(int j=0;j<len;j++)
     		cout<<mat[i][j]<<" ";
     		cout<<endl;   
     	}
	return 0;
}