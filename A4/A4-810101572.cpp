#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include <queue>

using namespace std;

const char CSV_DELIMITER = ' ';
const int INVALID = -1;
const string ID = "id";
const string NAME = "name";
const string AGE = "age";
const string LEVEL = "level";
const string emp_id = "employee_id";
const string DAY = "day";
const string work_inter = "working_interval";

#define EXIT_FAILURE -1

typedef struct employee
{
    int id;
    string name;
    int age;
    string level;
} employee;


typedef struct working_hours
{
    int employee_id;
    int day;
    string working_interval;
} working_hours;

typedef struct teams
{
    int team_id;
    int team_head_id;
    string member_ids;
    int bonus_min_working_hours;
    float bonus_working_hours_max_variance;
} teams;

typedef struct salary_configs
{
    string level;
    int base_salary;
    int salary_per_hour;
    int salary_per_extra_hour;
    int official_working_hours;
    int tax_percentage;

} salary_configs;


vector<employee> get_employees(char *file);
vector<working_hours> get_working_hours(char *file);
vector<teams> get_teams(char *file);
vector<salary_configs> get_salary_config(char *file);
vector<string> split(string line, char delimiter);
vector<vector<string> > read_csv(char *file);
vector<employee> tokenize_table(vector<vector<string> > table);
vector<working_hours> tokenize_table_working_hours(vector<vector<string> > table);
vector<teams> tokenize_table_teams(vector<vector<string> > table);
vector<salary_configs> tokenize_table_salary_configs(vector<vector<string> > table);
employee tokenize(vector<string> raw, vector<string> header);
working_hours tokenize_hours(vector<string> raw, vector<string> header);
teams tokenize_teams(vector<string> raw, vector<string> header);
salary_configs tokenize_salary_configs(vector<string> raw, vector<string> header);
int find_index_in_vector(const vector<string> &vec, string s);


class CommandHandler
{

public:
    CommandHandler();
    void run();

private:
    vector<string> tokenizeInput(string input);
    void report_salaries();
    void report_employee_salary();
    void report_team_salary();
    void report_total_hours_per_day();
    void report_employee_per_hour();
    void show_salary_config();
};

void CommandHandler::run()
{
    const int COMMAND_TYPE_INDEX = 0;
    string input;
    while (getline(cin, input))
    {
        const string commandType = tokenizeInput(input)[COMMAND_TYPE_INDEX];
        if (commandType == "report_salaries")
            cout << "report_salaries()" << endl;
    }
}

void CommandHandler::report_salaries()
{
}
void CommandHandler::report_employee_salary()
{
}

void CommandHandler::report_team_salary()
{

}
void CommandHandler::report_total_hours_per_day()
{
}
void CommandHandler::report_employee_per_hour()
{
}
void CommandHandler::show_salary_config()
{
}



int main(int argc, char *argv[])
{
    //int i = 0;
    vector<employee> employees;
    vector<working_hours> work_hour;
    vector<teams> team;
    vector<salary_configs> salary;

    if (argc < 2)
    {
        cout << "no csv file name in args" << endl;
        // exit(EXIT_FAILURE);
    }

    employees = get_employees(argv[1]);
   /* for (i = 0; i < employees.size(); i++)
    {
        cout << employees[i].id << " " << employees[i].age << " " << employees[i].name << " " << employees[i].level << endl;
    }*/

    //work_hour = get_working_hours(argv[2]);
     //team = get_teams(argv[3]);
    // salary = get_salary_config(argv[4]);

    // CommandHandler CommandHandler = CommandHandler();
     //CommandHandler.run();
    return 0;
}

vector<employee> get_employees(char *file)
{
    vector<vector<string> > table;
    table = read_csv(file);
    return tokenize_table(table);
}

vector<working_hours> get_working_hours(char *file)
{
    vector<vector<string> > table;
    table = read_csv(file);
    return tokenize_table_working_hours(table);
}

vector<teams> get_teams(char *file)
{
    vector<vector<string> > table;
    table = read_csv(file);
    return tokenize_table_teams(table);
}

vector<salary_configs> get_salary_config(char *file)
{
    vector<vector<string> > table;
    table = read_csv(file);
    return tokenize_table_salary_configs(table);
}

vector<string> split(string line, char delimiter)
{
    stringstream stream(line);
    vector<string> out_list;
    string block;
    while (getline(stream, block, delimiter))
    {
        out_list.push_back(block);
    }
    return out_list;
}

vector<vector<string> > read_csv(char *file)
{
    string line;
    fstream fin;
    fin.open(file, ios::in);
    vector<vector<string> > table;
    while (getline(fin, line))
    {
        table.push_back(split(line, CSV_DELIMITER));
    }
    return table;
}

vector<employee> tokenize_table(vector<vector<string> > table)
{
    vector<employee> tokens;
    vector<string> header; 
    header = table[0];
    for (int i = 1; i < table.size(); i++)
    {
        tokens.push_back(tokenize(table[i], header));
    }
    return tokens;
}

vector<working_hours> tokenize_table_working_hours(vector<vector<string> > table)
{
    vector<working_hours> tokens;
    vector<string> header = table[0];
    for (int i = 1; i < table.size() ; i++)
    {
        tokens.push_back(tokenize_hours(table[i], header));
    }
    return tokens;
}

vector<teams> tokenize_table_teams(vector<vector<string> > table)
{
    vector<teams> tokens;
    vector<string> header = table[0];
    for (int i = 1; i < table.size(); i++)
    {
        tokens.push_back(tokenize_teams(table[i], header));
    }
    return tokens;
}

vector<salary_configs> tokenize_table_salary_configs(vector<vector<string> > table)
{
    vector<salary_configs> tokens;
    vector<string> header = table[0];
    for (int i = 1; i < table.size(); i++)
    {
        tokens.push_back(tokenize_salary_configs(table[i], header));
    }
    return tokens;
}

employee tokenize(vector<string> raw, vector<string> header)
{
    employee employees;
    stringstream ss;
    stringstream sss;
    int x = 0;
    int y = 0;

    sss << raw[find_index_in_vector(header, ID)];
    sss >> y;
    employees.id = y;
    employees.name = raw[find_index_in_vector(header, NAME)];
    ss << raw[find_index_in_vector(header, AGE)];
    ss >> x;
    employees.age = x;
    employees.level = raw[find_index_in_vector(header, LEVEL)];

    return employees;
}

working_hours tokenize_hours(vector<string> raw, vector<string> header)
{
    working_hours working;
    stringstream ss;
    stringstream sss;
    int x = 0;
    int y = 0;

    sss << raw[find_index_in_vector(header, emp_id)];
    sss >> y;
    working.employee_id = y;
    ss << raw[find_index_in_vector(header, DAY)];
    ss >> x;
    working.day = x;
    working.working_interval = raw[find_index_in_vector(header, work_inter)];

    return working;
}

teams tokenize_teams(vector<string> raw, vector<string> header)
{
    teams team;
    stringstream ss;
    stringstream sss;
    stringstream ssss;
    stringstream sssss;
    int x = 0;
    int y = 0;
    int z = 0;
    float i = 0;

    sss << raw[find_index_in_vector(header, "team_id")];
    sss >> y;
    team.team_id = y;
    ss << raw[find_index_in_vector(header, "team_head_id")];
    ss >> x;
    team.team_head_id = x;
    team.member_ids = raw[find_index_in_vector(header, "member_ids")];
    ssss << raw[find_index_in_vector(header, "bonus_min_working_hours")];
    ssss >> z;
    team.bonus_min_working_hours = z;
    sssss << raw[find_index_in_vector(header, "bonus_working_hours_max_variance")];
    sssss >> i;
    team.bonus_working_hours_max_variance = i;
    return team;
}

salary_configs tokenize_salary_configs(vector<string> raw, vector<string> header)
{
    teams team;
    stringstream ss;
    stringstream sss;
    stringstream ssss;
    stringstream sssss;
    stringstream sls;
    int x = 0;
    int y = 0;
    int z = 0;
    int i = 0;
    int j = 0;

    salary_configs salary;
    salary.level = raw[find_index_in_vector(header, "level")];
    sss << raw[find_index_in_vector(header, "base_salary")];
    sss >> y;
    salary.base_salary = y;
    ss << raw[find_index_in_vector(header, "salary_per_hour")];
    ss >> x;
    salary.salary_per_hour = x;
    sssss << raw[find_index_in_vector(header, "salary_per_extra_hour")];
    sssss >> i;
    salary.salary_per_extra_hour = i;
    ssss << raw[find_index_in_vector(header, "tax_percentage")];
    ssss >> z;
    salary.tax_percentage = z;
    sls << raw[find_index_in_vector(header, "official_working_hours")];
    sls >> j;
    salary.official_working_hours = j;

    return salary;
}

int find_index_in_vector(const vector<string> &vec, string s)
{
    for (int i = 0; i < vec.size(); i++)
        if (vec[i] == s)
            return i;

    return INVALID;
}

vector<working_hours> sorting(vector<working_hours> work_hour)
{
    int i = 0;

    for ( i = 0; i < work_hour.size(); i++)
    {
        if (work_hour[i].employee_id > work_hour[i+1].employee_id)
        {
            swap(work_hour[i].employee_id , work_hour[i+1].employee_id);
        }
        
    }
    return work_hour;
    
}