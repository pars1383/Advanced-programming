#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

using namespace std;

void split_str(std::string const &str, const char delim,
               std::vector<std::string> &out)
{
    // create a stream from the string
    std::stringstream s(str);

    std::string s2;
    while (std::getline(s, s2, delim))
    {
        out.push_back(s2); // store the string in s2
    }
}

int main()
{
    string str;
    int hour = 0;
    int min = 0;
    int x = 0;
    stringstream ss;
    stringstream sss;
    const char delim = ':';
    cin >> str;
    vector<string> out;
    split_str(str, delim, out);

    ss << out[0];
    ss >> x;
    hour = x;
    sss << out[1];
    sss >> x;
    min = x;
    cout << hour << " " << min << endl;
    return 0;
}

 if (course->day1 == "Saturday")
        {
            if (hm_float(course->start_time) <= 7.5)
            {

                if ((course->end_time).hour >= 9)
                {
                    course->saturday[0] = 1;
                    cout << "saturday 7:30 9" << endl;
                }
                else
                {
                    course->saturday[0] = 0;
                }
                if ((course->end_time).hour >= 11)
                {

                    course->saturday[1] = 1;
                }
                else
                {
                    course->saturday[1] = 0;
                }
                if ((course->end_time).hour >= 13)
                {
                    course->saturday[2] = 1;
                }
                else
                {
                    course->saturday[2] = 0;
                }
            }

            if (hm_float(course->start_time) <= 9.5)
            {

                course->saturday[0] = 0;

                if ((course->end_time).hour >= 11)
                {

                    course->saturday[1] = 1;
                }
                else
                {
                    course->saturday[1] = 0;
                }
                if ((course->end_time).hour >= 13)
                {
                    course->saturday[2] = 1;
                }
                else
                {
                    course->saturday[2] = 0;
                }
            }

            if (hm_float(course->start_time) <= 11.5)
            {

                course->saturday[0] = 0;

                course->saturday[1] = 0;

                if ((course->end_time).hour >= 13)
                {
                    course->saturday[2] = 1;
                }
                else
                {
                    course->saturday[2] = 0;
                }
            }
        }

        else if (course->day1 == "Sunday")
        {
            if (hm_float(course->start_time) <= 7.5)
            {
                if ((course->end_time).hour >= 9)
                {
                    course->sunday[0] = 1;
                }
                else
                {
                    course->sunday[0] = 0;
                }
                if ((course->end_time).hour >= 11)
                {

                    course->sunday[1] = 1;
                }
                else
                {
                    course->sunday[1] = 0;
                }
                if ((course->end_time).hour >= 13)
                {
                    course->sunday[2] = 1;
                }
                else
                {
                    course->sunday[2] = 0;
                }
            }

            if (hm_float(course->start_time) <= 9.5)
            {

                course->sunday[0] = 0;

                if ((course->end_time).hour >= 11)
                {

                    course->sunday[1] = 1;
                }
                else
                {
                    course->sunday[1] = 0;
                }
                if ((course->end_time).hour >= 13)
                {
                    course->sunday[2] = 1;
                }
                else
                {
                    course->sunday[2] = 0;
                }
            }

            if (hm_float(course->start_time) <= 11.5)
            {

                course->sunday[0] = 0;

                course->sunday[1] = 0;

                if ((course->end_time).hour >= 13)
                {
                    course->sunday[2] = 1;
                }
                else
                {
                    course->sunday[2] = 0;
                }
            }
        }

        else if (course->day1 == "Monday")
        {
            if (hm_float(course->start_time) <= 7.5)
            {
                if ((course->end_time).hour >= 9)
                {
                    course->monday[0] = 1;
                    cout << "monday 7:30 9" << endl;
                }
                else
                {
                    course->monday[0] = 0;
                }
                if ((course->end_time).hour >= 11)
                {

                    course->monday[1] = 1;
                }
                else
                {
                    course->monday[1] = 0;
                }
                if ((course->end_time).hour >= 13)
                {
                    course->monday[2] = 1;
                }
                else
                {
                    course->monday[2] = 0;
                }
            }

            if (hm_float(course->start_time) <= 9.5)
            {

                course->monday[0] = 0;

                if ((course->end_time).hour >= 11)
                {

                    course->monday[1] = 1;
                }
                else
                {
                    course->monday[1] = 0;
                }
                if ((course->end_time).hour >= 13)
                {
                    course->monday[2] = 1;
                }
                else
                {
                    course->monday[2] = 0;
                }
            }

            if (hm_float(course->start_time) <= 11.5)
            {

                course->monday[0] = 0;

                course->monday[1] = 0;

                if ((course->end_time).hour >= 13)
                {
                    course->monday[2] = 1;
                }
                else
                {
                    course->monday[2] = 0;
                }
            }
        }

        else if (course->day1 == "Tuesday")
        {
            if (hm_float(course->start_time) <= 7.5)
            {
                if ((course->end_time).hour >= 9)
                {
                    course->tuesday[0] = 1;
                }
                else
                {
                    course->tuesday[0] = 0;
                }
                if ((course->end_time).hour >= 11)
                {

                    course->tuesday[1] = 1;
                }
                else
                {
                    course->tuesday[1] = 0;
                }
                if ((course->end_time).hour >= 13)
                {
                    course->tuesday[2] = 1;
                }
                else
                {
                    course->tuesday[2] = 0;
                }
            }

            if (hm_float(course->start_time) <= 9.5)
            {

                course->tuesday[0] = 0;

                if ((course->end_time).hour >= 11)
                {

                    course->tuesday[1] = 1;
                }
                else
                {
                    course->tuesday[1] = 0;
                }
                if ((course->end_time).hour >= 13)
                {
                    course->tuesday[2] = 1;
                }
                else
                {
                    course->tuesday[2] = 0;
                }
            }

            if (hm_float(course->start_time) <= 11.5)
            {

                course->tuesday[0] = 0;

                course->tuesday[1] = 0;

                if ((course->end_time).hour >= 13)
                {
                    course->tuesday[2] = 1;
                }
                else
                {
                    course->tuesday[2] = 0;
                }
            }
        }
        else if (course->day1 == "Wednesday")
        {
            if (hm_float(course->start_time) <= 7.5)
            {
                if ((course->end_time).hour >= 9)
                {
                    course->wednesday[0] = 1;
                }
                else
                {
                    course->wednesday[0] = 0;
                }
                if ((course->end_time).hour >= 11)
                {

                    course->wednesday[1] = 1;
                }
                else
                {
                    course->wednesday[1] = 0;
                }
                if ((course->end_time).hour >= 13)
                {
                    course->wednesday[2] = 1;
                }
                else
                {
                    course->wednesday[2] = 0;
                }
            }

            if (hm_float(course->start_time) <= 9.5)
            {

                course->wednesday[0] = 0;

                if ((course->end_time).hour >= 11)
                {

                    course->wednesday[1] = 1;
                }
                else
                {
                    course->wednesday[1] = 0;
                }
                if ((course->end_time).hour >= 13)
                {
                    course->wednesday[2] = 1;
                }
                else
                {
                    course->wednesday[2] = 0;
                }
            }

            if (hm_float(course->start_time) <= 11.5)
            {

                course->wednesday[0] = 0;

                course->wednesday[1] = 0;

                if ((course->end_time).hour >= 13)
                {
                    course->wednesday[2] = 1;
                }
                else
                {
                    course->wednesday[2] = 0;
                }
            }
        }
