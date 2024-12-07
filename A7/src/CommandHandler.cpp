#include "CommandHandler.hpp"

using namespace std;

CommandHandler::CommandHandler()
{
}

void CommandHandler::run()
{
    const int COMMAND_TYPE_INDEX = 0;
    const int SECOND_COMMAND_TYPE_INDEX = 1;
    std::string input;
    read_csv_premier_league();

    read_csv_week(WEEK_1);
    update_league_teams(1);
    league_standing_first_week();

    while (getline(cin, input))
    {
        const std::string commandType = tokenizeInput(input)[COMMAND_TYPE_INDEX];

        if (commandType == POST)
        {
            const std::string secondcommandType = tokenizeInput(input)[SECOND_COMMAND_TYPE_INDEX];
            if (secondcommandType == SIGNUP)
                signup(input);
            else if (secondcommandType == LOGIN)
                login(input);
            else if (secondcommandType == LOGOUT)
                logout();
            else if (secondcommandType == REGISTER_ADMIN)
                register_admin(input);
            else if (secondcommandType == SELL_PLAYER)
                sell_player(input);
            else if (secondcommandType == BUY_PLAYER)
                buy_player(input);
            else if (secondcommandType == CLOSE_TRANSFER_WINDOW)
                close_transfer_window();
            else if (secondcommandType == OPEN_TRANSFER_WINDOW)
                open_transfer_window();
            else if (secondcommandType == PASS_WEEK)
                pass_week();
            else
                cout << "Not Found" << endl;
        }
        else if (commandType == GET)
        {
            const std::string secondcommandType = tokenizeInput(input)[SECOND_COMMAND_TYPE_INDEX];
            if (secondcommandType == SQUAD)
                squad(input);
            else if (secondcommandType == TEAM_OF_THE_WEEK)
                team_of_the_week(input);
            else if (secondcommandType == PLAYERS)
                players(input);
            else if (secondcommandType == LEAGUE_STANDINGS)
                league_stand();
            else if (secondcommandType == USERS_RANKING)
                users_ranking();
            else if (secondcommandType == MATCHES_RESULT_LEAGUE)
                matches_result_league(input);
            else
                cout << "Not Found" << endl;
        }

        else
            cout << "Bad Request" << endl;
    }
}

std::vector<std::string> CommandHandler::tokenizeInput(std::string input)
{
    stringstream inputStringStream(input);
    return std::vector<std::string>(istream_iterator<std::string>(inputStringStream),
                          istream_iterator<std::string>());
}

void CommandHandler::signup(std::string input)
{
    const int QUESTION_MARK = 2;
    const int TEAM_NAME_KEYWORD = 3;
    const int TEAM_NAME = 4;
    const int PASSWORD_KEYWORD = 5;
    const int PASSWORD = 6;

    std::vector<std::string> tokenized_input = tokenizeInput(input);
    football_team ft;

    if (tokenized_input.size() < 7 || tokenized_input[TEAM_NAME_KEYWORD] != "team_name" || tokenized_input[PASSWORD_KEYWORD] != "password" || tokenized_input[QUESTION_MARK] != "?")
        cout << "Bad Request" << endl;
    else
    {
        std::string team_name = tokenized_input[TEAM_NAME];
        std::string password = tokenized_input[PASSWORD];

        ft.set_signup(team_name, password);
        UFT.users_teams.push_back(ft);
        cout << "OK" << endl;
    }
}

void CommandHandler::login(std::string input)
{
    const int QUESTION_MARK = 2;
    const int TEAM_NAME_KEYWORD = 3;
    const int TEAM_NAME = 4;
    const int PASSWORD_KEYWORD = 5;
    const int PASSWORD = 6;

    std::vector<std::string> tokenized_input = tokenizeInput(input);

    if (tokenized_input.size() < 7 || tokenized_input[TEAM_NAME_KEYWORD] != "team_name" || tokenized_input[PASSWORD_KEYWORD] != "password" || tokenized_input[QUESTION_MARK] != "?")
        cout << "Bad Request" << endl;
    else
    {
        std::string team_name = tokenized_input[TEAM_NAME];
        std::string password = tokenized_input[PASSWORD];
        if (UFT.team_name_index(team_name) == -1)
            cout << "Not Found" << endl;
        else if (!(UFT.password_is_correct(password)))
            cout << "Permission Denied" << endl;
        else
        {
            int index = UFT.team_name_index(team_name);
            UFT.users_teams[index].set_login();
            cout << "OK" << endl;
        }
    }
}

void CommandHandler::logout()
{
   long unsigned int i = 0;
    for (i = 0; i < UFT.users_teams.size(); i++)
        if (UFT.users_teams[i].get_login_status())
        {
            UFT.users_teams[i].set_login_status(false);
            cout << "OK" << endl;
            break;
        }

    if (i == UFT.users_teams.size())
        cout << "This user is not login!" << endl;
}

void CommandHandler::register_admin(string input)
{
    const int QUESTION_MARK = 2;
    const int USERNAME_KEYWORD = 3;
    const int USERNAME = 4;
    const int PASSWORD_KEYWORD = 5;
    const int PASSWORD = 6;

    std::vector<std::string> tokenized_input = tokenizeInput(input);

    if (tokenized_input.size() < 7 || tokenized_input[USERNAME_KEYWORD] != "username" || tokenized_input[PASSWORD_KEYWORD] != "password" || tokenized_input[QUESTION_MARK] != "?")
        cout << "Bad Request" << endl;
    else if (tokenized_input[USERNAME] != "admin" || tokenized_input[PASSWORD] != "123456")
        cout << "Bad Request" << endl;
    else
    {
        this->set_register_status(true);
        cout << "OK" << endl;
    }
}

bool CommandHandler::find_player(std::string player_name, int index)
{
    if (UFT.users_teams[index].get_gk().get_name() == player_name)
        return true;
    else if (UFT.users_teams[index].get_df1().get_name() == player_name)
        return true;
    else if (UFT.users_teams[index].get_df2().get_name() == player_name)
        return true;
    else if (UFT.users_teams[index].get_md().get_name() == player_name)
        return true;
    else if (UFT.users_teams[index].get_fw().get_name() == player_name)
        return true;
    return false;
}

void CommandHandler::sell_player(std::string input)
{
    const int QUESTION_MARK = 2;
    const int NAME_KEYWORD = 3;
    const int FIRST_NAME = 4;
    const int MIDDLE_NAME = 5;
    const int LAST_NAME = 6;

    std::vector<std::string> tokenized_input = tokenizeInput(input);
    std::string player_name;

    int size = tokenized_input.size();
     if (size < 5)
         cout << "Bad Request" << endl;
    else if (tokenized_input[NAME_KEYWORD] != "name" || tokenized_input[QUESTION_MARK] != "?")
        cout << "Bad Request" << endl;
    else
    {
        
       
            if (size == 5)
                player_name = tokenized_input[FIRST_NAME];
            else if (size == 6)
                player_name = tokenized_input[FIRST_NAME] + " " + tokenized_input[MIDDLE_NAME];
            else if (size == 7)
                player_name = tokenized_input[FIRST_NAME] + " " + tokenized_input[MIDDLE_NAME] + " " + tokenized_input[LAST_NAME];

            if (!LOP.player_existence(player_name))
                cout << "Not Found" << endl;
            else
            {
                int login_team_index = UFT.get_active_team_name_index();
                if (login_team_index == -1)
                {
                    cout << "Bad Request" << endl;
                }
                else
                {
                int x = UFT.users_teams[login_team_index].get_number_of_sells();
                    if (!this->get_transfer_window())
                        cout << "Permission Denied" << endl;
                    else if (UFT.users_teams[login_team_index].get_team_completed())
                    {
                        if (find_player(player_name, login_team_index))
                        {
                          if (x < 2)
                          {
                              player p;
                              p.set_name("");
                              std::string role = LOP.get_role(player_name);
                              p.set_role(role);

                              UFT.update_player(p, login_team_index, false);
                              UFT.users_teams[login_team_index].set_team_completed(false);
                              UFT.users_teams[login_team_index].set_number_of_sells(x + 1);
                              cout << "OK" << endl;
                           }
                           else
                              cout << "Permission Denied" << endl;
                         }
                         else
                         cout << "Not Found" << endl;
                    }
                    else
                    {
                      if (find_player(player_name, login_team_index))
                        {
                         if(x < 2)
                         {
                          player p;
                          p.set_name("");
                          std::string role = LOP.get_role(player_name);
                          p.set_role(role);

                          UFT.update_player(p, login_team_index, false);
                          UFT.users_teams[login_team_index].set_team_completed(false);
                          UFT.users_teams[login_team_index].set_number_of_sells(x + 1);
                          cout << "OK" << endl;
                         }
                         else
                          cout << "Permission Denied" << endl;
                         }
                         else 
                         cout<< "Not Found" << endl;
                    }
                }
            }
        }
    
}

bool CommandHandler::get_red_card(std::string player_name, int week_number)
{
    for (long unsigned int i = 0; i < league_teams.size(); i++)
        for (long unsigned int j = 0; j < (*league_teams[i].get_players()).size(); j++)
        {
            std::vector<player> p = (*league_teams[i].get_players());

            if (p[j].get_name() == player_name)
            {
                return (*(league_teams[i].get_players()))[j].get_red_card();
            }
        }
    return false;
}

int CommandHandler::get_yellow_card(std::string player_name, int week_number)
{
    for (long unsigned int i = 0; i < league_teams.size(); i++)
        for (long unsigned int j = 0; j < (*league_teams[i].get_players()).size(); j++)
        {
            std::vector<player> p = (*league_teams[i].get_players());

            if (p[j].get_name() == player_name)
            {
                return (*(league_teams[i].get_players()))[j].get_yellow_card();
            }
        }
    return -1;
}

int CommandHandler::get_injured(std::string player_name, int week_number)
{
    for (long unsigned int i = 0; i < league_teams.size(); i++)
        for (long unsigned int j = 0; j < (*league_teams[i].get_players()).size(); j++)
        {
            std::vector<player> p = (*league_teams[i].get_players());

            if (p[j].get_name() == player_name)
            {
                return (*(league_teams[i].get_players()))[j].get_injured();
            }
        }
    return -1;
}

float CommandHandler::get_score(std::string player_name, int week_number)
{
    for (long unsigned int i = 0; i < league_teams.size(); i++)
        for (long unsigned int j = 0; j < (*league_teams[i].get_players()).size(); j++)
        {
            std::vector<player> p = (*league_teams[i].get_players());

            if (p[j].get_name() == player_name)
            {
                return (*(league_teams[i].get_players()))[j].get_score();
            }
        }
    return -1;
}

void CommandHandler::buy_player(string input)
{
    const int QUESTION_MARK = 2;
    const int NAME_KEYWORD = 3;
    const int FIRST_NAME = 4;
    const int MIDDLE_NAME = 5;
    const int LAST_NAME = 6;

    std::vector<std::string> tokenized_input = tokenizeInput(input);
    std::string player_name;
     int size = tokenized_input.size();
    if (size < 5)
        cout << "Bad Request" << endl;
    else if (tokenized_input[NAME_KEYWORD] != "name" || tokenized_input[QUESTION_MARK] != "?")
        cout << "Bad Request" << endl;
    else
    {
       
       
        
            if (size == 5)
                player_name = tokenized_input[FIRST_NAME];
            else if (size == 6)
                player_name = tokenized_input[FIRST_NAME] + " " + tokenized_input[MIDDLE_NAME];
            else if (size == 7)
                player_name = tokenized_input[FIRST_NAME] + " " + tokenized_input[MIDDLE_NAME] + " " + tokenized_input[LAST_NAME];

            if (!LOP.player_existence(player_name))
                cout << "Not Found" << endl;
            else
            {
                int login_team_index = UFT.get_active_team_name_index();
                if (login_team_index == -1)
                {
                    cout << "Bad Request" << endl;
                }
                else
                {
                   
                    int injured = 0;
                    int yellow_card = 0;
                    bool red_card = false;

                    red_card = this->get_red_card(player_name, this->get_week_number());
                    yellow_card = this->get_yellow_card(player_name, this->get_week_number());
                    injured = this->get_injured(player_name, this->get_week_number());


                    if (!this->get_transfer_window())
                        cout << "Permission Denied" << endl;
                    else if (red_card || yellow_card == 3 || (injured < 5 && injured > 0))
                        cout << "This is not available for next week" << endl;
                    else
                    {
                        player p;
                        p.set_name(player_name);
                        std::string role = LOP.get_role(player_name);
                        p.set_role(role);
                        if (UFT.is_position_full(role, login_team_index))
                        {
                            cout << "Bad Request" << endl;
                        }
                        else
                        {
                            UFT.update_player(p, login_team_index, true);
                            if (UFT.users_teams[login_team_index].get_gk_full() && UFT.users_teams[login_team_index].get_df1_full() && UFT.users_teams[login_team_index].get_df2_full() && UFT.users_teams[login_team_index].get_md_full() && UFT.users_teams[login_team_index].get_fw_full())
                            {
                                UFT.users_teams[login_team_index].set_team_completed(true);
                            }

                            cout << "OK" << endl;
                        }
                    }
                }
            }
        }
    }


void CommandHandler::close_transfer_window()
{
    if (this->get_register_status())
    {
        this->set_transfer_window(false);
        cout << "OK" << endl;
    }
    else
        cout << "Admin is not loged in!" << endl;
}

void CommandHandler::open_transfer_window()
{
    if (this->get_register_status())
    {
        this->set_transfer_window(true);
        cout << "OK" << endl;
    }
    else
        cout << "Admin is not loged in!" << endl;
}

vector<string> CommandHandler::split(std::string line, char delimiter)
{
    stringstream stream(line);
    std::vector<std::string> out_list;
    std::string block;
    while (getline(stream, block, delimiter))
    {
        out_list.push_back(block);
    }
    return out_list;
}

void CommandHandler::read_csv_premier_league()
{
    std::string line;
    std::fstream fin;
    fin.open(CSV_PREMIER_LEAGUE, ios::in);
    std::vector<std::vector<std::string>> table;
    getline(fin, line);
    while (getline(fin, line))
    {
        table.push_back(split(line, CSV_DELIMITER1));
    }

    for (long unsigned int i = 0; i < table.size(); i++)
    {
        league_team lt;
        for (long unsigned int j = 0; j < table[i].size(); j++)
        {
            std::vector<std::string> temp = split(table[i][j], CSV_DELIMITER2);
            if (j == 0) // team
            {
                lt.set_team_name(table[i][j]);
            }
            for (long unsigned int k = 0; k < temp.size(); k++)
            {

                if (j == 1) // gk
                {
                    LOP.add_player(temp[k], "GK");
                    lt.add_player(temp[k], "gk");
                }

                else if (j == 2) // df
                {
                    LOP.add_player(temp[k], "DF");
                    lt.add_player(temp[k], "df");
                }

                else if (j == 3) // md
                {
                    LOP.add_player(temp[k], "MD");
                    lt.add_player(temp[k], "md");
                }

                else if (j == 4) // fw
                {
                    LOP.add_player(temp[k], "FW");
                    lt.add_player(temp[k], "fw");
                }
            }
        }
        league_teams.push_back(lt);
    }
}

void CommandHandler::read_csv_week(string week)
{
    std::string line;
    std::fstream fin;
    fin.open(week, ios::in);
    player_week_info w_info;
    std::vector<std::vector<std::string>> table;
    getline(fin, line);
    while (getline(fin, line))
    {
        table.push_back(split(line, CSV_DELIMITER1));
    }

    for (long unsigned int i = 0; i < table.size(); i++)
    {

        for (long unsigned int j = 0; j < table[i].size(); j++)
        {
            std::vector<std::string> temp = split(table[i][j], CSV_DELIMITER2);
            for (long unsigned int k = 0; k < temp.size(); k++)
            {

                if (j == 0) // matches team
                    w_info.add_matches_team(temp[k]);
                else if (j == 1) // result
                    w_info.add_matches_result(temp[k]);
                else if (j == 2) // injured
                    w_info.add_injured_player(temp[k]);
                else if (j == 3) // yellow_card
                    w_info.add_yellow_card_player(temp[k]);
                else if (j == 4) // red_card
                    w_info.add_red_card_player(temp[k]);
                else if (j == 5) // scores
                    w_info.add_player_score(temp[k]);
            }
        }
    }
    PWI.push_back(w_info);
}

void CommandHandler::squad(std::string input)
{
    const int QUESTION_MARK = 2;
    const int FANTASY_TEAM_KEYWORD = 3;
    const int FANTASY_TEAM = 4;

    std::vector<std::string> tokenized_input = tokenizeInput(input);

    int size = tokenized_input.size();
    if (size < 3)
        cout << "Bad Request" << endl;
    else if (size == 3)
    {
        int login_team_index = UFT.get_active_team_name_index();
        if (login_team_index == -1)
        {
            cout << "Not Found" << endl;
        }
        else
        {
            football_team ft = UFT.users_teams[login_team_index];

            if (!ft.get_gk_full() || !ft.get_df1_full() || !ft.get_df2_full() || !ft.get_md_full() || !ft.get_fw_full())
                cout << "Empty" << endl;
            else
                ft.print_team_info();
        }
    }

    else if (tokenized_input[FANTASY_TEAM_KEYWORD] != "fantasy_team" || tokenized_input[QUESTION_MARK] != "?")
        cout << "Bad Request" << endl;
    else if (size == 5)
    {
        string team_name = tokenized_input[FANTASY_TEAM];
        int index = UFT.team_name_index(team_name);
        if (index == -1)
        {
            cout << "Not Found" << endl;
        }
        else
        {
            football_team ft = UFT.users_teams[index];

            if (!ft.get_gk_full() || !ft.get_df1_full() || !ft.get_df2_full() || !ft.get_md_full() || !ft.get_fw_full())
                cout << "Empty" << endl;
            else
                ft.print_team_info();
        }
    }
    else
        cout << "Bad Request" << endl;
}

void CommandHandler::pass_week()
{
    int x = this->get_week_number();
    std::string csv_path = "data/weeks_stats/week_" + to_string(x + 1) + ".csv";
    read_csv_week(csv_path);
    if (this->get_register_status())
    {
        this->update_UFT();
        this->save_week();
	this->inc_week_number();
        this->update_league_teams(this->get_week_number());
        this->update_league_standing();
        cout << "OK" << endl;
    }
    else
        cout << "Admin is not logged in!" << endl;
}

void CommandHandler::save_week()
{
    team_week tw;
    std::vector<team_week> tow;
    for (long unsigned int i = 0; i < UFT.users_teams.size(); i++)
    {
        tw.set_gk(UFT.users_teams[i].get_gk().get_name(), UFT.users_teams[i].get_gk().get_score());
        tw.set_df1(UFT.users_teams[i].get_df1().get_name(), UFT.users_teams[i].get_df1().get_score());
        tw.set_df2(UFT.users_teams[i].get_df2().get_name(), UFT.users_teams[i].get_df2().get_score());
        tw.set_md(UFT.users_teams[i].get_md().get_name(), UFT.users_teams[i].get_md().get_score());
        tw.set_fw(UFT.users_teams[i].get_fw().get_name(), UFT.users_teams[i].get_fw().get_score());
        tow.push_back(tw);
    }
    teams_weeks.push_back(tow);
}

float CommandHandler::get_player_score(std::string player_name, int week_number)
{
    player_week_info t = PWI[week_number - 1];

    std::vector<std::string> player_score = t.get_player_score();
    for (long unsigned int i = 0; i < player_score.size(); i++)
    {
        std::vector<std::string> ps = split(player_score[i], CSV_DELIMITER3);
        if (ps[0] == player_name)
        {
            return stof(ps[1]);
        }
    }
    return 0;
}

void CommandHandler::update_UFT()
{

    for (long unsigned int i = 0; i < UFT.users_teams.size(); i++)
    {
        player p = UFT.users_teams[i].get_gk();

        int x = this->get_injured(p.get_name(), this->get_week_number());
        int y = this->get_yellow_card(p.get_name(), this->get_week_number());
        bool z = this->get_red_card(p.get_name(), this->get_week_number());
        float f = this->get_score(p.get_name(), this->get_week_number());
        if (x > 0 || y == 3 || z)
        {
            UFT.users_teams[i].set_gk_full(false);
        }
        else
        {
            p.set_injured(x);
            p.set_yellow_card(y);
            p.set_red_card(z);
            p.set_score(f);
            UFT.users_teams[i].set_gk(p);
        }

        p = UFT.users_teams[i].get_df1();

        x = this->get_injured(p.get_name(), this->get_week_number());
        y = this->get_yellow_card(p.get_name(), this->get_week_number());
        z = this->get_red_card(p.get_name(), this->get_week_number());
        f = this->get_score(p.get_name(), this->get_week_number());
        if (x > 0 || y == 3 || z)
        {
            UFT.users_teams[i].set_df1_full(false);
        }
        else
        {

            p.set_injured(x);
            p.set_yellow_card(y);
            p.set_red_card(z);
            p.set_score(f);
            UFT.users_teams[i].set_df1(p);
        }

        p = UFT.users_teams[i].get_df2();

        x = this->get_injured(p.get_name(), this->get_week_number());
        y = this->get_yellow_card(p.get_name(), this->get_week_number());
        z = this->get_red_card(p.get_name(), this->get_week_number());
        f = this->get_score(p.get_name(), this->get_week_number());
        if (x > 0 || y == 3 || z)
        {
            UFT.users_teams[i].set_df2_full(false);
        }
        else
        {
            p.set_injured(x);
            p.set_yellow_card(y);
            p.set_red_card(z);
            p.set_score(f);
            UFT.users_teams[i].set_df2(p);
        }

        p = UFT.users_teams[i].get_md();

        x = this->get_injured(p.get_name(), this->get_week_number());
        y = this->get_yellow_card(p.get_name(), this->get_week_number());
        z = this->get_red_card(p.get_name(), this->get_week_number());
        f = this->get_score(p.get_name(), this->get_week_number());
        if (x > 0 || y == 3 || z)
        {
            UFT.users_teams[i].set_md_full(false);
        }
        else
        {
            p.set_injured(x);
            p.set_yellow_card(y);
            p.set_red_card(z);
            p.set_score(f);
            UFT.users_teams[i].set_md(p);
        }

        p = UFT.users_teams[i].get_fw();

        x = this->get_injured(p.get_name(), this->get_week_number());
        y = this->get_yellow_card(p.get_name(), this->get_week_number());
        z = this->get_red_card(p.get_name(), this->get_week_number());
        f = this->get_score(p.get_name(), this->get_week_number());
        if (x > 0 || y == 3 || z)
        {
            UFT.users_teams[i].set_fw_full(false);
        }
        else
        {
            p.set_injured(x);
            p.set_yellow_card(y);
            p.set_red_card(z);
            p.set_score(f);
            UFT.users_teams[i].set_fw(p);
        }

        if (UFT.users_teams[i].get_gk_full() && UFT.users_teams[i].get_df1_full() && UFT.users_teams[i].get_df2_full() && UFT.users_teams[i].get_md_full() && UFT.users_teams[i].get_fw_full())
        {
            UFT.users_teams[i].set_team_completed(true);
            float pre_points = 0;
            if (get_week_number() > 1)
            {
                pre_points = UFT.users_teams[i].get_points();
            }
            float point = UFT.users_teams[i].get_gk().get_score() + UFT.users_teams[i].get_df1().get_score() + UFT.users_teams[i].get_df2().get_score() + UFT.users_teams[i].get_md().get_score() + UFT.users_teams[i].get_fw().get_score();
            UFT.users_teams[i].set_points(point + pre_points);
        }
    }
}

void CommandHandler::team_of_the_week(string input)
{
    const int QUESTION_MARK = 2;
    const int WEEK_NUM_KEYWORD = 3;
    const int WEEK_NUM = 4;

    std::vector<std::string> tokenized_input = tokenizeInput(input);

    int size = tokenized_input.size();
    int week_number = 0;
    if (size < 3)
        cout << "Bad Request" << endl;
    else if (size == 3)
    {
        float gk, df1, df2, md, fw;
        string gk_name, df1_name, df2_name, md_name, fw_name;
        for (long unsigned int i = 0; i < UFT.users_teams.size(); i++)
        {
            if (i == 0)
            {
                gk = UFT.users_teams[i].get_gk().get_score();
                gk_name = UFT.users_teams[i].get_gk().get_name();
                df1 = UFT.users_teams[i].get_df1().get_score();
                df1_name = UFT.users_teams[i].get_df1().get_name();
                df2 = UFT.users_teams[i].get_df2().get_score();
                df2_name = UFT.users_teams[i].get_df2().get_name();
                md = UFT.users_teams[i].get_md().get_score();
                md_name = UFT.users_teams[i].get_md().get_name();
                fw = UFT.users_teams[i].get_fw().get_score();
                fw_name = UFT.users_teams[i].get_fw().get_name();
            }
            else
            {
                if (UFT.users_teams[i].get_gk().get_score() > gk)
                {
                    gk = UFT.users_teams[i].get_gk().get_score();
                    gk_name = UFT.users_teams[i].get_gk().get_name();
                }
                if (UFT.users_teams[i].get_df1().get_score() > df1)
                {
                    df1 = UFT.users_teams[i].get_df1().get_score();
                    df1_name = UFT.users_teams[i].get_df1().get_name();
                }

                if (UFT.users_teams[i].get_df2().get_score() > df2)
                {
                    df2 = UFT.users_teams[i].get_df2().get_score();
                    df2_name = UFT.users_teams[i].get_df2().get_name();
                }

                if (UFT.users_teams[i].get_md().get_score() > md)
                {
                    md = UFT.users_teams[i].get_md().get_score();
                    md_name = UFT.users_teams[i].get_md().get_name();
                }

                if (UFT.users_teams[i].get_fw().get_score() > fw)
                {
                    fw = UFT.users_teams[i].get_fw().get_score();
                    fw_name = UFT.users_teams[i].get_fw().get_name();
                }
            }
        }
        cout << "team of the week: " << endl;
        cout << "GoalKeeper: " << gk_name << " | "
             << "score: " << gk << endl;
        cout << "Defender1: " << df1_name << " | "
             << "score: " << df1 << endl;
        cout << "Defender2: " << df2_name << " | "
             << "score: " << df2 << endl;
        cout << "Midfielder: " << md_name << " | "
             << "score: " << md << endl;
        cout << "Forward: " << fw_name << " | "
             << "score: " << fw << endl;
    }

    else if (tokenized_input[WEEK_NUM_KEYWORD] != "week_num" || tokenized_input[QUESTION_MARK] != "?")
        cout << "Bad Request" << endl;
    else if (size == 5)
    {
        string wn = tokenized_input[WEEK_NUM];
        week_number = stoi(wn);

        float gk, df1, df2, md, fw;
        std::string gk_name, df1_name, df2_name, md_name, fw_name;
        for (long unsigned int i = 0; i < teams_weeks[week_number - 1].size(); i++)
        {
            if (i == 0)
            {
                gk = teams_weeks[week_number - 1][i].get_gk_score();
                gk_name = teams_weeks[week_number - 1][i].get_gk_name();
                df1 = teams_weeks[week_number - 1][i].get_df1_score();
                df1_name = teams_weeks[week_number - 1][i].get_df1_name();
                df2 = teams_weeks[week_number - 1][i].get_df2_score();
                df2_name = teams_weeks[week_number - 1][i].get_df2_name();
                md = teams_weeks[week_number - 1][i].get_md_score();
                md_name = teams_weeks[week_number - 1][i].get_md_name();
                fw = teams_weeks[week_number - 1][i].get_fw_score();
                fw_name = teams_weeks[week_number - 1][i].get_fw_name();
            }
            else
            {
                if (teams_weeks[week_number - 1][i].get_gk_score() > gk)
                {
                    gk = teams_weeks[week_number - 1][i].get_gk_score();
                    gk_name = teams_weeks[week_number - 1][i].get_gk_name();
                }
                if (teams_weeks[week_number - 1][i].get_df1_score() > df1)
                {
                    df1 = teams_weeks[week_number - 1][i].get_df1_score();
                    df1_name = teams_weeks[week_number - 1][i].get_df1_name();
                }

                if (teams_weeks[week_number - 1][i].get_df2_score() > df2)
                {
                    df2 = teams_weeks[week_number - 1][i].get_df2_score();
                    df2_name = teams_weeks[week_number - 1][i].get_df2_name();
                }

                if (teams_weeks[week_number - 1][i].get_md_score() > md)
                {
                    md = teams_weeks[week_number - 1][i].get_md_score();
                    md_name = teams_weeks[week_number - 1][i].get_md_name();
                }

                if (teams_weeks[week_number - 1][i].get_fw_score() > fw)
                {
                    fw = teams_weeks[week_number - 1][i].get_fw_score();
                    fw_name = teams_weeks[week_number - 1][i].get_fw_name();
                }
            }
        }
        cout << "team of the week: " << endl;
        cout << "GoalKeeper: " << gk_name << " | "
             << "score: " << gk << endl;
        cout << "Defender1: " << df1_name << " | "
             << "score: " << df1 << endl;
        cout << "Defender2: " << df2_name << " | "
             << "score: " << df2 << endl;
        cout << "Midfielder: " << md_name << " | "
             << "score: " << md << endl;
        cout << "Forward: " << fw_name << " | "
             << "score: " << fw << endl;
    }
    else
        cout << "Bad Request" << endl;
}

bool CommandHandler::find_yellow_card_player(std::string name, int week_number)
{
    player_week_info t = PWI[week_number - 1];

    std::vector<std::string> yel = t.get_yellow_card_player();
    for (long unsigned int i = 0; i < yel.size(); i++)
    {
        if (yel[i] == name)
        {
            return true;
        }
    }
    return false;
}

bool CommandHandler::find_injured_player(std::string name, int week_number)
{
    player_week_info t = PWI[week_number - 1];

    std::vector<std::string> inj = t.get_injured_player();
    for (long unsigned int i = 0; i < inj.size(); i++)
    {
        if (inj[i] == name)
        {
            return true;
        }
    }
    return false;
}

bool CommandHandler::find_red_card_player(std::string name, int week_number)
{
    player_week_info t = PWI[week_number - 1];

    std::vector<std::string> red = t.get_red_card_player();
    for (long unsigned int i = 0; i < red.size(); i++)
    {
        if (red[i] == name)
        {
            return true;
        }
    }
    return false;
}

void CommandHandler::update_league_teams(int week_number)
{
    for (long unsigned int i = 0; i < league_teams.size(); i++)
        for (long unsigned int j = 0; j < (*league_teams[i].get_players()).size(); j++)
        {
            std::vector<player> p = (*league_teams[i].get_players());

            (*(league_teams[i].get_players()))[j].set_red_card(false);

            if (find_red_card_player(p[j].get_name(), week_number))
            {
                (*(league_teams[i].get_players()))[j].set_red_card(true);
            }
            int x = (*(league_teams[i].get_players()))[j].get_yellow_card();
            if (find_yellow_card_player(p[j].get_name(), week_number))
            {
                (*(league_teams[i].get_players()))[j].set_yellow_card(x + 1);
            }
            else if (x == 3)
            {
                (*(league_teams[i].get_players()))[j].set_yellow_card(0);
            }

            int y = (*(league_teams[i].get_players()))[j].get_injured();
            if (find_injured_player(p[j].get_name(), week_number))
            {
                (*(league_teams[i].get_players()))[j].set_injured(1);
            }
            else if (y > 0 && y < 4)
            {
                (*(league_teams[i].get_players()))[j].set_injured(y + 1);
            }
            else if (y == 4)
                (*(league_teams[i].get_players()))[j].set_injured(0);

            (*(league_teams[i].get_players()))[j].set_score(get_player_score(p[j].get_name(), week_number));
        }
}

bool CommandHandler::team_is_found(std::string team_name)
{
    for (long unsigned int i = 0; i < league_teams.size(); i++)
        if (league_teams[i].get_team_name() == team_name)
            return true;
    return false;
}

struct player_score
{
    bool operator()(player &m1, player &m2) const
    {
        if (m1.get_score() > m2.get_score())
            return true;
        else if (m1.get_score() < m2.get_score())
            return false;
        else
        {
            if (m1.get_name() < m2.get_name())
                return true;
            else
                return false;
        }
    }
};

void CommandHandler::players(std::string input)
{
    const int QUESTION_MARK = 2;
    const int TEAM_NAME_KEYWORD = 3;
    const int TEAM_NAME = 4;
    const int ROLE = 5;
    const int RANKS = 6;

    std::vector<std::string> tokenized_input = tokenizeInput(input);
    std::string tn1;
    std::string team_name;
    std::string role;
    std::string ranks;
    int counter = 1;

    int size = tokenized_input.size();
     if (size < 5)
         cout << "Bad Request" << endl;
    else if (tokenized_input[TEAM_NAME_KEYWORD] != "team_name" || tokenized_input[QUESTION_MARK] != "?")
        cout << "Bad Request" << endl;
    else
    {
       
       

            if (size == 5)
            {

                tn1 = tokenized_input[TEAM_NAME];
                std::vector<std::string> tn2 = split(tn1, CSV_DELIMITER4);
                if (tn2.size() == 3)
                    team_name = tn2[0] + " " + tn2[1] + " " + tn2[2];
                else if (tn2.size() == 2)
                    team_name = tn2[0] + " " + tn2[1];
                else
                {
                    team_name = tn2[0];
                }
                if (team_is_found(team_name))
                {
                    cout << "list of players:" << endl;
                    for (long unsigned int i = 0; i < league_teams.size(); i++)
                    {
                        if (league_teams[i].get_team_name() == team_name)
                        {
                            for (long unsigned int j = 0; j < (*league_teams[i].get_players()).size(); j++)
                            {
                                std::vector<player> p = (*league_teams[i].get_players());

                                cout << counter << ". name: " << p[j].get_name() << " | role: " << p[j].get_role() << " | score: " << p[j].get_score() << endl;
                                counter++;
                            }

                            break;
                        }
                    }
                }
                else
                    cout << "Not Found" << endl;
            }
            else if (size == 6)
            {
                if (!(tokenized_input[ROLE] == "gk" || tokenized_input[ROLE] == "df" || tokenized_input[ROLE] == "md" || tokenized_input[ROLE] == "fw"))
                    if (tokenized_input[ROLE] == "ranks")
                    {
                        tn1 = tokenized_input[TEAM_NAME];
                        ranks = tokenized_input[ROLE];
                        std::vector<std::string> tn2 = split(tn1, CSV_DELIMITER4);
                        if (tn2.size() == 3)
                            team_name = tn2[0] + " " + tn2[1] + " " + tn2[2];
                        else if (tn2.size() == 2)
                            team_name = tn2[0] + " " + tn2[1];
                        else
                        {
                            team_name = tn2[0];
                        }
                        if (team_is_found(team_name))
                        {
                            cout << "list of players:" << endl;

                            for (long unsigned int i = 0; i < league_teams.size(); i++)
                            {
                                if (league_teams[i].get_team_name() == team_name)
                                {
                                    sort((*(league_teams[i].get_players())).begin(), (*(league_teams[i].get_players())).end(), player_score());

                                    for (long unsigned int j = 0; j < (*league_teams[i].get_players()).size(); j++)
                                    {
                                        std::vector<player> p = (*league_teams[i].get_players());

                                        cout << counter << ". name: " << p[j].get_name() << " | role: " << p[j].get_role() << " | score: " << p[j].get_score() << endl;
                                        counter++;
                                    }
                                }
                            }
                        }
                        else
                            cout << "Not Found" << endl;
                    }
                    else
                    {
                        cout << "Bad Request" << endl;
                    }

                else
                {
                    tn1 = tokenized_input[TEAM_NAME];
                    role = tokenized_input[ROLE];
                    std::vector<std::string> tn2 = split(tn1, CSV_DELIMITER4);
                    if (tn2.size() == 3)
                        team_name = tn2[0] + " " + tn2[1] + " " + tn2[2];
                    else if (tn2.size() == 2)
                        team_name = tn2[0] + " " + tn2[1];
                    else
                    {
                        team_name = tn2[0];
                    }
                    if (team_is_found(team_name))
                    {
                        cout << "list of players:" << endl;
                        for (long unsigned int i = 0; i < league_teams.size(); i++)
                        {
                            if (league_teams[i].get_team_name() == team_name)
                            {
                                for (long unsigned int j = 0; j < (*league_teams[i].get_players()).size(); j++)
                                {
                                    std::vector<player> p = (*league_teams[i].get_players());
                                    if (p[j].get_role() == role)
                                    {
                                        cout << counter << ". name: " << p[j].get_name() << " | role: " << p[j].get_role() << " | score: " << p[j].get_score() << endl;
                                        counter++;
                                    }
                                }
                                break;
                            }
                        }
                    }
                    else
                        cout << "Not Found" << endl;
                }
            }
            else if (size == 7)
            {
                if (tokenized_input[RANKS] != "ranks" || !(tokenized_input[ROLE] == "gk" || tokenized_input[ROLE] == "df" || tokenized_input[ROLE] == "md" || tokenized_input[ROLE] == "fw"))
                    cout << "Bad Request" << endl;
                else
                {
                    tn1 = tokenized_input[TEAM_NAME];
                    role = tokenized_input[ROLE];
                    ranks = tokenized_input[RANKS];
                    std::vector<std::string> tn2 = split(tn1, CSV_DELIMITER4);
                    if (tn2.size() == 3)
                        team_name = tn2[0] + " " + tn2[1] + " " + tn2[2];
                    else if (tn2.size() == 2)
                        team_name = tn2[0] + " " + tn2[1];
                    else
                    {
                        team_name = tn2[0];
                    }
                    if (team_is_found(team_name))
                    {
                        cout << "list of players:" << endl;
                        for (long unsigned int i = 0; i < league_teams.size(); i++)
                        {
                            if (league_teams[i].get_team_name() == team_name)
                            {
                                sort((*(league_teams[i].get_players())).begin(), (*(league_teams[i].get_players())).end(), player_score());

                                for (long unsigned int j = 0; j < (*league_teams[i].get_players()).size(); j++)
                                {
                                    std::vector<player> p = (*league_teams[i].get_players());
                                    if (p[j].get_role() == role)
                                    {
                                        cout << counter << ". name: " << p[j].get_name() << " | role: " << p[j].get_role() << " | score: " << p[j].get_score() << endl;
                                        counter++;
                                    }
                                }
                            }
                        }
                    }
                    else
                        cout << "Not Found" << endl;
                }
            }
            else
                cout << "Bad Request" << endl;
        }
    
}

struct team_standing
{
    bool operator()(team_info &m1, team_info &m2) const
    {
        if (m1.get_team_score() > m2.get_team_score())
        {
            return true;
        }
        else
        {
            if (m1.get_team_score() == m2.get_team_score())
            {
                int gf_ga1 = m1.get_gf() - m1.get_ga();
                int gf_ga2 = m2.get_gf() - m2.get_ga();
                if (gf_ga1 > gf_ga2)
                {
                    return true;
                }
                else
                {
                    if (gf_ga1 == gf_ga2)
                    {
                        if (m1.get_gf() > m2.get_gf())
                        {
                            return true;
                        }
                        else
                        {
                            if (m1.get_gf() == m2.get_gf())
                            {
                                if (m1.get_team_name() < m2.get_team_name())
                                {
                                    return true;
                                }
                                else
                                    return false;
                            }
                            else
                                return false;
                        }
                    }
                    else
                        return false;
                }
            }
            else
                return false;
        }
    }
};

void CommandHandler::league_standing_first_week()
{
    for (long unsigned int i = 0; i < PWI[0].get_matches_result().size(); i++)
    {
        std::string matches_result = PWI[0].get_matches_result()[i];
        std::string matches_team = PWI[0].get_matches_team()[i];
        std::vector<std::string> mr = split(matches_result, CSV_DELIMITER3);
        std::vector<std::string> mt = split(matches_team, CSV_DELIMITER3);
        team_info ti0, ti1;
        ti0.set_team_name(mt[0]);
        ti0.set_gf(stoi(mr[0]));
        ti0.set_ga(stoi(mr[1]));

        ti1.set_team_name(mt[1]);
        ti1.set_gf(stoi(mr[1]));
        ti1.set_ga(stoi(mr[0]));

        if (stoi(mr[0]) == stoi(mr[1]))
        {
            ti0.set_team_score(1);
            ti1.set_team_score(1);
        }
        else if (stoi(mr[0]) > stoi(mr[1]))
        {
            ti0.set_team_score(3);
            ti1.set_team_score(0);
        }
        else
        {
            ti0.set_team_score(0);
            ti1.set_team_score(3);
        }
        LS.league_standing_info.push_back(ti0);
        LS.league_standing_info.push_back(ti1);
    }
    sort(LS.league_standing_info.begin(), LS.league_standing_info.end(), team_standing());
}

void CommandHandler::update_league_standing()
{
    int week_number = this->get_week_number();
    for (long unsigned int i = 0; i < PWI[week_number - 1].get_matches_result().size(); i++)
    {
        std::string matches_result = PWI[week_number - 1].get_matches_result()[i];
        std::string matches_team = PWI[week_number - 1].get_matches_team()[i];
        std::vector<std::string> mr = split(matches_result, CSV_DELIMITER3);
        std::vector<std::string> mt = split(matches_team, CSV_DELIMITER3);
        int index1 = LS.find_team_name_index(mt[0]);
        int score1 = LS.get_team_score(index1);
        int gf1 = LS.get_gf(index1);
        int ga1 = LS.get_ga(index1);
        int index2 = LS.find_team_name_index(mt[1]);
        int score2 = LS.get_team_score(index2);
        int gf2 = LS.get_gf(index2);
        int ga2 = LS.get_ga(index2);
        LS.set_num_goals_for(gf1 + stoi(mr[0]), index1);
        LS.set_num_goals_against(ga1 + stoi(mr[1]), index1);
        LS.set_num_goals_for(gf2 + stoi(mr[1]), index2);
        LS.set_num_goals_against(ga2 + stoi(mr[0]), index2);

        if (stoi(mr[0]) == stoi(mr[1]))
        {
            LS.set_team_score(score1 + 1, index1);
            LS.set_team_score(score2 + 1, index2);
        }
        else if (stoi(mr[0]) > stoi(mr[1]))
        {
            LS.set_team_score(score1 + 3, index1);
        }
        else
        {
            LS.set_team_score(score2 + 3, index2);
        }
    }
    sort(LS.league_standing_info.begin(), LS.league_standing_info.end(), team_standing());
}

void CommandHandler::league_stand()
{

    cout << "league standings: " << endl;
    int counter = 1;
    for (long unsigned int i = 0; i < LS.league_standing_info.size(); i++)
    {
        cout << counter << "." << LS.league_standing_info[i].get_team_name() << ": score: " << LS.league_standing_info[i].get_team_score() << " | GF: " << LS.league_standing_info[i].get_gf() << " | GA: " << LS.league_standing_info[i].get_ga() << endl;
        counter++;
    }
}

struct football_team_points
{
    bool operator()( football_team &m1, football_team &m2) const
    {
        return m1.get_points() > m2.get_points();
    }
};

void CommandHandler::users_ranking()
{
    sort(UFT.users_teams.begin(), UFT.users_teams.end(), football_team_points());
    std::string team_name;
    for (long unsigned int i = 0; i < UFT.users_teams.size(); i++)
    {
        cout << i + 1 << ". team_name: " << UFT.users_teams[i].get_team_name() << " | "
             << "point: " << UFT.users_teams[i].get_points() << endl;
    }
}

void CommandHandler::matches_result_league(string input)
{
    const int QUESTION_MARK = 2;
    const int WEEK_NUM_KEYWORD = 3;
    const int WEEK_NUM = 4;

    std::vector<std::string> tokenized_input = tokenizeInput(input);

    int size = tokenized_input.size();
    int week_number = 0;
    if (size < 3)
        cout << "Bad Request" << endl;
    else if (size == 3)
    {
        week_number = this->get_week_number();
        for (long unsigned int i = 0; i < PWI[week_number - 1].get_matches_result().size(); i++)
        {
            std::string matches_result = PWI[week_number - 1].get_matches_result()[i];
            std::string matches_team = PWI[week_number - 1].get_matches_team()[i];
            std::vector<std::string> mr = split(matches_result, CSV_DELIMITER3);
            std::vector<std::string> mt = split(matches_team, CSV_DELIMITER3);
            cout << mt[0] << " " << mr[0] << " | " << mt[1] << " " << mr[1] << endl;
        }
    }
    else if (tokenized_input[WEEK_NUM_KEYWORD] != "week_num" || tokenized_input[QUESTION_MARK] != "?")
        cout << "Bad Request" << endl;
    else if (size == 5)
    {
        std::string wn = tokenized_input[WEEK_NUM];
        week_number = stoi(wn);
        if (week_number > this->get_week_number() || week_number < 0)
            cout << "Not Found" << endl;
        else
        {
            for (long unsigned int i = 0; i < PWI[week_number - 1].get_matches_result().size(); i++)
            {
                std::string matches_result = PWI[week_number - 1].get_matches_result()[i];
                std::string matches_team = PWI[week_number - 1].get_matches_team()[i];
                std::vector<std::string> mr = split(matches_result, CSV_DELIMITER3);
                std::vector<std::string> mt = split(matches_team, CSV_DELIMITER3);
                cout << mt[0] << " " << mr[0] << " | " << mt[1] << " " << mr[1] << endl;
            }
        }
    }
    else
        cout << "Bad Request" << endl;
}
