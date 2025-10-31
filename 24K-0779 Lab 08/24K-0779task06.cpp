#include <iostream>
#include <queue>
using namespace std;

class node{
public:
 int d;
 node *l,*r;
 node(int x){d=x;l=r=NULL;}
};

node* build(){
 int x;
 cout<<"enter value (-1 to stop):"<<endl;
 cin>>x;
 if(x==-1)return NULL;
 node* n=new node(x);
 cout<<"enter left child of "<<x<<endl;
 n->l=build();
 cout<<"enter right child of "<<x<<endl;
 n->r=build();
 return n;
}

void inorder(node* root){
 if(!root)return;
 inorder(root->l);
 cout<<root->d<<" ";
 inorder(root->r);
}

void preorder(node* root){
 if(!root)return;
 cout<<root->d<<" ";
 preorder(root->l);
 preorder(root->r);
}

void postorder(node* root){
 if(!root)return;
 postorder(root->l);
 postorder(root->r);
 cout<<root->d<<" ";
}

void levelorder(node* root){
 if(!root)return;
 queue<node*>q;
 q.push(root);
 while(!q.empty()){
  node* cur=q.front();
  q.pop();
  cout<<cur->d<<" ";
  if(cur->l)q.push(cur->l);
  if(cur->r)q.push(cur->r);
 }
}

int main(){
 node* root=build();
 cout<<"inorder traversal:"<<endl;
 inorder(root);
 cout<<endl;
 cout<<"preorder traversal:"<<endl;
 preorder(root);
 cout<<endl;
 cout<<"postorder traversal:"<<endl;
 postorder(root);
 cout<<endl;
 cout<<"level order traversal:"<<endl;
 levelorder(root);
 cout<<endl;
}
