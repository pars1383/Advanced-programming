#ifndef TEAM_WEEK_HPP
#define TEAM_WEEK_HPP

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>

#include "Util.hpp"


class team_week
{
private:
    std::string gk_name;
    float gk_score;
    std::string df1_name;
    float df1_score;
    std::string df2_name;
    float df2_score;
    std::string md_name;
    float md_score;
    std::string fw_name;
    float fw_score;

public:
    std::string get_gk_name();
    std::string get_df1_name();
    std::string get_df2_name();
    std::string get_md_name();
    std::string get_fw_name();
    float get_gk_score();
    float get_df1_score();
    float get_df2_score();
    float get_md_score();
    float get_fw_score();
    void set_gk(std::string name, float score);
    void set_df1(std::string name, float score);
    void set_df2(std::string name, float score);
    void set_md(std::string name, float score);
    void set_fw(std::string name, float score);
    team_week();
};



#endif
