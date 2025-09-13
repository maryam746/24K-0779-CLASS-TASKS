
#include <iostream>
using namespace std;

class Node {
public:
    string book;
    Node* next;

    Node(string data) {
        this->book = data;
        this->next = nullptr;
    }
};

class Library {
private:
    Node* head;

public:
    Library() {
        head = nullptr;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->book << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void insertatfront(Node* newnode) {
        newnode->next = head;
        head = newnode;
    }

    void insertatend(Node* newnode) {
        if (head == nullptr) {
            head = newnode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newnode;
    }

    void insertatpos(string afterBook, Node* newnode) {
        Node* temp = head;
        while (temp != nullptr && temp->book != afterBook) {
            temp = temp->next;
        }
        if (temp == nullptr) {
            cout << "Book not found\n";
            return;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }

    void searchbook(string b) {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->book == b) {
                cout << "Book: " << temp->book << " found\n";
                return;
            }
            temp = temp->next;
        }
        cout << "Book not found\n";
    }
};

int main() {
    Library library;

    Node* n1 = new Node("Data Structures");
    Node* n2 = new Node("Operating Systems");
    Node* n3 = new Node("Computer Networks");
    Node* n4 = new Node("Database Systems");

    library.insertatend(n1);
    library.insertatend(n2);
    library.insertatend(n3);
    library.insertatend(n4);

    cout << "Initial list:\n";
    library.display();

    Node* n5 = new Node("Artificial Intelligence");
    library.insertatfront(n5);
    cout << "\nAfter inserting at front:\n";
    library.display();

    Node* n6 = new Node("Machine Learning");
    library.insertatend(n6);
    cout << "\nAfter inserting at end:\n";
    library.display();

    Node* n7 = new Node("Cyber Security");
    library.insertatpos("Operating Systems", n7);
    cout << "\nAfter inserting after Operating Systems:\n";
    library.display();

    cout << "\nSearching for Database Systems:\n";
    library.searchbook("Database Systems");

    return 0;
}
