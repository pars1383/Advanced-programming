#ifndef TEAM_INFO_HPP
#define TEAM_INFO_HPP

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>

#include "Util.hpp"



class team_info
{
private:
    std::string team_name;
    int team_score;
    int gf;
    int ga;

public:
    std::string get_team_name();
    int get_team_score();
    int get_gf();
    int get_ga();
    void set_team_name(std::string name);
    void set_team_score(int score);
    void set_gf(int gf);
    void set_ga(int ga);
    team_info();
};




#endif
