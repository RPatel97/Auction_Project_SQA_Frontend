#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <list>
#include <iterator>
#include "Login.hpp"
#include "mainMenu.hpp"

#include "OnlineAuctionSystem.hpp"

/*
 *Generated welcome msg, prompts user to enter command, 
 *reads into command and redirects to appropriate function. 
 *Only login has been coded.
 *Must login to access main menu. Login as admin01.
 *In order to login, type "login" as first command then press enter, when prompted to, enter username as "admin01".
 */

int main()
{
    Login username;

    std::string user_input;
    std::list<std::string> user_inputs;
    std::cout<< "Welcome to the Online Auction System! Please login to Proceed" << "\n";
    std::cin >> user_input;

    //implemented list for tokenization of commands and parameters, for later functionality.
    user_inputs.push_back(user_input);
    std::list<std::string>::iterator command_iter;
    std::string delimiter = " ";
    std::string command = user_input.substr(0, user_input.find(delimiter));
    

    if (command == "login")
    {
        username.login();
    }
    else{
        std::cout<<"Not a valid command" << "\n";
    }

}

/*
 *Below are all the functions that need to be implemented. 
 */
void logout1()
{
    //TODO
}
void create_user()
{
    //TODO
}
void delete_user()
{
    //TODO
}
void addCredit()
{
    //TODO
}
void refundCredit()
{
    //TODO
}
void advertise1()
{
    //TODO
}
void bid1()
{
    //TODO
}