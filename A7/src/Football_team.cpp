#include "Football_team.hpp"

using namespace std;

football_team::football_team()
{
    login_status = false;
    points = 0;
    team_completed = false;
    number_of_sells = 0;
}
std::string football_team::get_team_name()
{
    return team_name;
}
std::string football_team::get_password()
{
    return password;
}

bool football_team::get_login_status()
{
    return login_status;
}

float football_team::get_points()
{
    return points;
}

bool football_team::get_team_completed()
{
    return team_completed;
}

int football_team::get_number_of_sells()
{
    return number_of_sells;
}

void football_team::set_team_name(std::string team_name)
{
    this->team_name = team_name;
}
void football_team::set_password(std::string password)
{
    this->password = password;
}
void football_team::set_login_status(bool login_s)
{
    this->login_status = login_s;
}

void football_team::set_signup(std::string team_name, std::string password)
{
    this->team_name = team_name;
    this->password = password;
    this->login_status = false;
}
void football_team::set_login()
{
    this->login_status = true;
}

void football_team::set_points(float p)
{
    this->points = p;
}

void football_team::set_team_completed(bool tc)
{
    this->team_completed = tc;
}

void football_team::set_number_of_sells(int nos)
{
    this->number_of_sells = nos;
}

void football_team::print_team_info()
{
    cout << "fantasy_team: " << this->get_team_name() << endl;
    cout << "Goalkeeper: " << this->get_gk().get_name() << endl;
    if (this->get_df1().get_name() < this->get_df2().get_name())
    {
        cout << "Defender1: " << this->get_df1().get_name() << endl;
        cout << "Defender2: " << this->get_df2().get_name() << endl;
    }
    else
    {
        cout << "Defender1: " << this->get_df2().get_name() << endl;
        cout << "Defender2: " << this->get_df1().get_name() << endl;
    }
    cout << "Midfielder: " << this->get_md().get_name() << endl;
    cout << "Striker: " << this->get_fw().get_name() << endl;
    cout << "Total Points: " << this->get_points() << endl;
}
