#ifndef PLAYER_WEEK_INFO_HPP
#define PLAYER_WEEK_INFO_HPP

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>

#include "Util.hpp"



class player_week_info
{
private:
    std::vector<std::string> matches_team;
    std::vector<std::string> matches_result;
    std::vector<std::string> injured_player;
    std::vector<std::string> yellow_card_player;
    std::vector<std::string> red_card_player;
    std::vector<std::string> player_score;

public:
    void add_matches_team(std::string teams_name);
    void add_matches_result(std::string result);
    void add_injured_player(std::string injured);
    void add_yellow_card_player(std::string yc);
    void add_red_card_player(std::string rc);
    void add_player_score(std::string ps);
    std::vector<std::string> get_matches_team();
    std::vector<std::string> get_matches_result();
    std::vector<std::string> get_injured_player();
    std::vector<std::string> get_yellow_card_player();
    std::vector<std::string> get_red_card_player();
    std::vector<std::string> get_player_score();

    player_week_info();
};




#endif
