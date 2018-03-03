#ifndef Users_H_
#define Users_H_
#include<string>
#include<vector>


class User {
    public:
        std::string username;
        std::string roles;
        double credits;
};

class Users{
    public:
        static std::vector<User> GetUsers();
};

#endif
