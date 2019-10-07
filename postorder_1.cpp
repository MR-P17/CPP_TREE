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
void postorder(Node *root)
{
    if(root==NULL)return;
    stack<Node*>st;
    Node *curr=root;
    while(curr!=NULL || !st.empty())
    {
    	if(curr!=NULL)
    	{
    		st.push(curr);
    		curr=curr->left;
    	}
    	else
    	{
    		Node *tmp=st.top(),*tmp1;
    		if(tmp->right==NULL)
    		{
    			cout<<tmp->data<<" ";
    			st.pop();
    		   while(!st.empty() && tmp==st.top()->right)
    			{tmp1=st.top();st.pop();
    			cout<<tmp1->data<<" ";}
    			curr=tmp1->right;
    		}
    		else{
    			curr=tmp1->right;
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

    postorder(root);

	return 0;
}