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
 cout<<" left child of "<<x<<endl;
 n->l=build();
 cout<<" right child of "<<x<<endl;
 n->r=build();
 return n;
}

bool identical(node* a,node* b){
 if(!a && !b)return true;
 if(!a || !b)return false;
 return (a->d==b->d && identical(a->l,b->l) && identical(a->r,b->r));
}

bool mirror(node* a,node* b){
 if(!a && !b)return true;
 if(!a || !b)return false;
 return (a->d==b->d && mirror(a->l,b->r) && mirror(a->r,b->l));
}

int main(){
 cout<<"build first tree:"<<endl;
 node* t1=build();

 cout<<"build second tree:"<<endl;
 node* t2=build();

 if(identical(t1,t2))
  cout<<" identical"<<endl;
 else
  cout<<" not identical"<<endl;

 if(mirror(t1,t2))
  cout<<" mirror images"<<endl;
 else
  cout<<"not mirror images"<<endl;
}
