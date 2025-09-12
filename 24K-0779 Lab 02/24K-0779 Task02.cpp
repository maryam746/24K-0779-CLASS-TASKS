#include <iostream>
using namespace std;

class Dynamic2D
{
private:
    int **arr;
    int rows;
    int cols;

public:
    Dynamic2D(int r, int c)
    {
        rows = r;
        cols = c;
        arr = new int *[rows];
        for (int i = 0; i < rows; i++)
        {
            arr[i] = new int[cols];
            for (int j = 0; j < cols; j++)
                arr[i][j] = 0;
        }
    }

    void resize(int newRows, int newCols, int fillVal = 0)
    {
        int **newArr = new int *[newRows];
        for (int i = 0; i < newRows; i++)
        {
            newArr[i] = new int[newCols];
            for (int j = 0; j < newCols; j++)
            {
                if (i < rows && j < cols)
                    newArr[i][j] = arr[i][j];
                else
                    newArr[i][j] = fillVal;
            }
        }

        for (int i = 0; i < rows; i++)
            delete[] arr[i];
        delete[] arr;

        arr = newArr;
        rows = newRows;
        cols = newCols;
    }

    void transpose()
    {
        int **transposed = new int *[cols];
        for (int i = 0; i < cols; i++)
        {
            transposed[i] = new int[rows];
            for (int j = 0; j < rows; j++)
            {
                transposed[i][j] = arr[j][i];
            }
        }

        for (int i = 0; i < rows; i++)
            delete[] arr[i];
        delete[] arr;

        arr = transposed;

        int temp = rows;
        rows = cols;
        cols = temp;
    }

    void print()
    {
        int index = 0;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                int val = arr[i][j];
                if (index % 2 == 1)
                    val += 2;

                cout << val << " ";
                index++;
            }
            cout << endl;
        }
    }

    ~Dynamic2D()
    {
        for (int i = 0; i < rows; i++)
            delete[] arr[i];
        delete[] arr;
    }
};

int main()
{
    Dynamic2D mat(2, 2);

    cout << "Original matrix:" << endl;
    mat.print();

    mat.resize(3, 3, 7);
    cout << "\nResized matrix:" << endl;
    mat.print();

    mat.transpose();
    cout << "\nTransposed matrix:" << endl;
    mat.print();

    return 0;
}
