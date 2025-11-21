#include <iostream>
using namespace std;

class employeehashtable {
private:
    string table[50];
    bool occup[50];

    int hash1(string s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
            sum += s[i];
        return sum % 50;
    }

    int hash2(string s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
            sum += s[i];
        return 7 - (sum % 7);
    }

public:
    employeehashtable() {
        for (int i = 0; i < 50; i++)
            occup[i] = false;
    }

    void addemploye(string name) {
        int h1 = hash1(name);
        int h2 = hash2(name);

        for (int i = 0; i < 50; i++) {
            int k = (h1 + i * h2) % 50;
            if (!occup[k]) {
                table[k] = name;
                occup[k] = true;
                return;
            }
        }
        cout << "hash table is full" << endl;
    }

    void search_employee(string name) {
        int h1 = hash1(name);
        int h2 = hash2(name);

        for (int i = 0; i < 50; i++) {
            int k = (h1 + i * h2) % 50;
            if (!occup[k])
                break;
            if (table[k] == name) {
                cout << name << " found at index " << k << endl;
                return;
            }
        }
        cout << "employee not found in the directory" << endl;
    }

    void display_table() {
        cout << "hash table:" << endl;
        for (int i = 0; i < 50; i++) {
            if (occup[i])
                cout << i << " -> " << table[i] << endl;
        }
    }
};

int main() {
    employeehashtable eht;

    eht.addemploye("zainab");
    eht.addemploye("ali");
    eht.addemploye("ahmed");
    eht.addemploye("sara");

    eht.display_table();

    cout << endl;
    eht.search_employee("ahmed");
    eht.search_employee("maria");
}
