#include <iostream>
using namespace std;

class Node{

    public:
    string word;
    Node* next;
    Node(string w){
        word=w;
        next=NULL;
    }

  

};
  

class asciidict{
   private:
    Node *table[100];
    

    int hashfunc(string key){
        int sum =0;
        for(int i=0;i<key.length();i++){
            sum+=int(key[i]);
        }
        return sum%100;
    }


    public:
      asciidict(){
        for(int i=0;i<100;i++)
            table[i]=NULL;
        }

    void addrecord(string w){

        int index = hashfunc(w);
        Node * n = new Node(w);


        if(table[index] == NULL){
            table[index] = n;
        }
        else{
            Node* temp = table[index];
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = n;
        }
    }

    void wordsearch(string w){
        int index =hashfunc(w);
        Node * temp = table[index];

        while(temp != NULL){
            if(temp->word == w){
                cout << "Word found "<<endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Word not found "<<endl;
    }

    void display(){
        for (int i = 0; i < 100; i++) {
            cout << i << ": ";
            Node* temp = table[i];

            if (temp == NULL) {
                cout << "NULL"<<endl;
                continue;
            }

            while (temp != NULL) {
                cout << temp->word << " -> ";
                temp = temp->next;
            }
            cout << "NULL"<<endl;
        }
    }
};

int main(){

     asciidict dict;

    
    dict.addrecord("hello");
    dict.addrecord("banana");
    dict.addrecord("apple");
    dict.addrecord("cat");
    dict.addrecord("dog");

    cout << endl;
    dict.wordsearch("banana");
    dict.wordsearch("xyz");

    cout << endl;
    dict.display();

}
