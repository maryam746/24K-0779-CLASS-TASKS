#include <iostream>
using namespace std;

class DA
{
private:
    int *arr;
    int size;
    int capacity;

public:
    DA()
    {
        capacity = 5;
        size = 0;
        arr = new int[capacity];
        for (int i = 0; i < capacity; ++i)
            arr[i] = 0;
    }

    void push_back(int val)
    {
        if (size == capacity)
        {
            int new_capacity = capacity * 2;
            int *new_arr = new int[new_capacity];

            for (int i = 0; i < size; i++)
                new_arr[i] = arr[i];

            delete[] arr;
            arr = new_arr;
            capacity = new_capacity;
        }

        arr[size] = val;
        size++;
    }

    void print()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    ~DA()
    {
        delete[] arr;
    }
};

int main()
{
    DA obj;
    obj.push_back(10);
   
    obj.print();
}
