#include "Player.hpp"

using namespace std;

player::player()
{
    score = 0;
    red_card = false;
    yellow_card = 0;
    injured = 0;
}

std::string player::get_name()
{
    return name;
}

float player::get_score()
{
    return score;
}
std::string player::get_role()
{
    return role;
}

bool player::get_red_card()
{
    return red_card;
}

int player::get_yellow_card()
{
    return yellow_card;
}

int player::get_injured()
{
    return injured;
}

void player::set_name(std::string name)
{
    this->name = name;
}
void player::set_score(float score)
{
    this->score = score;
}
void player::set_role(std::string role)
{
    this->role = role;
}

void player::set_red_card(bool rc)
{
    this->red_card = rc;
}

void player::set_yellow_card(int yc)
{
    this->yellow_card = yc;
}

void player::set_injured(int inj)
{
    this->injured = inj;
}
