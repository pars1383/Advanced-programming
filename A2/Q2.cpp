#include <iostream>
#include <string>
using namespace std;
int fact(int n);

int main()
{
    int n = 0;
    int m = 0;
    cin >> n;

    m = (fact(2 * n)) / (fact(n) * fact(n + 1));

    cout << m << endl;
}

int fact(int n)
{
    if (n == 1)
    {
        return 1;
    }

    return n * fact(n - 1);
}