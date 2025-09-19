#include <iostream>
using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void insertionSort(int arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int interpolationSearch(int arr[], int n, int x)
{
    int low = 0, high = n - 1;
    while (low <= high && x >= arr[low] && x <= arr[high])
    {
        if (low == high)
        {
            if (arr[low] == x) return low;
            return -1;
        }
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (x - arr[low]);
        if (arr[pos] == x) return pos;
        if (arr[pos] < x) low = pos + 1;
        else high = pos - 1;
    }
    return -1;
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int* arr = new int [n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    insertionSort(arr, n);
    cout << "Sorted Array: ";
    display(arr, n);

    int target;
    cout << "Enter element to search: ";
    cin >> target;

    int index = interpolationSearch(arr, n, target);
    if (index != -1) cout << "Element found at index " << index << endl;
    else cout << "Element not found" << endl;

    return 0;
}
