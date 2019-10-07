#include<bits/stdc++.h>
using namespace std;

class Node
{
   public:
   	int data;
   	Node *left;
   	Node *right;
};

Node *newNode(int key)
{
  Node *tmp=new Node();
  tmp->data=key;
  tmp->left=NULL;
  tmp->right=NULL;
  return tmp;
}

void preorder(Node *root)
{
	if(root!=NULL)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}
vector<Node*>getTrees(int in[],int start,int end)
{
	vector<Node *>trees;

	if(start>end)
	{
		trees.push_back(NULL);
		return trees;
	}

	for(int i=start;i<=end;i++)
	{
		vector<Node*> ltree=getTrees(in,start,i-1);
		vector<Node*> rtree=getTrees(in,i+1,end);

		for(int j=0;j<ltree.size();j++)
		{
			for(int k=0;k<rtree.size();k++)
			{
				Node *node=newNode(in[i]);
				node->left=ltree[j];
				node->right=rtree[k];
				trees.push_back(node);
			}
		}
	}
	return trees;
}
int main()
{
    int in[]={4,5,7};
    int n=sizeof(in)/sizeof(in[0]);

    vector<Node *>trees=getTrees(in, 0 ,n-1);

    for(int i=0;i<trees.size();i++)
    {
    	preorder(trees[i]);
    	cout<<endl;
    }

	return 0;
}