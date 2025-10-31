#include <iostream>
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

bool full(node* r){
 if(r==NULL)return true;
 if((r->l==NULL&&r->r==NULL))return true;
 if(r->l&&r->r)return full(r->l)&&full(r->r);
 return false;
}

int main(){
 node* root=build();
 if(full(root))cout<<"tree is full binary tree"<<endl;
 else cout<<"tree is not full binary tree"<<endl;
}
