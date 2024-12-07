#ifndef TEAM_HPP
#define TEAM_HPP

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


class team
{
private:
    player GoalKeeper;
    bool gk_full;
    player Defender1;
    bool df1_full;
    player Defender2;
    bool df2_full;
    player Midfielder;
    bool md_full;
    player Forward;
    bool fw_full;

public:
    void set_gk(player GoalKeeper);
    void set_df1(player Defender1);
    void set_df2(player Defender2);
    void set_md(player Midfielder);
    void set_fw(player Forward);
    void set_gk_full(bool full);
    void set_df1_full(bool full);
    void set_df2_full(bool full);
    void set_md_full(bool full);
    void set_fw_full(bool full);
    player get_gk();
    player get_df1();
    player get_df2();
    player get_md();
    player get_fw();
    bool get_gk_full();
    bool get_df1_full();
    bool get_df2_full();
    bool get_md_full();
    bool get_fw_full();

    team();
};



#endif
