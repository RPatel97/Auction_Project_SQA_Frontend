#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include "Users.hpp"


std::vector<User> Users::GetUsers() {
    
    std::vector<User> result;

    //open database
    std::ifstream userLoginFile;
    userLoginFile.open("currentaccounts.txt");

    std::string line;

    //read into database
    while (!userLoginFile.eof())
    {
        getline(userLoginFile, line);
        if (line.empty())
            continue;

        std::stringstream stream(line);
        
        User user;
        
        stream >> user.username;
        stream >> user.roles;
        stream >> user.credits;

        result.push_back(user);
    }
    userLoginFile.close();

    return result;
}