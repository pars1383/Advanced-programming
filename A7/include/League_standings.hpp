#ifndef LEAGUE_STANDINGS_HPP
#define LEAGUE_STANDINGS_HPP

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>

#include "Util.hpp"
#include "Team_info.hpp"


class league_standings
{
private:
public:
    std::vector<team_info> league_standing_info;
    int get_team_score(int index);
    int get_gf(int index);
    int get_ga(int index);
    void set_team_score(int n, int index);
    void set_num_goals_for(int n, int index);
    void set_num_goals_against(int n, int index);
    int find_team_name_index(std::string name);
    league_standings();
};




#endif
