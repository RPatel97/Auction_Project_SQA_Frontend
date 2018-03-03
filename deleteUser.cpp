#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <list>
#include <iterator>
#include "mainMenu.hpp" 
#include "deleteUser.hpp"
#include "Users.hpp"
#include "Login.hpp"

bool deleteUser::delete_success;
std::string deleteUser::username;

void deleteUser::delete_user(){
    std::string line;
    mainMenu menu;
    User user;

    for (User u : Users::GetUsers()){
        if (Login::username == u.username){
            user = u;
        }
    }

    if ( user.roles == "AD"){
        std::cout << "Please enter a username" << "\n";
        std::cin >> username;

        std::ifstream users;
        users.open("currentaccounts.txt");
        
        std::ofstream temp;
        temp.open("temp.txt");
        
        while (getline(users, line))
        {
            if (line.substr(0, username.size()) != username)
            temp << line << "\n";
        }
        
        std::cout << "The record with the name " << username << " has been deleted if it exsisted" << "\n";
        
        users.close();
        temp.close();
        remove("currentaccounts.txt");
        rename("temp.txt", "currentaccounts.txt");

        delete_success = true;
        menu.main_menu();
    }
    else
    {
        std::cout << "You do not have access to this feature" << "\n";
        menu.main_menu();
    }
}