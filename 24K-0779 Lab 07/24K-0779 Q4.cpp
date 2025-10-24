#include <iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    node(int val) {
        data = val;
        next = NULL;
    }
};

class linkedlist {
public:
    node* head;
    linkedlist() {
        head = NULL;
    }

    void insert(int val) {
        node* newnode = new node(val);
        if (!head) head = newnode;
        else {
            node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newnode;
        }
    }

    node* gettail(node* cur) {
        while (cur && cur->next) cur = cur->next;
        return cur;
    }

    node* partition(node* start, node* end, node** newhead, node** newend) {
        node* pivot = end;
        node *prev = NULL, *cur = start, *tail = pivot;

        while (cur != pivot) {
            if (cur->data < pivot->data) {
                if (!(*newhead)) *newhead = cur;
                prev = cur;
                cur = cur->next;
            } else {
                if (prev) prev->next = cur->next;
                node* tmp = cur->next;
                cur->next = NULL;
                tail->next = cur;
                tail = cur;
                cur = tmp;
            }
        }

        if (!(*newhead)) *newhead = pivot;
        *newend = tail;
        return pivot;
    }

    node* quicksortrec(node* start, node* end) {
        if (!start || start == end) return start;

        node *newhead = NULL, *newend = NULL;
        node* pivot = partition(start, end, &newhead, &newend);

        if (newhead != pivot) {
            node* temp = newhead;
            while (temp->next != pivot) temp = temp->next;
            temp->next = NULL;

            newhead = quicksortrec(newhead, temp);

            node* tail = gettail(newhead);
            tail->next = pivot;
        }

        pivot->next = quicksortrec(pivot->next, newend);
        return newhead;
    }

    void quicksort() {
        head = quicksortrec(head, gettail(head));
    }

    void display() {
        node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    linkedlist l;
    int arr[] = {10, 7, 8, 9, 1, 5, 3};
    for (int i = 0; i < 7; i++) l.insert(arr[i]);

    cout << "before  ";
    l.display();

    l.quicksort();

    cout << "after sorting: ";
    l.display();

    return 0;
}
