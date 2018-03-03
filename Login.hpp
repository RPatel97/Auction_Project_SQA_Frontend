#ifndef Login_H_
#define Login_H_
#include <string>

class Login{
    public:
        void login();
        static bool loginSuccess;
        static std::string username;
};

#endif