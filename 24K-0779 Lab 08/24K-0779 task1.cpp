
#include <iostream>
using namespace std;

class node{
public:
 string name;
 node *l,*r;
 node(string n){name=n;l=r=NULL;}
};

node* add(){
 string n;
 cout<<"enter package name (or -1 to stop):"<<endl;
 cin>>n;
 if(n=="-1")return NULL;
 node* root=new node(n);
 cout<<"enter left subpackage of "<<n<<endl;
 root->l=add();
 cout<<"enter right subpackage of "<<n<<endl;
 root->r=add();
 return root;
}

void disp(node* r,int space=0){
 if(r==NULL)return;
 space+=5;
 disp(r->r,space);
 cout<<endl;
 for(int i=5;i<space;i++)cout<<" ";
 cout<<r->name<<endl;
 disp(r->l,space);
}

int main(){
 cout<<"build tour package tree"<<endl;
 node* root=add();
 cout<<"tour package hierarchy:"<<endl;
 disp(root);
}

