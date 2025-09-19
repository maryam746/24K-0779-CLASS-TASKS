#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

void bubblesort(int arr[], int n)
{
    int comp = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
        {
            comp++;
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
        }
    cout << "Bubble Sort Comparisons: " << comp << endl;
}

void insertionsort(int arr[], int n)
{
    int comp = 0;
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0)
        {
            comp++;
            if (arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            else
                break;
        }
        arr[j + 1] = key;
    }
    cout << "Insertion Sort Comparisons: " << comp << endl;
}

void selectionsort(int arr[], int n)
{
    int comp = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < n; j++)
        {
            comp++;
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        swap(arr[i], arr[min_index]);
    }
    cout << "Selection Sort Comparisons: " << comp << endl;
}

void shellsort(int arr[], int n)
{
    int comp = 0;
    for (int gap = n / 2; gap > 0; gap /= 2)
        for (int j = gap; j < n; j++)
        {
            int temp = arr[j];
            int res = j;
            while (res >= gap)
            {
                comp++;
                if (arr[res - gap] > temp)
                {
                    arr[res] = arr[res - gap];
                    res -= gap;
                }
                else
                    break;
            }
            arr[res] = temp;
        }
    cout << "Shell Sort Comparisons: " << comp << endl;
}

int main()
{
    srand(time(0));
    int n = 20;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100 + 1;
    cout << "Original Array (size " << n << "):" << endl;
    display(arr, n);

    int *b = new int[n];
    int *c = new int[n];
    int *d = new int[n];
    int *e = new int[n];
    for (int i = 0; i < n; i++)
        b[i] = c[i] = d[i] = e[i] = arr[i];

    bubblesort(b, n);
    display(b, n);
    insertionsort(c, n);
    display(c, n);
    selectionsort(d, n);
    display(d, n);
    shellsort(e, n);
    display(e, n);

    delete[] b;
    delete[] c;
    delete[] d;
    delete[] e;
    delete[] arr;

    n = 100;
    arr = new int[n];
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100 + 1;
    cout << "\nOriginal Array (size " << n << "):" << endl;
    display(arr, n);

    b = new int[n];
    c = new int[n];
    d = new int[n];
    e = new int[n];
    for (int i = 0; i < n; i++)
        b[i] = c[i] = d[i] = e[i] = arr[i];

    bubblesort(b, n);
    insertionsort(c, n);
    selectionsort(d, n);
    shellsort(e, n);

    delete[] arr;
    delete[] b;
    delete[] c;
    delete[] d;
    delete[] e;
    return 0;
}
