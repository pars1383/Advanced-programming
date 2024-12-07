#include "Team_week.hpp"

using namespace std;

team_week::team_week()
{
}

string team_week::get_gk_name()
{
    return gk_name;
}
string team_week::get_df1_name()
{
    return df1_name;
}
string team_week::get_df2_name()
{
    return df2_name;
}
string team_week::get_md_name()
{
    return md_name;
}
string team_week::get_fw_name()
{
    return fw_name;
}
float team_week::get_gk_score()
{
    return gk_score;
}
float team_week::get_df1_score()
{
    return df1_score;
}
float team_week::get_df2_score()
{
    return df2_score;
}
float team_week::get_md_score()
{
    return md_score;
}
float team_week::get_fw_score()
{
    return fw_score;
}
void team_week::set_gk(string name, float score)
{
    this->gk_name = name;
    this->gk_score = score;
}
void team_week::set_df1(string name, float score)
{
    this->df1_name = name;
    this->df1_score = score;
}
void team_week::set_df2(string name, float score)
{
    this->df2_name = name;
    this->df2_score = score;
}
void team_week::set_md(string name, float score)
{
    this->md_name = name;
    this->md_score = score;
}
void team_week::set_fw(string name, float score)
{
    this->fw_name = name;
    this->fw_score = score;
}
