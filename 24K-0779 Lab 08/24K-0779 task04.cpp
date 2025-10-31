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

bool complete(node* r){
 if(!r)return true;
 queue<node*>q;
 q.push(r);
 bool f=false;
 while(!q.empty()){
  node* c=q.front();
  q.pop();
  if(c){
   if(f)return false;
   q.push(c->l);
   q.push(c->r);
  }else f=true;
 }
 return true;
}

int sum(node* r){
 if(!r)return 0;
 return r->d+sum(r->l)+sum(r->r);
}

int main(){
 node* root=build();
 if(complete(root))cout<<"tree is complete"<<endl;
 else cout<<"tree is not complete"<<endl;
 cout<<"sum of all nodes:"<<sum(root)<<endl;
}

