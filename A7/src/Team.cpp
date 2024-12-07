#include "Team.hpp"

using namespace std;

team::team()
{
    gk_full = false;
    df1_full = false;
    df2_full = false;
    md_full = false;
    fw_full = false;
}

void team::set_gk(player GoalKeeper)
{
    this->GoalKeeper = GoalKeeper;
    gk_full = true;
}
void team::set_df1(player Defender1)
{
    this->Defender1 = Defender1;
    df1_full = true;
}
void team::set_df2(player Defender2)
{
    this->Defender2 = Defender2;
    df2_full = true;
}
void team::set_md(player Midfielder)
{
    this->Midfielder = Midfielder;
    md_full = true;
}
void team::set_fw(player Forward)
{
    this->Forward = Forward;
    fw_full = true;
}

void team::set_gk_full(bool full)
{
    gk_full = full;
}

void team::set_df1_full(bool full)
{
    df1_full = full;
}

void team::set_df2_full(bool full)
{
    df2_full = full;
}

void team::set_md_full(bool full)
{
    md_full = full;
}
void team::set_fw_full(bool full)
{
    fw_full = full;
}

player team::get_gk()
{
    return GoalKeeper;
}
player team::get_df1()
{
    return Defender1;
}
player team::get_df2()
{
    return Defender2;
}
player team::get_md()
{
    return Midfielder;
}
player team::get_fw()
{
    return Forward;
}

bool team::get_gk_full()
{
    return gk_full;
}

bool team::get_df1_full()
{
    return df1_full;
}

bool team::get_df2_full()
{
    return df2_full;
}

bool team::get_md_full()
{
    return md_full;
}

bool team::get_fw_full()
{
    return fw_full;
}
