#ifndef ADMIN_HPP
#define ADMIN_HPP

#include <iostream>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm>

#include "Util.hpp"



class admin
{
private:
    std::string username;
    std::string password;
    bool register_status;
    bool transfer_window;
    int week_number;

public:
    std::string get_username_admin();
    std::string get_password_admin();
    bool get_transfer_window();
    bool get_register_status();
    int get_week_number();
    void set_transfer_window(bool tw);
    void set_register_status(bool rs);
    void inc_week_number();
    admin();
};




#endif
