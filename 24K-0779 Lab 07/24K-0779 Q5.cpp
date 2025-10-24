#include <iostream>
#include <string>
using namespace std;

class employee {
public:
    string name;
    int id;
    int salary;
};

class company {
public:
    employee e[12];
    int size;

    company() {
        size = 12;
    }

    void input() {
        for (int i = 0; i < size; i++) {
            cout << "enter name id salary of employee " << i + 1 << ": ";
            cin >> e[i].name >> e[i].id >> e[i].salary;
        }
    }

    void merge(employee arr[], int st, int mid, int end) {
        int n1 = mid - st + 1;
        int n2 = end - mid;
        employee L[n1], R[n2];

        for (int i = 0; i < n1; i++) L[i] = arr[st + i];
        for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = st;

        while (i < n1 && j < n2) {
            if (L[i].salary >= R[j].salary) {
                arr[k] = L[i];
                i++;
            } else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    void mergesort(employee arr[], int st, int end) {
        if (st < end) {
            int mid = st + (end - st) / 2;
            mergesort(arr, st, mid);
            mergesort(arr, mid + 1, end);
            merge(arr, st, mid, end);
        }
    }

    void sortbysalary() {
        mergesort(e, 0, size - 1);
    }

    void displaytop3() {
        cout << "\ntop 3 highest paid employees:\n";
        for (int i = 0; i < 3 && i < size; i++) {
            cout << e[i].name << " (id: " << e[i].id << ", salary: " << e[i].salary << ")\n";
        }
    }
};

int main() {
    company c;
    c.input();
    c.sortbysalary();
    c.displaytop3();
    return 0;
}
