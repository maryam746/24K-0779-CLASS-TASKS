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

int count(node* r){
 if(r==NULL)return 0;
 return 1+count(r->l)+count(r->r);
}

int leaf(node* r){
 if(r==NULL)return 0;
 if(r->l==NULL&&r->r==NULL)return 1;
 return leaf(r->l)+leaf(r->r);
}

int height(node* r){
 if(r==NULL)return 0;
 int lh=height(r->l),rh=height(r->r);
 return 1+(lh>rh?lh:rh);
}

int main(){
 node* root=build();
 cout<<"total nodes: "<<count(root)<<endl;
 cout<<"leaf nodes: "<<leaf(root)<<endl;
 cout<<"height of tree: "<<height(root)<<endl;
}
