#ifndef LIST_OF_PLAYERS_HPP
#define LIST_OF_PLAYERS_HPP

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>

#include "Util.hpp"



class list_of_players
{
private:
    std::vector<std::string> gk;
   std::vector<std::string> df;
    std::vector<std::string> md;
    std::vector<std::string> fw;

public:
    void add_player(std::string player_name, std::string role);
    bool player_existence(std::string player_name);
    std::string get_role(std::string player_name);
    std::vector<std::string> get_Goalkeepers_list();
    std::vector<std::string> get_Defenders_list();
    std::vector<std::string> get_Midfielders_list();
    std::vector<std::string> get_Forwards_list();
    list_of_players();
};




#endif
