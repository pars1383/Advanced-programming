#include "List_of_players.hpp"

using namespace std;

list_of_players::list_of_players()
{
}

void list_of_players::add_player(std::string player_name, std::string role)
{

    if (role == "GK")
        gk.push_back(player_name);
    else if (role == "DF")
        df.push_back(player_name);
    else if (role == "MD")
        md.push_back(player_name);
    else if (role == "FW")
       fw.push_back(player_name);
}

bool list_of_players::player_existence(std::string player_name)
{
    long unsigned int i = 0;
    for ( i = 0; i < gk.size(); i++)
        if (gk[i] == player_name)
            return true;
    for (i = 0; i < df.size(); i++)
        if (df[i] == player_name)
            return true;
    for (i = 0; i < md.size(); i++)
        if (md[i] == player_name)
            return true;
    for (i = 0; i < fw.size(); i++)
        if (fw[i] == player_name)
            return true;
    return false;
}

std::string list_of_players::get_role(std::string player_name)
{
    long unsigned int i = 0;
    for (i = 0; i < gk.size(); i++)
        if (gk[i] == player_name)
            return "GK";
    for (i = 0; i < df.size(); i++)
        if (df[i] == player_name)
            return "DF";
    for (i = 0; i < md.size(); i++)
        if (md[i] == player_name)
            return "MD";
    for (i = 0; i < fw.size(); i++)
        if (fw[i] == player_name)
            return "FW";
    return "none";
}

std::vector<std::string> list_of_players::get_Goalkeepers_list()
{
    return gk;
}

std::vector<std::string> list_of_players::get_Defenders_list()
{
    return df;
}

std::vector<std::string> list_of_players::get_Midfielders_list()
{
    return md;
}

std::vector<std::string> list_of_players::get_Forwards_list()
{
    return fw;
}
