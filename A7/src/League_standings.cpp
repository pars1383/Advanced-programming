#include "League_standings.hpp"

using namespace std;

league_standings::league_standings()
{
}

int league_standings::get_team_score(int index)
{
    return this->league_standing_info[index].get_team_score();
}
int league_standings::get_gf(int index)
{
    return this->league_standing_info[index].get_gf();
}
int league_standings::get_ga(int index)
{
    return this->league_standing_info[index].get_ga();
}

void league_standings::set_team_score(int n, int index)
{
    this->league_standing_info[index].set_team_score(n);
}
void league_standings::set_num_goals_for(int n, int index)
{
    this->league_standing_info[index].set_gf(n);
}
void league_standings::set_num_goals_against(int n, int index)
{
    this->league_standing_info[index].set_ga(n);
}

int league_standings::find_team_name_index(string name)
{
    for (long unsigned int i = 0; i < league_standing_info.size(); i++)
        if (league_standing_info[i].get_team_name() == name)
            return i;
    return -1;
}
