#include <iostream>
using namespace std;

struct Product {
    string name;
    float price;
    string description;
    bool available;
};

int partition(Product arr[], int low, int high) {
    float pivot = arr[high].price;
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j].price <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(Product arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    Product products[3];

    for (int i = 0; i < 3; i++) {
        cout << "Enter details for product " << i + 1 << ":\n";
        cout << "Name: ";
        cin >> ws;
        getline(cin, products[i].name);
        cout << "Price: ";
        cin >> products[i].price;
        cout << "Description: ";
        cin >> ws;
        getline(cin, products[i].description);
        cout << "Available (1 for Yes, 0 for No): ";
        cin >> products[i].available;
        cout << endl;
    }

    quickSort(products, 0, 2);

    cout << "\nProducts sorted by price:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Name: " << products[i].name << endl;
        cout << "Price: " << products[i].price << endl;
        cout << "Description: " << products[i].description << endl;
        cout << "Availability: " << (products[i].available ? "Available" : "Not Available") << endl;
        cout << "---------------------------\n";
    }

    return 0;
}
