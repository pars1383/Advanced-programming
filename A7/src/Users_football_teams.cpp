#include "Users_football_teams.hpp"

using namespace std;

users_football_teams::users_football_teams()
{
}

int users_football_teams::team_name_index(std::string team_name)
{
    for (long unsigned int i = 0; i < users_teams.size(); i++)
        if (users_teams[i].get_team_name() == team_name)
            return i;
    return -1;
}

int users_football_teams::get_active_team_name_index()
{
    for (long unsigned int i = 0; i < users_teams.size(); i++)
        if (users_teams[i].get_login_status())
            return i;
    return -1;
}

bool users_football_teams::password_is_correct(string password)
{
    for (long unsigned int i = 0; i < users_teams.size(); i++)
        if (users_teams[i].get_password() == password)
            return true;
    return false;
}

bool users_football_teams::is_position_full(std::string role, int login_index)
{
    if (role == "GK")
    {
        if (users_teams[login_index].get_gk_full())
            return true;
    }
    else if (role == "DF")
    {
        if (users_teams[login_index].get_df1_full() && users_teams[login_index].get_df2_full())
            return true;
    }
    else if (role == "MD")
    {
        if (users_teams[login_index].get_md_full())
            return true;
    }
    else if (role == "FW")
    {
        if (users_teams[login_index].get_fw_full())
            return true;
    }
    return false;
}

void users_football_teams::update_player(player p, int login_index, bool full)
{
    std::string role = p.get_role();
    if (role == "GK")
    {

        users_teams[login_index].set_gk(p);
        users_teams[login_index].set_gk_full(full);
    }
    else if (role == "DF")
    {
        if (users_teams[login_index].get_df1_full())
        {
            users_teams[login_index].set_df2(p);
            users_teams[login_index].set_df2_full(full);
        }
        else
        {
            users_teams[login_index].set_df1(p);
            users_teams[login_index].set_df1_full(full);
        }
    }
    else if (role == "MD")
    {

        users_teams[login_index].set_md(p);
        users_teams[login_index].set_md_full(full);
    }
    else if (role == "FW")
    {

        users_teams[login_index].set_fw(p);
        users_teams[login_index].set_fw_full(full);
    }
}
