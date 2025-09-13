#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int d) {
        data = d;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
public:
    LinkedList() { head = nullptr; }

    void add(int d) {
        Node* n = new Node(d);
        if (!head) { head = n; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = n;
    }

    void show() {
        Node* temp = head;
        cout << "List: ";
        while (temp) { cout << temp->data << " -> "; temp = temp->next; }
        cout << "NULL\n";
    }

    void sortlist() {
        if (!head || !head->next) return;
        for (Node* i = head; i->next; i = i->next) {
            for (Node* j = i->next; j; j = j->next) {
                if (i->data > j->data) swap(i->data, j->data);
            }
        }
    }

    void concat(LinkedList& l2) {
        if (!head) { head = l2.head; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = l2.head;
    }

    void middle() {
        if (!head) { cout << "List empty\n"; return; }
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element: " << slow->data << endl;
    }

    void removedups() {
        Node* temp = head;
        while (temp) {
            Node* runner = temp;
            while (runner->next) {
                if (runner->next->data == temp->data) {
                    Node* dup = runner->next;
                    runner->next = runner->next->next;
                    delete dup;
                } else runner = runner->next;
            }
            temp = temp->next;
        }
    }

    static LinkedList mergelists(LinkedList& l1, LinkedList& l2) {
        LinkedList res;
        Node* a = l1.head;
        Node* b = l2.head;
        while (a && b) {
            if (a->data < b->data) { res.add(a->data); a = a->next; }
            else { res.add(b->data); b = b->next; }
        }
        while (a) { res.add(a->data); a = a->next; }
        while (b) { res.add(b->data); b = b->next; }
        return res;
    }
};

int main() {
    LinkedList l1;
    l1.add(4); l1.add(2); l1.add(5); l1.add(2); l1.add(3);

    cout << "Original list:\n";
    l1.show();

    l1.sortlist();
    cout << "Sorted list:"<< endl;
    l1.show();

    l1.middle();

    l1.removedups();
    cout << "\nremoving duplicates:"<< endl;
    l1.show();

    LinkedList l2;
    l2.add(1); l2.add(6); l2.add(3);

    l1.concat(l2);
    cout << "concatenating "<< endl;
    l1.show();

    LinkedList l3 = LinkedList::mergelists(l1, l2);
    cout << "Merged sorted list:"<< endl;
    l3.show();

    return 0;
}
