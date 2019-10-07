#include<bits/stdc++.h>
using namespace std;

class Node{
   public:
   int data;
   Node *left;
   Node *right;
};
Node *new_Node(int data)
{
  Node *tmp=new Node();
  tmp->data=data;
  tmp->left=NULL;
  tmp->right=NULL;
  return tmp;
}
void inorder_print(Node *root)
{
  if(root==NULL)
  return;

  inorder_print(root->left);
  cout<<root->data<<" ";
  inorder_print(root->right);
}
void insert(Node *root,int key)
{ 
  queue<Node *> q;
  q.push(root);

  while(!q.empty())
  {
    Node *tmp=q.front();
    q.pop();
   
    if(tmp->left==NULL)
      {
         tmp->left=new_Node(key);
         break;
      }
      else
         q.push(tmp->left);

     if(tmp->right==NULL)
      {
        tmp->right=new_Node(key);
        break;
      }
      else
         q.push(tmp->right);
  }
}
int main()
{
  Node *root=new_Node(10);
  root->left=new_Node(11);
  root->left->left=new_Node(7);
  root->right=new_Node(9);
  root->right->left=new_Node(15);
  root->right->right=new_Node(8);

  inorder_print(root);
  cout<<endl<<endl;

  int key=12;
  insert(root,key);

  inorder_print(root);
  
return 0;
}
