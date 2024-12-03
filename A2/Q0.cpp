#include <iostream>
#include <string>
#include <cstring>
using namespace std;
string to_upper(string str);

int main()
{
    string line;
    while (getline(cin, line))
    {
        cout << to_upper(line) << endl;
    }
    return 0;
}

string to_upper(string str)
{
    string ch;
    string rem;
    string remup;
    if (str[0] == '\0')
    {
        return "";
    }

    ch = toupper(str[0]);
    rem = str.substr(1, str.length());
    remup = to_upper(rem);
    return (ch + remup);
}