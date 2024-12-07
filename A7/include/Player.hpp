#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>

#include "Util.hpp"



class player
{
private:
    std::string name;
    float score;
    std::string role;
    bool red_card;
    int yellow_card;
    int injured;

public:
    player();
    std::string get_name();
    float get_score();
    std::string get_role();
    bool get_red_card();
    int get_yellow_card();
    int get_injured();
    void set_name(std::string name);
    void set_score(float score);
    void set_role(std::string role);
    void set_red_card(bool rc);
    void set_yellow_card(int yc);
    void set_injured(int inj);
};




#endif
