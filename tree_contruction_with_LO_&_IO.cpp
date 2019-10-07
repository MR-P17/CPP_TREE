#include<bits/stdc++.h>
using namespace std;

class node
{
public:
	int data;
	int low;
	int high;
	node *left;
	node *right;
};

node *new_node(int x,int low,int high)
{
	node *tmp=new node();
	tmp->data=x;
	tmp->low=low;
	tmp->high=high;
	tmp->left=NULL;
	tmp->right=NULL;

	return tmp;
}

int search(int arr[],int x,int low,int high)
{
	for(int i=low;i<=high;i++)
	{
		if(arr[i]==x)
			return i;
	}
}

void print_tree(node *root)
{
	if(root==NULL)return;

	
	print_tree(root->left);
	cout<<root->data<<" ";
	print_tree(root->right);
}

int main()
{
	int in[]={4,8,10,12,14,20,22};
	int level[]={20,8,22,4,12,10,14};
	int n=sizeof(in)/sizeof(in[0]);

	node *root=NULL,*tmp;
	int low=0,high=n-1,l_idx=0,h=n-1;

	queue<node*>q;
	root=new_node(level[l_idx],low,high);

	//cout<<root->data<<endl;

	q.push(root);

	while(!q.empty())
	{
		
		tmp=q.front();
		q.pop();
		low=tmp->low;
		high=tmp->high;
		int idx=search(in,tmp->data,low,high);

		if(idx-1>=low)
		{
			l_idx++;
			tmp->left=new_node(level[l_idx],low,idx-1);
			q.push(tmp->left);

			//cout<<tmp->left->data<<endl;
		}
		if(idx+1<=high)
		{
			l_idx++;
			tmp->right=new_node(level[l_idx],idx+1,high);
			q.push(tmp->right);

			//cout<<tmp->right->data<<endl;
		}
	}

	print_tree(root);

	return 0;
}