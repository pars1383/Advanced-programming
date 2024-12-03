#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
using namespace std;

int min_max(int x, int y, int flag);

int main()
{
    int n = 0;
    int i = 0;
    int j = 0;
    int x = 0;
    int flag = 0;
    int index = 0;
    int minmax = 0;

    cin >> n;
    int *arr = new int(n);
    for (x = 0; x < n; x++)
    {
        cin >> arr[x];
    }

    while (j < n && x != j)
    {

        if (index == 0)
        {
            minmax = arr[0];
            j += minmax;
            x = 0;
            cout << arr[0] << " ";
        }
        else
        {
            minmax = min_max(arr[x], arr[j] , flag);
            cout << arr[j] << " ";
            x = j;
            j += minmax;
        }

        flag++;
        index = 1;
    }
}



int min_max(int x, int y, int flag)
{

    if (flag % 2 == 0)
    {
        if (x > y)
        {
            return x;
        }
        else
        {
            return y;
        }
    }

    else if (flag % 2 != 0)
    {
        if (x > y)
        {
            return y;
        }
        else
        {
            return x;
        }
    }
}
