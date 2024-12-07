#ifndef FOOTBALL_TEAM_HPP
#define FOOTBALLTEAM_HPP

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>

#include "Util.hpp"
#include "Team.hpp"


class football_team : public team
{
private:
    std::string team_name;
    std::string password;
    bool login_status;
    float points;
    bool team_completed;
    int number_of_sells;

public:
    std::string get_team_name();
    std::string get_password();
    bool get_login_status();
    float get_points();
    bool get_team_completed();
    int get_number_of_sells();
    void set_team_name(std::string team_name);
    void set_password(std::string password);
    void set_signup(std::string team_name, std::string password);
    void set_login();
    void set_login_status(bool login_s);
    void set_points(float p);
    void set_team_completed(bool tc);
    void set_number_of_sells(int nos);
    void print_team_info();
    football_team();
};



#endif
