#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <list>
#include <iterator>

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
    std::string user_input;
    std::list<std::string> user_inputs;
    std::cout<< "Welcome to the Online Auction System! Please login to Proceed" << "\n";
    std::cin >> user_input;

    //implemented list for tokenization of commands and parameters, for later functionality.
    user_inputs.push_back(user_input);
    std::list<std::string>::iterator command_iter;
    std::string delimiter = " ";
    std::string command = user_input.substr(0, user_input.find(delimiter));
    
    //Code to tokenize commands: commented out for now
    //std::string username = user_input.substr(user_input.find(delimiter + delimiter.size());
    //std::cout << command << username << "\n";

    if (command == "login")
    {
        login();
    }
    else{
        std::cout<<"Not a valid command" << "\n";
    }

}

/*
 *Once login command has been deteced, main redirects here, 
 *reads into user input for username, saves to variable. 
 *compares variable to .txt file for username in database.
 *If found, login success, otherwise session is terminated.
 *Currently, must login as admin01 or user01.
 */

void login()
{
    //initializing variables
    bool found = false;
    int i = 0;
    std::list<std::string> txt;
    std::string saveduser;    
    
    //take in username
    std::string username;
    std::cout << "Please enter your username: " << "\n";
    std::cin >> username;

    //open database
    std::ifstream userLoginFile;
    userLoginFile.open("CurrentUsers.txt");
    
    //read into database
    while (!userLoginFile.eof())
    {
        if(userLoginFile.is_open())
        {
            getline(userLoginFile, saveduser);
            txt.push_back(saveduser);
            i++;
        }
    }
    userLoginFile.close();

    //iterate through database with comparison of username, if true is returned, login success
    std::list<std::string>::iterator iter;
    std::string findString = username;

    for(std::list<std::string>::iterator iter = txt.begin(); iter != txt.end(); iter++)
    {
        if (username == *iter)
        {
            found = true;
            main_menu();
        }
        
    }
    if (found == false)
    {
        std::cout << "Username not found in database" << "\n";
    }
    
}

/*
 *If login successful, redirect to main_menu. 
 *This function has access to all commands except login. 
 *TODO all commands, any command currently input terminates session.
 */

void main_menu()
{

    std::cout<<"Welcome to the main menu. Please enter a command to continue: "
            << "\n";

    typedef enum{
        advertise,
        bid,
        addcredit,
        refund,
        userdelete,
        create,
        logout
    }userCommand;

    int userCommand1;
    std::cin >> userCommand1;
    /*std::string userCommand;
    std::cin >> userCommand;*/

    switch (userCommand1)
    {
        case 1:
            advertise1();
            break;
        case 2:
            bid1();
            break;
        case 3:
            addCredit();
            break;
        case 4:
            refundCredit();
            break;
        case 5:
            delete_user();
            break;
        case 6:
            create_user();
            break;
        case 7:
            logout1();
            break;
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