#include "Account.h"

Account::Account(unsigned long long id_val, std::string username_val, std::string password_val, unsigned int age_val, double balance_val, bool first_use_val)
    : id{id_val}, username{username_val}, password{password_val}, age{age_val}, balance{balance_val}, first_use{first_use_val}
{

}

void Account::set_username(std::string username_val) {
    username = username_val;
}

void Account::set_password(std::string password_val) {
    password = password_val;
}

void Account::set_age(unsigned int age_val) {
    age = age_val;
}

void Account::set_balance(double balance_val) {
    balance = balance_val;
}

void Account::set_first_use(bool first_use_val) {
    first_use = first_use_val;
}

unsigned long long Account::get_id()
{
    return id;
}

std::string Account::get_username()
{
    return username;
}

std::string Account::get_password()
{
    return password;
}

unsigned int Account::get_age()
{
    return age;
}

double Account::get_balance()
{
    return balance;
}

bool Account::get_first_use()
{
    return false;
}