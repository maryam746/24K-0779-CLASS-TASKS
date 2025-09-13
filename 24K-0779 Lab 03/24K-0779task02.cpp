#include <iostream>
using namespace std;

class Node
{
public:
    string book;
    Node *next;

    Node(string data)
    {
        this->book = data;
        this->next = nullptr;
    }
};

class Library
{
private:
    Node *head;
    Node *tail;

public:
    Library()
    {
        head = nullptr;
        tail = nullptr;
    }

    void addbooktotail(Node *newnode)
    {
        if (head == nullptr)
        {
            head = newnode;
            tail = newnode;
            return;
        }
        tail->next = newnode;
        tail = newnode;
    }

    void delbookfromfront()
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }
        if (head == tail)
        {
            delete head;
            head = nullptr;
            tail = nullptr;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    void searchbookbytitle(string b)
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            if (temp->book == b)
            {
                cout << "Book found: " << b << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Book not found\n";
    }

    void searchbyposition(int position)
    {
        Node *temp = head;
        int pos = 1;
        while (temp != nullptr)
        {
            if (pos == position)
            {
                cout << "Book at position " << pos << ": " << temp->book << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Invalid position.\n";
    }

    void display()
    {
        Node *temp = head;
        cout << "CATALOG: ";
        while (temp != nullptr)
        {
            cout << temp->book << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    Library library;

    library.addbooktotail(new Node("Data Structures"));
    library.addbooktotail(new Node("Operating Systems"));
    library.addbooktotail(new Node("Computer Networks"));
    library.addbooktotail(new Node("Database Systems"));

    cout << "Initial Catalog:\n";
    library.display();

    library.delbookfromfront();

    library.display();

    library.searchbookbytitle("Database Systems");

    library.searchbyposition(2);

    return 0;
}
