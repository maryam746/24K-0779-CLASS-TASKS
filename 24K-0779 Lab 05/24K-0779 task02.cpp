#include <iostream>
using namespace std;

const int n = 7;

bool safe(int m[n][n], int x, int y, int ans[n][n])
{
    return (x >= 0 && x < n && y >= 0 && y < n && m[x][y] == 1 && ans[x][y] == 0);
}

bool path(int m[n][n], int x, int y, int ans[n][n])
{
    if (x == n - 1 && y == n - 1 && m[x][y] == 1)
    {
        ans[x][y] = 1;
        return true;
    }
    if (safe(m, x, y, ans))
    {
        ans[x][y] = 1;
        if (path(m, x + 1, y, ans))
            return true;
        if (path(m, x, y + 1, ans))
            return true;
        if (path(m, x - 1, y, ans))
            return true;
        if (path(m, x, y - 1, ans))
            return true;
        ans[x][y] = 0;
        return false;
    }
    return false;
}

void solve(int m[n][n])
{
    int ans[n][n] = {0};
    if (path(m, 0, 0, ans))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "no path\n";
    }
}

int main()
{
    int m[n][n] = {
        {1, 0, 1, 1, 1, 0, 1},
        {1, 1, 1, 0, 1, 1, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {1, 1, 0, 1, 1, 0, 1},
        {0, 1, 1, 1, 0, 1, 0},
        {1, 0, 0, 1, 1, 1, 1},
        {1, 1, 1, 0, 0, 1, 1}};
    solve(m);
    return 0;
}
