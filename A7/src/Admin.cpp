#include "Admin.hpp"

using namespace std;

admin::admin()
{
    username = "admin";
    password = "123456";
    register_status = false;
    transfer_window = true;
    week_number = 1;
}

std::string admin::get_username_admin()
{
    return username;
}
std::string admin::get_password_admin()
{
    return password;
}
bool admin::get_register_status()
{
    return register_status;
}
bool admin::get_transfer_window()
{
    return transfer_window;
}

int admin::get_week_number()
{
    return week_number;
}
void admin::set_transfer_window(bool tw)
{
    this->transfer_window = tw;
}

void admin::set_register_status(bool rs)
{
    this->register_status = rs;
}

void admin::inc_week_number()
{
    this->week_number++;
}
