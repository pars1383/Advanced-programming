#ifndef LEAGUE_TEAM_HPP
#define LEAGUE_TEAM_HPP

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>

#include "Util.hpp"
#include "Player.hpp"


class league_team
{
private:
    std::string team_name;
    std::vector<player> *team_players;

public:
    std::string get_team_name();
    void set_team_name(std::string name);
    void add_player(std::string player_name, std::string role);
    std::vector<player> *get_players();

    league_team();
};



#endif
