#include<iostream>
using namespace std;

class Hash {
private:
string table[50];
bool occup[50];

int hashfunc(string s)
{
    int sum =0;
    for(int i=0;i<s.length();i++)
    {
        sum += s[i];
    }
    return sum % 50;
}

public:
Hash(){
    for(int i=0;i<50;i++)
    {
        table[i] = "";
        occup[i] = false;
    }
}


void insert(string s){
    int index = hashfunc(s);


    for( int i =0; i<50 ;i++){
        int k = (index + i) % 50;
        if(!occup[k]){
            table[k] = s;
        occup[k] = true;
            return;

    }

}

cout <<"Hash table is full"<<endl;
    }

     void search(string s) {
        int index = hashfunc(s);

        for (int i = 0; i < 50; i++) {
            int k = (index + i) % 50;

            if (!occup[k])
                break;

            if (table[k] == s) {
                cout << "'" << s << "' FOUND at  " << k << endl;
                return;
            }
        }

        cout << "'" << s << "' NOT FOUND"<<endl;
    }

     void display() {
        cout << "Hash Table "<<endl;
        for (int i = 0; i < 50; i++) {
           
            if (occup[i])
                cout << table[i]<< " ";
           
                
            
        }
    }


    void deleteKey(string s) {
        int index = hashfunc(s);

        for (int i = 0; i < 50; i++) {
            int k= (index + i) % 50;

            if (!occup[k])
                break;

            if (table[k] == s) {
                table[k] = "";
            occup[k] = false;
            cout << "Deleted '" << s << "' from index " << k << endl;
                return;
            }
        }
    }





};


int main(){
Hash h;

h.insert("1");
    h.insert("3");
    h.insert("4");
     h.insert("5");
      h.insert("7");
      h.display();
   

    cout << endl;
    h.search("4");
 
    cout << endl;
   
   
    
    h.display();
}
