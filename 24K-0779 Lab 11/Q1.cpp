#include<iostream>
#include<string>
using namespace std;


class Node {
    public:
    string data;
    Node*next;
    Node(string val) {
        data = val;
        next = NULL;
    }

};


class Chainhash{
    public:
    Node *table[10];

    Chainhash(){
        for(int i=0;i<10;i++){
            table[i]=NULL;
        }
    }

    
    int hashfunc(string key){
        int sum=0;
        for(int i=0;i<key.length();i++){
            sum+=int(key[i]);
        }
        return sum%10;
    }

    void insert(string s){
        int index = hashfunc(s);
        Node*newnode=new Node(s);
        if(table[index]==NULL){
            table[index]= newnode ;
        
        }

        else{
            Node*temp = table[index];
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=newnode;
        }
    }


    bool search(string s){
        int index = hashfunc(s);
        Node*temp=table[index];
        while(temp!=NULL){
            if(temp->data==s){
                return true;
            }
            temp=temp->next;
        }
        return false;
    }

void display(){
      for(int i=0 ; i<10 ;i++){
        cout<<i<<" : ";
        Node*temp=table[i];
        while(temp!=NULL){
            cout<<temp->data<<" -> ";
            temp=temp->next;
        }
        cout<<"NULL"<<endl;
      }
}

 
};


int main() {
    Chainhash h;
    h.insert("apple");
    h.insert("banana");
    h.insert("mango");
    h.insert("apple");

    cout << "Hash Table:\n";
    h.display();

     if (h.search("apple")) cout << "FOUND\n";
    else cout << "NOT FOUND\n";

    return 0;
}
