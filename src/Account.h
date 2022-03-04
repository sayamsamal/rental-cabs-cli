#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>

class Account 
{
    private:
        unsigned long long id;
        std::string username;
        std::string password;
        unsigned int age;
        double balance;
        bool first_use;
    public:
        void set_username(std::string username_val);
        void set_password(std::string password_val);
        void set_age(unsigned int age_val);
        void set_balance(double balance_val);
        void set_first_use(bool first_use_val);
                
        unsigned long long get_id();
        std::string get_username();
        std::string get_password();
        unsigned int get_age();
        double get_balance();
        bool get_first_use();

        Account(unsigned long long id_val, std::string username_val, std::string password_val = "", unsigned int age_val = 18, double balance_val = 0, bool first_use_val = false);
};

#endif 