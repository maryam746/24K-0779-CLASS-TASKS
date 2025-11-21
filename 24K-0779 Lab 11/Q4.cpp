#include <iostream>
using namespace std;

class studenthashtable {
private:
    struct student {
        int roll;
        string name;
    };

    student table[15];
    bool occup[15];

    int hashfunc(int roll) {
        return roll % 15;
    }

public:
    studenthashtable() {
        for (int i = 0; i < 15; i++)
            occup[i] = false;
    }

    void insertrecord(int roll, string name) {
        int index = hashfunc(roll);

        for (int i = 0; i < 15; i++) {
            int k = (index + i * i) % 15;
            if (!occup[k]) {
                table[k].roll = roll;
                table[k].name = name;
                occup[k] = true;
                return;
            }
        }
        cout << "hash table is full" << endl;
    }

    void searchrecord(int roll) {
        int index = hashfunc(roll);

        for (int i = 0; i < 15; i++) {
            int k = (index + i * i) % 15;
            if (!occup[k])
                break;
            if (table[k].roll == roll) {
                cout << table[k].name << endl;
                return;
            }
        }
        cout << "record not found" << endl;
    }

    void display() {
        cout << "hash table" << endl;
        for (int i = 0; i < 15; i++) {
            if (occup[i])
                cout << table[i].roll << "-" << table[i].name << " ";
        }
        cout << endl;
    }
};

int main() {
    studenthashtable sht;

    sht.insertrecord(1, "ali");
    sht.insertrecord(16, "ahmed");
    sht.insertrecord(31, "zara");
    sht.display();

    sht.searchrecord(16);
    sht.searchrecord(5);
}
