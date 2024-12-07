#include "League_team.hpp"

using namespace std;

league_team::league_team()
{
    team_players = new std::vector<player>();
}

void league_team::add_player(std::string player_name, std::string role)
{
    player pl;
    pl.set_name(player_name);
    pl.set_role(role);
    team_players->push_back(pl);
}

std::string league_team::get_team_name()
{
    return team_name;
}
std::vector<player> *league_team::get_players()
{
    return team_players;
}

void league_team::set_team_name(std::string name)
{
    this->team_name = name;
}
