#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
using namespace std;
string find_date(string str);
void best_day();
string summery(string input);
void show_longest();

typedef struct diary
{
    string date;
    string notes;
    int counter = 0;

} diary;

vector<diary> my_diary;

int main()
{

    diary temp;
    string temp2 = "";
    string line;
    string result;
    int flag = 0;
    int i = 0;
    int j = 0;
    while (true)
    {

        getline(cin, line);

        if (line.find("start_day") == 0)
        {

            if (flag == 1)
            {
                my_diary.push_back(temp);

                flag = 0;
            }
            temp = {};

            result = find_date(line);
            temp.date = result;
        }
        else if (line.find("show_day") == 0)
        {

            if (flag == 1)
            {
                my_diary.push_back(temp);
                temp = {};
                flag = 0;
            }
            result = find_date(line);
            for (i = 0; i < my_diary.size(); i++)
            {
                if (my_diary[i].date == result)
                {
                    cout << my_diary[i].notes;
                }
            }
        }
        else if (line.find("show_the_longest_day") == 0)
        {
            if (flag == 1)
            {
                my_diary.push_back(temp);

                flag = 0;
            }
            temp = {};
            show_longest();
        }
        else if (line.find("show_the_best_day") == 0)
        {
            if (flag == 1)
            {
                my_diary.push_back(temp);

                flag = 0;
            }
            temp = {};
            best_day();
        }

        else
        {
            temp.notes += line;
            temp.notes += '\n';
            flag = 1;
        }
    }
}

string find_date(string str)
{
    int i = 0;
    int flag = 0;
    int j = 0;
    string out;
    for (i = 0; i < str.size(); i++)
    {
        if (flag == 1)
        {
            out += str[i];
        }

        if (str[i] == ' ')
        {
            flag = 1;
        }
    }
    return out;
}

void best_day()
{
    int i = 0;
    int best = 0;
    int index = 0;
    int x = 0;
    int j = 0;
    string temp;
    string positive;
    ifstream myfile("positive-words.txt");

    while (getline(myfile, positive))
    {

        for (i = 0; i < my_diary.size(); i++)
        {
            temp = my_diary[i].notes;
            for (j = 0; j < temp.length(); j++)
            {
                temp[j] = tolower(temp[j]);
            }

            if (temp.find(positive) != string::npos)
            {
                my_diary[i].counter++;
            }
        }
    }

    for (i = 0; i < my_diary.size(); i++)
    {

        if (my_diary[i].counter > best)
        {
            best = my_diary[i].counter;
            index = i;
        }
    }

    cout << my_diary[index].date << endl;
    cout << summery(my_diary[index].notes) << endl;

    myfile.close();
}

string summery(string input)
{
    int j = 0;
    string output = "";

    if (input.length() > 20)
    {

        output = input.substr(0, 20);
        output += "...";
    }
    else
    {
        output = input;
    }
    return output;
}

void show_longest()
{
    int j = 0;
    int size = 0;
    int longest = 0;
    int index = 0;
    for (j = 0; j < my_diary.size(); j++)
    {
        size = (my_diary[j].notes).size();
        if (size > longest)
        {
            longest = size;
            index = j;
        }
    }
    cout << my_diary[index].date << endl;
    cout << summery(my_diary[index].notes) << endl;
}
