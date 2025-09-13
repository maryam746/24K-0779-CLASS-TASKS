#include <iostream>
using namespace std;

class Compartment {
public:
    int num;
    Compartment* next;
    Compartment* prev;

    Compartment(int n) {
        num = n;
        next = nullptr;
        prev = nullptr;
    }
};

class Train {
private:
    Compartment* head;
    Compartment* tail;

public:
    Train() {
        head = nullptr;
        tail = nullptr;
    }

    void addtail(int n) {
        Compartment* newc = new Compartment(n);
        if (!head) {
            head = tail = newc;
            return;
        }
        tail->next = newc;
        newc->prev = tail;
        tail = newc;
    }

    void removefront() {
        if (!head) {
            cout << "Train empty\n";
            return;
        }
        Compartment* temp = head;
        if (head == tail) head = tail = nullptr;
        else {
            head = head->next;
            head->prev = nullptr;
        }
        cout << "Removed: " << temp->num << endl;
        delete temp;
    }

    void search(int n) {
        Compartment* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->num == n) {
                cout << n << " at pos " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << n << " not found\n";
    }

    void show() {
        Compartment* temp = head;
        cout << "Train: ";
        while (temp) {
            cout << temp->num << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    Train t;
    t.addtail(101);
    t.addtail(102);
    t.addtail(103);
    t.addtail(104);

    t.show();
    t.removefront();
    t.show();
    t.search(103);
    t.search(105);

    return 0;
}
