#include<iostream>
#include<fstream>
#include "Users.hpp"
#include "createUser.hpp"
#include "mainMenu.hpp"
#include "Login.hpp"

bool createUser::create_user_success;
std::string createUser::username;
std::string createUser::user_role;
int createUser::user_credits = 0;

void createUser::create_user(){
    mainMenu menu;
    User user;
    user_credits = 0;

    bool username_check = false;
    //create_user_success = false;

    for (User u : Users::GetUsers()){
        if (Login::username == u.username){
            user = u;
        }
    }
    
    if (user.roles == "AD" ) {
        while (username_check == false)
        {
            std::cout << "Please enter the name of the user" << "\n";
            std::cin >> username;

            if (username.length() > 25){
                std::cout << "Name of user is too long, must be within 25 characters" << "\n";
            }
            else{
                username_check = true;
            } 
        }
        std::cout << "Enter role of user" << "\n";
        std::cin >> user_role;

        std::ofstream userLoginFile;
        userLoginFile.open("currentaccounts.txt", std::ios_base::app);
        userLoginFile << std::endl << username << " " << user_role << " " << user_credits << "\n";
        userLoginFile.close();

        create_user_success = true;

        menu.main_menu();
    }
    else {
        std::cout << "You do not have the authorization for this" << "\n";
        menu.main_menu();
    }
}