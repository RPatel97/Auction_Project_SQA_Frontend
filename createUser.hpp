#ifndef createUser_H_
#define createUser_H_
#include<string>

class createUser{
    public:
        void create_user();
        static bool create_user_success;
        static std::string username;
        static std::string user_role;
        static int user_credits;
};

#endif