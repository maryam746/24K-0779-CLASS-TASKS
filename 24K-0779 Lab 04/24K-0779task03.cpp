#include <iostream>
using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void shellSort(int arr[], int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int j = gap; j < n; j++)
        {
            int temp = arr[j];
            int k = j;
            while (k >= gap && arr[k - gap] > temp)
            {
                arr[k] = arr[k - gap];
                k -= gap;
            }
            arr[k] = temp;
        }
    }
}

int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nOriginal Array: ";
    display(arr, n);

    shellSort(arr, n);

    cout << "Sorted Array (Shell Sort): ";
    display(arr, n);

    return 0;
}
