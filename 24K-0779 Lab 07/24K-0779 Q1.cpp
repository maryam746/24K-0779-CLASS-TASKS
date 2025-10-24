#include <iostream>
#include <string>
using namespace std;

class node {
public:
    string name;
    int score;
    node* next;

    node(string n, int s) {
        name = n;
        score = s;
        next = NULL;
    }
};

class studentlist {
public:
    node* head;

    studentlist() {
        head = NULL;
    }

    void insert(string name, int score) {
        node* newnode = new node(name, score);
        if (!head) head = newnode;
        else {
            node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newnode;
        }
    }

    int getmax() {
        int max = head->score;
        node* temp = head->next;
        while (temp) {
            if (temp->score > max) max = temp->score;
            temp = temp->next;
        }
        return max;
    }

    int getdigit(int num, int place) {
        for (int i = 0; i < place - 1; i++) num /= 10;
        return num % 10;
    }

    void radixsort() {
        int max = getmax();
        for (int place = 1; max / place > 0; place *= 10) {
            node* buckets[10] = {NULL};
            node* tails[10] = {NULL};
            node* temp = head;

            while (temp) {
                int digit = getdigit(temp->score, place);
                node* nextnode = temp->next;
                temp->next = NULL;
                if (!buckets[digit]) buckets[digit] = tails[digit] = temp;
                else {
                    tails[digit]->next = temp;
                    tails[digit] = temp;
                }
                temp = nextnode;
            }

            head = NULL;
            node* tail = NULL;
            for (int i = 0; i < 10; i++) {
                if (buckets[i]) {
                    if (!head) {
                        head = buckets[i];
                        tail = tails[i];
                    } else {
                        tail->next = buckets[i];
                        tail = tails[i];
                    }
                }
            }
        }
    }

    void display() {
        node* temp = head;
        while (temp) {
            cout << temp->name << " - " << temp->score << endl;
            temp = temp->next;
        }
    }
};

int main() {
    studentlist s;
    s.insert("ali", 75);
    s.insert("fatima", 92);
    s.insert("ahmed", 64);
    s.insert("maryam", 85);
    s.insert("usman", 43);

    cout << "before sorting:\n";
    s.display();

    s.radixsort();

    cout << "\nafter sorting:\n";
    s.display();

    return 0;
}
