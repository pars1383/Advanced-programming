#ifndef USERS_FOOTBALL_TEAMS_HPP
#define USERS_FOOTBALL_TEAMS_HPP

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>

#include "Util.hpp"
#include "Football_team.hpp"


class users_football_teams
{
private:
public:
    std::vector<football_team> users_teams;
    int team_name_index(std::string team_name);
    int get_active_team_name_index();
    bool password_is_correct(std::string password);
    void update_player(player p, int login_index, bool full);
    bool is_position_full(std::string role, int login_index);
    users_football_teams();
};



#endif
