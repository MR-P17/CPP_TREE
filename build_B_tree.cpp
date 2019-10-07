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
int search(int data,int arr[],int start,int end)
{
	for(int i=start;i<=end;i++)
	{
		if(arr[i]==data)
			return i;
	}
	return -1;
}
Node *build_tree(int pre[],int pre_m[],int start,int end,int n)
{
	static int idx=0;
	if(start>end || idx>=n)return NULL;

	Node *root=new_node(pre[idx++]);

	if(start==end)return root;

	int i=search(pre[idx],pre_m,start,end);

	if(i<=end)
	{
		root->left=build_tree(pre,pre_m,i,end,n);
		root->right=build_tree(pre,pre_m,start+1,i-1,n);
	}
	return root;
}
void inorder(Node *root)
{
	if(root==NULL)return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
int main()
{
    int pre[]={0, 1, 3, 4, 2, 5, 6};
    int pre_m[]={0, 2, 6, 5, 1, 4, 3};

    int n=sizeof(pre)/sizeof(pre[0]);

    Node *root=build_tree(pre,pre_m,0,n-1,n);

    inorder(root);

	return 0;
}