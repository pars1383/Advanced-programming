#include "Team_info.hpp"

using namespace std;

team_info::team_info()
{
    team_score = 0;
    gf = 0;
    ga = 0;
}

string team_info::get_team_name()
{
    return team_name;
}
int team_info::get_team_score()
{
    return team_score;
}
int team_info::get_gf()
{
    return gf;
}
int team_info::get_ga()
{
    return ga;
}
void team_info::set_team_name(string name)
{
    this->team_name = name;
}
void team_info::set_team_score(int score)
{
    this->team_score = score;
}
void team_info::set_gf(int gf)
{
    this->gf = gf;
}
void team_info::set_ga(int ga)
{
    this->ga = ga;
}

