#include "Player_week_info.hpp"

using namespace std;

player_week_info::player_week_info()
{
}

void player_week_info::add_matches_team(string teams_name)
{
    this->matches_team.push_back(teams_name);
}

void player_week_info::add_matches_result(string result)
{
    this->matches_result.push_back(result);
}
void player_week_info::add_injured_player(string injured)
{
    this->injured_player.push_back(injured);
}

void player_week_info::add_yellow_card_player(string yc)
{
    this->yellow_card_player.push_back(yc);
}
void player_week_info::add_red_card_player(string rc)
{
    this->red_card_player.push_back(rc);
}
void player_week_info::add_player_score(string ps)
{
    this->player_score.push_back(ps);
}
vector<string> player_week_info::get_matches_team()
{
    return matches_team;
}
vector<string> player_week_info::get_matches_result()
{
    return matches_result;
}
vector<string> player_week_info::get_injured_player()
{
    return injured_player;
}
vector<string> player_week_info::get_yellow_card_player()
{
    return yellow_card_player;
}
vector<string> player_week_info::get_red_card_player()
{
    return red_card_player;
}
vector<string> player_week_info::get_player_score()
{
    return player_score;
}
