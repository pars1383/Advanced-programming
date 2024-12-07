#ifndef COMMANDHANDLER_HPP
#define COMMANDHANDLER_HPP

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>
#include <fstream>

#include "Util.hpp"
#include "Admin.hpp"
#include "List_of_players.hpp"
#include "Users_football_teams.hpp"
#include "League_team.hpp"
#include "League_standings.hpp"
#include "Player_week_info.hpp"
#include "Team_week.hpp"


class CommandHandler : public admin
{
public:
    CommandHandler();
    void run();

private:
    list_of_players LOP;
    users_football_teams UFT;
    std::vector<player_week_info> PWI;
    std::vector<std::vector<team_week>> teams_weeks;
    std::vector<league_team> league_teams;
    league_standings LS;
    std::vector<std::string> tokenizeInput(std::string input);
    void signup(std::string input);
    void login(std::string input);
    void register_admin(std::string input);
    bool find_player(std::string player_name, int index);
    void sell_player(std::string input);
    void buy_player(std::string input);
    void close_transfer_window();
    void open_transfer_window();
    void read_csv_premier_league();
    void squad(std::string input);
    void pass_week();
    void read_csv_week(std::string week);
    bool get_red_card(std::string player_name, int week_number);
    int get_yellow_card(std::string player_name, int week_number);
    int get_injured(std::string player_name, int week_number);
    float get_score(std::string player_name, int week_number);
    void update_UFT();
    void update_UFT_index(int i);
    void team_of_the_week(std::string input);
    void players(std::string input);
    void league_stand();
    void users_ranking();
    void matches_result_league(std::string input);
    void save_week();
    bool find_yellow_card_player(std::string name, int week_number);
    bool find_injured_player(std::string name, int week_number);
    bool find_red_card_player(std::string name, int week_number);
    float get_player_score(std::string player_name, int week_number);
    void update_league_teams(int week_number);
    bool team_is_found(std::string team_name);
    void league_standing_first_week();
    void update_league_standing();
    std::vector<std::string> split(std::string line, char delimiter);
    void logout();
};




#endif
