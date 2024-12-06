#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef struct hm
{
    int hour;
    int min;
} hm;

typedef struct day_hm
{
    int hm;
    int day;
    int day2;
    int hm2;
} day_hm;

typedef struct table
{
    string course_name;
    string teacher;
    int day;
    int hm;
    int day2;
    int hm2;

    struct table *next;
} table;

typedef struct teachers
{
    string teacher_name;
    int num_freedays;
    vector<string> free_day;
    int num_courses;
    vector<string> courses;
    int weekday[5][3];
    int num_freetimes;
    struct teachers *next;
} teachers;

typedef struct lesson_order
{
    string name;
    string day1;
    string day2;
    hm start_time;
    hm end_time;
    int weekday[5][3];

    struct lesson_order *next;

} lesson_order;

void tokenize(string const &str, const char delim, vector<string> &out);
teachers *teacher_construct(vector<string> str);
lesson_order *courses_construct(vector<string> str);
hm time_hm(string str);
void split_str(std::string const &str, const char delim,
               std::vector<std::string> &out);
float hm_float(hm t);
void course_schedule(lesson_order *course);
void checking_block(lesson_order *course, string weekday);
int weekday_arr_filler(string weekday);
void checking_teacher_block(teachers *teach);
table *plan_maker(lesson_order *course, teachers *teach);
day_hm map_course_teacher(lesson_order *lesson, teachers *teach);
teachers *find_teacher(teachers *teach, day_hm dh);
string decode_hm(int hm);
bool teacher_found(teachers *teach, day_hm dh);

int main()
{
    int n = 0;
    int k = 0;
    int i = 0;
    int j = 0;
    string line = "";
    const char delim = ' ';
    vector<string> out;
    teachers *T;
    lesson_order *L;
    teachers *teach_list = NULL;
    teachers *temp_list = NULL;
    teachers *last = NULL;
    lesson_order *course_list = NULL;
    lesson_order *temp_course = NULL;
    lesson_order *last_course = NULL;
    table *table_list1 = NULL;
    table *table_list2 = NULL;

    cin >> n;
    cin >> ws;
    for (i = 0; i < n; i++)
    {

        getline(cin, line);
        out.clear();
        tokenize(line, delim, out);

        T = teacher_construct(out);
        if (i == 0)
        {
            teach_list = T;
        }
        else
        {

            temp_list = teach_list;
            last = teach_list;
            while (temp_list != NULL)
            {
                last = temp_list;
                temp_list = temp_list->next;
            }

            last->next = T;
        }
    }

    temp_list = teach_list;

    while (temp_list != NULL)
    {
        checking_teacher_block(temp_list);

        temp_list = temp_list->next;
    }

    /* temp_list = teach_list;
     while (temp_list != NULL)
     {
         cout << temp_list->teacher_name << " " << temp_list->num_freedays << " ";
         for (j = 0; j < temp_list->free_day.size(); j++)
         {
             cout << temp_list->free_day[j] << " ";
         }
         cout << temp_list->num_courses << " ";
         for (j = 0; j < temp_list->courses.size(); j++)
         {
             cout << temp_list->courses[j] << " ";
         }
         cout << endl;

         for (i = 0; i < 3; i++)
         {
             if (i == 0)
             {
                 cout << "7:30 - 9 " << endl;
             }

             if (i == 1)
             {
                 cout << "9:30 - 11 " << endl;
             }
             if (i == 2)
             {
                 cout << "11:30 - 13 " << endl;
             }

             cout << "saturday"
                  << " " << temp_list->weekday[0][i] << endl;
             cout << "sunday"
                  << " " << temp_list->weekday[1][i] << endl;
             cout << "monday"
                  << " " << temp_list->weekday[2][i] << endl;
             cout << "tuesday"
                  << " " << temp_list->weekday[3][i] << endl;
             cout << "wednesday"
                  << " " << temp_list->weekday[4][i] << endl;
         }

         temp_list = temp_list->next;
     }*/

    out.clear();
    cin >> k;
    cin >> ws;

    for (i = 0; i < k; i++)
    {
        getline(cin, line);
        out.clear();
        tokenize(line, delim, out);
        L = courses_construct(out);

        if (i == 0)
        {
            course_list = L;
        }
        else
        {
            temp_course = course_list;
            last_course = course_list;
            while (temp_course != NULL)
            {
                last_course = temp_course;
                temp_course = temp_course->next;
            }

            last_course->next = L;
        }
    }

    temp_course = course_list;
    course_schedule(temp_course);

    /* temp_course = course_list;
      while (temp_course != NULL)
      {
          cout << temp_course->name << endl;
            << " " << temp_course->day1 << " ";
       cout << temp_course->day2 << " " << (temp_course->start_time).hour << ":" << (temp_course->start_time).min;
       cout << (temp_course->end_time).hour << ":" << (temp_course->end_time).min << endl;

          for (i = 0; i < 3; i++)
          {
              if (i == 0)
              {
                  cout << "7:30 - 9 " << endl;
              }

              if (i == 1)
              {
                  cout << "9:30 - 11 " << endl;
              }
              if (i == 2)
              {
                  cout << "11:30 - 13 " << endl;
              }

              cout << "saturday"
                   << " " << temp_course->weekday[0][i] << endl;
              cout << "sunday"
                   << " " << temp_course->weekday[1][i] << endl;
              cout << "monday"
                   << " " << temp_course->weekday[2][i] << endl;
              cout << "tuesday"
                   << " " << temp_course->weekday[3][i] << endl;
              cout << "wednesday"
                   << " " << temp_course->weekday[4][i] << endl;
          }

          temp_course = temp_course->next;
      }*/

    table_list1 = plan_maker(course_list, teach_list);

    while (table_list1 != NULL)
    {

        cout << table_list1->course_name << endl;
        cout << table_list1->teacher << ":"
             << decode_hm(table_list1->hm) << endl;

        table_list1 = table_list1->next;
    }

    /*temp_list = teach_list;
    while (temp_list != NULL)
    {
        if (temp_list->teacher_name == "Amin")
        {

            for (j = 0; j < temp_list->free_day.size(); j++)
            {
                cout << temp_list->free_day[j] << " ";
            }
            cout << temp_list->num_courses << " ";
            for (j = 0; j < temp_list->courses.size(); j++)
            {
                cout << temp_list->courses[j] << " ";
            }
            cout << endl;

            for (i = 0; i < 3; i++)
            {
                if (i == 0)
                {
                    cout << "7:30 - 9 " << endl;
                }

                if (i == 1)
                {
                    cout << "9:30 - 11 " << endl;
                }
                if (i == 2)
                {
                    cout << "11:30 - 13 " << endl;
                }

                cout << "saturday"
                     << " " << temp_list->weekday[0][i] << endl;
                cout << "sunday"
                     << " " << temp_list->weekday[1][i] << endl;
                cout << "monday"
                     << " " << temp_list->weekday[2][i] << endl;
                cout << "tuesday"
                     << " " << temp_list->weekday[3][i] << endl;
                cout << "wednesday"
                     << " " << temp_list->weekday[4][i] << endl;
            }
        }

        temp_list = temp_list->next;
    }*/

    table_list2 = plan_maker(course_list, teach_list);

    while (table_list2 != NULL)
    {

        cout << table_list2->course_name << endl;
        cout << table_list2->teacher << ":"
             << decode_hm(table_list2->hm2) << endl;

        table_list2 = table_list2->next;
    }
}

void tokenize(string const &str, const char delim, vector<string> &out)
{
    // construct a stream from the string
    stringstream ss(str);

    string s;
    while (getline(ss, s, delim))
    {
        out.push_back(s);
    }
}

teachers *teacher_construct(vector<string> str)
{
    int i = 0;
    int j = 0;
    int x = 0;
    stringstream ss;
    stringstream sss;
    teachers *teach = new teachers();

    teach->teacher_name = str[0];
    // cout << str[0] << endl;

    ss << str[1];
    ss >> x;
    teach->num_freedays = x;

    for (i = 0; i < teach->num_freedays; i++)
    {
        teach->free_day.push_back(str[i + 2]);
    }

    sss << str[i + 2];
    sss >> x;
    teach->num_courses = x;

    for (j = 0; j < teach->num_courses; j++)
    {
        teach->courses.push_back(str[j + i + 3]);
    }

    teach->next = NULL;

    /*  cout << teach->teacher_name << " " << teach->num_freedays << " ";
      for (j = 0; j < teach->free_day.size(); j++)
      {
          cout << teach->free_day[j] << " ";
      }
      cout << teach->num_courses << " ";
      for (j = 0; j < teach->courses.size(); j++)
      {
          cout << teach->courses[j] << " ";
      }
      cout << endl;*/

    return teach;
}

lesson_order *courses_construct(vector<string> str)
{

    stringstream ss;
    stringstream sss;
    lesson_order *lesson = new lesson_order();
    lesson->name = str[0];
    lesson->day1 = str[1];
    lesson->day2 = str[2];
    lesson->start_time = time_hm(str[3]);
    lesson->end_time = time_hm(str[4]);

    lesson->next = NULL;
    return lesson;
}

int weekday_arr_filler(string weekday)
{
    int i = 0;
    if (weekday == "Saturday")
    {
        i = 0;
    }
    else if (weekday == "Sunday")
    {
        i = 1;
    }
    else if (weekday == "Monday")
    {
        i = 2;
    }
    else if (weekday == "Tuesday")
    {
        i = 3;
    }
    else if (weekday == "Wednesday")
    {
        i = 4;
    }
    return i;
}

string decode_weekday(int day, int hm)
{
    string result = "";
    if (day == 0)
    {
        result = "Saturday";
    }
    else if (day == 1)
    {
        result = "Sunday";
    }
    else if (day == 2)
    {
        result = "Monday";
    }
    else if (day == 3)
    {
        result = "Tuesday";
    }
    else if (day == 4)
    {
        result = "Wednesday";
    }
    else
    {
        result = "No Day!";
    }

    if (hm == 0)
    {
        result += " 07:30 09:00";
    }
    else if (hm == 1)
    {
        result += " 09:30 11:00";
    }
    else if (hm == 2)
    {
        result += " 11:30 13:00";
    }
    else
    {
        result += " No Time!";
    }
    return result;
}

string decode_hm(int hm)
{
    string result = "";
    if (hm == 0)
    {
        result += " 07:30 09:00";
    }
    else if (hm == 1)
    {
        result += " 09:30 11:00";
    }
    else if (hm == 2)
    {
        result += " 11:30 13:00";
    }
    else
    {
        result += " No Time!";
    }
    return result;
}

void checking_teacher_block(teachers *teach)
{
    int i = 0;
    int j = 0;
    teach->num_freetimes = teach->num_freedays * 3;
    for (i = 0; i < teach->num_freedays; i++)
    {
        if (teach->free_day[i] == "Saturday")
        {
            for (j = 0; j < 3; j++)
            {
                teach->weekday[0][j] = 1;
            }
        }
        else if (teach->free_day[i] == "Sunday")
        {
            for (j = 0; j < 3; j++)
            {
                teach->weekday[1][j] = 1;
            }
        }
        else if (teach->free_day[i] == "Monday")
        {
            for (j = 0; j < 3; j++)
            {
                teach->weekday[2][j] = 1;
            }
        }
        else if (teach->free_day[i] == "Tuesday")
        {
            for (j = 0; j < 3; j++)
            {
                teach->weekday[3][j] = 1;
            }
        }
        else if (teach->free_day[i] == "Wednesday")
        {
            for (j = 0; j < 3; j++)
            {
                teach->weekday[4][j] = 1;
            }
        }
    }
}

void checking_block(lesson_order *course, string weekday)
{
    int i = 0;
    i = weekday_arr_filler(weekday);

    if (course->day1 == weekday)
    {
        if (hm_float(course->start_time) <= 7.5)
        {

            if ((course->end_time).hour >= 9)
            {
                course->weekday[i][0] = 1;
            }
            else
            {
                course->weekday[i][0] = 0;
            }
            if ((course->end_time).hour >= 11)
            {

                course->weekday[i][1] = 1;
            }
            else
            {
                course->weekday[i][1] = 0;
            }
            if ((course->end_time).hour >= 13)
            {
                course->weekday[i][2] = 1;
            }
            else
            {
                course->weekday[i][2] = 0;
            }
        }

        else if (hm_float(course->start_time) <= 9.5)
        {

            course->weekday[i][0] = 0;

            if ((course->end_time).hour >= 11)
            {

                course->weekday[i][1] = 1;
            }
            else
            {
                course->weekday[i][1] = 0;
            }
            if ((course->end_time).hour >= 13)
            {
                course->weekday[i][2] = 1;
            }
            else
            {
                course->weekday[i][2] = 0;
            }
        }

        else if (hm_float(course->start_time) <= 11.5)
        {

            course->weekday[i][0] = 0;

            course->weekday[i][1] = 0;

            if ((course->end_time).hour >= 13)
            {
                course->weekday[i][2] = 1;
            }
            else
            {
                course->weekday[i][2] = 0;
            }
        }
    }

    if (course->day2 == weekday)
    {
        if (hm_float(course->start_time) <= 7.5)
        {

            if ((course->end_time).hour >= 9)
            {

                course->weekday[i][0] = 1;
            }
            else
            {
                course->weekday[i][0] = 0;
            }
            if ((course->end_time).hour >= 11)
            {

                course->weekday[i][1] = 1;
            }
            else
            {
                course->weekday[i][1] = 0;
            }
            if ((course->end_time).hour >= 13)
            {
                course->weekday[i][2] = 1;
            }
            else
            {
                course->weekday[i][2] = 0;
            }
        }

        else if (hm_float(course->start_time) <= 9.5)
        {

            course->weekday[i][0] = 0;

            if ((course->end_time).hour >= 11)
            {

                course->weekday[i][1] = 1;
            }
            else
            {
                course->weekday[i][1] = 0;
            }
            if ((course->end_time).hour >= 13)
            {
                course->weekday[i][2] = 1;
            }
            else
            {
                course->weekday[i][2] = 0;
            }
        }

        else if (hm_float(course->start_time) <= 11.5)
        {

            course->weekday[i][0] = 0;

            course->weekday[i][1] = 0;

            if ((course->end_time).hour >= 13)
            {
                course->weekday[i][2] = 1;
            }
            else
            {
                course->weekday[i][2] = 0;
            }
        }
    }
}

void course_schedule(lesson_order *course)
{
    while (course != NULL)
    {
        /* int **arr = new int *[5];
         for (i = 0; i < 5; i++)
         {
             arr[i] = new int[3];
         }*/

        checking_block(course, "Saturday");
        checking_block(course, "Sunday");
        checking_block(course, "Monday");
        checking_block(course, "Tuesday");
        checking_block(course, "Wednesday");
        course = course->next;
    }
}

hm time_hm(string str)
{
    int x = 0;
    char delim = ':';
    hm t;
    stringstream ss;
    stringstream sss;
    vector<string> out;
    split_str(str, delim, out);

    ss << out[0];
    ss >> x;
    t.hour = x;
    sss << out[1];
    sss >> x;
    t.min = x;
    return t;
}

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

float hm_float(hm t)
{
    float x = 0;

    x += t.hour;
    x += float(t.min / 60);
    return x;
}

table *plan_maker(lesson_order *course, teachers *teach)
{
    day_hm dh;
    lesson_order *temp_course;
    teachers *active_teach;
    teachers *temp_teach;
    table *table_list = new table();
    table *temp_table;
    table *last_table;
    table *T;
    bool flag = false;

    temp_course = course;
    temp_teach = teach;

    while (temp_course != NULL)
    {

        dh = map_course_teacher(temp_course, temp_teach);

        if (dh.day == -1 && dh.hm == -1)
        {
            if (flag == false)
            {

                table_list->course_name = temp_course->name;
                table_list->day = -1;
                table_list->hm = -1;
                table_list->day2 = -1;
                table_list->hm2 == -1;
                table_list->teacher = "Not Found";
                flag = true;
            }
            else
            {

                temp_table = table_list;
                last_table = table_list;
                while (temp_table != NULL)
                {
                    last_table = temp_table;
                    temp_table = temp_table->next;
                }

                T = new table();

                T->course_name = temp_course->name;
                T->day = -1;
                T->hm = -1;
                T->day2 = -1;
                T->hm2 = -1;
                T->teacher = "Not Found";
                last_table->next = T;
            }
        }

        active_teach = find_teacher(temp_teach, dh);
        if (active_teach != NULL)
        {

            if (flag == false)
            {

                table_list->course_name = temp_course->name;
                table_list->day = dh.day;
                table_list->hm = dh.hm;
                table_list->day2 = dh.day2;
                table_list->hm2 == dh.hm2;
                table_list->teacher = active_teach->teacher_name;
                flag = true;
            }
            else
            {

                temp_table = table_list;
                last_table = table_list;
                while (temp_table != NULL)
                {
                    last_table = temp_table;
                    temp_table = temp_table->next;
                }
                T = new table();
                T->course_name = temp_course->name;
                T->day = dh.day;
                T->hm = dh.hm;
                T->day2 = dh.day2;
                T->hm2 == dh.hm2;
                T->teacher = active_teach->teacher_name;
                last_table->next = T;
            }
        }
        else
        {
            if (flag == false)
            {

                table_list->course_name = temp_course->name;
                table_list->day = -1;
                table_list->hm = -1;
                table_list->day2 = -1;
                table_list->hm2 == -1;
                table_list->teacher = "Not Found";
                flag = true;
            }
            else
            {

                temp_table = table_list;
                last_table = table_list;
                while (temp_table != NULL)
                {
                    last_table = temp_table;
                    temp_table = temp_table->next;
                }

                T = new table();

                T->course_name = temp_course->name;
                T->day = -1;
                T->hm = -1;
                T->day2 = -1;
                T->hm2 = -1;
                T->teacher = "Not Found";
                last_table->next = T;
            }
        }

        temp_course = temp_course->next;
    }

    return table_list;
}

day_hm map_course_teacher(lesson_order *lesson, teachers *teach)
{
    day_hm dh;
    teachers *temp_teach;
    int i = 0;
    int j = 0;
    int k = 0;
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 3; j++)
        {

            if (lesson->weekday[i][j] == 1)
            {

                dh.day = i;
                dh.hm = j;

                for (k = i + 1; k < 5; k++)
                {

                    if (lesson->weekday[k][j] == 1)
                    {

                        dh.day2 = k;
                        dh.hm2 = j;
                        if (teacher_found(teach, dh) == true)
                        {
                            return dh;
                        }
                    }
                }
            }
        }
    }

    dh.day = -1;
    dh.hm = -1;
    dh.day2 = -1;
    dh.hm2 = -1;

    return dh;
}

bool teacher_found(teachers *teach, day_hm dh)
{
    teachers *temp;

    temp = teach;

    while (temp != NULL)
    {

        if (temp->weekday[dh.day][dh.hm] == 1 && temp->weekday[dh.day2][dh.hm2] == 1)
        {

            return true;
        }

        temp = temp->next;
    }

    return false;
}

teachers *find_teacher(teachers *teach, day_hm dh)
{
    teachers *temp;
    teachers *priority = NULL;

    temp = teach;

    while (temp != NULL)
    {

        if (temp->weekday[dh.day][dh.hm] == 1 && temp->weekday[dh.day2][dh.hm2] == 1)
        {

            /* if (temp->teacher_name == "Amin")
             {
                 cout << temp->teacher_name << " " << temp->weekday[dh.day][dh.hm] << " " << temp->weekday[dh.day2][dh.hm2] << " " << endl;
                 cout << dh.day << " " << dh.hm << " " << dh.day2 << " " << dh.hm2 << endl;
             }*/

            if (priority == NULL)
            {
                priority = temp;
            }
            else
            {
                if (((priority->teacher_name).compare(temp->teacher_name)) > 0)

                {
                    priority = temp;
                }
            }
        }

        temp = temp->next;
    }

    if (priority != NULL)
    {
        priority->weekday[dh.day][dh.hm] = 0;
        priority->weekday[dh.day2][dh.hm2] = 0;
    }

    return priority;
}

bool teacher_course_checker(teachers *teach, string lesson_name)
{
    int i = 0;
    for (i = 0; i < teach->num_courses; i++)
    {
        if (teach->courses[i] == lesson_name)
        {
            return true;
        }
    }

    return false;
}