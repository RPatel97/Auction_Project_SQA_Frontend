#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include "Login.hpp"
#include "mainMenu.hpp"
#include "Users.hpp"

/*
 *Once login command has been deteced, main redirects here, 
 *reads into user input for username, saves to variable. 
 *compares variable to .txt file for username in database.
 *If found, login success, otherwise session is terminated.
 *Currently, must login as admin01 or user01.
 */

std::string Login::username;
bool Login::loginSuccess; 

void Login::login()
{
    mainMenu menu;
    User user;

    //initializing variables
    bool found = false;
    //int i = 0;
    //std::list<std::string> txt;
    //std::string saveduser;    
    
    //take in username
    std::cout << "Please enter your username: " << "\n";
    std::cin >> username;    
    
    for (User user : Users::GetUsers()){
        if (username == user.username){
            found = true;
        }
    }
    
    if (found == true)
    {  
        loginSuccess = true;
        menu.main_menu();
    }
    else
    {
        std::cout << "Username not found in database" << "\n";
    }

}