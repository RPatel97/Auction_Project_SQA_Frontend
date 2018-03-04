#include<iostream>
#include<fstream>
#include<string>
#include "Users.hpp"
#include "Login.hpp"
#include "addCredit.hpp"
#include "mainMenu.hpp"

bool addCredit::credit_success;
std::string addCredit::username;
int addCredit::changed_credit;

void addCredit::add_credit(){
    std::string line;
    mainMenu menu;
    User admin_user;
    User user;
    int user_credits, admin_credits, new_user_credits, new_admin_credits;
    bool credit_transfer_check = false;

    for (User a : Users::GetUsers()){
        if (Login::username == a.username){
            admin_user = a;
        }
    }
        
    if (admin_user.roles == "AD"){
        std::cout << "Please enter a username" << "\n";
        std::cin >> username;

        std::ifstream users;
        users.open("currentaccounts.txt");

        std::ofstream temp;
        temp.open("temp.txt");

        for (User u : Users::GetUsers()){
            if (username == u.username)
            {
                user = u;
            }
        }

        //supposed to look for everything other than user and admin
        while (getline(users, line))
        {
            if (line.substr(0, admin_user.username.size()) == admin_user.username || line.substr(0, username.size()) == user.username)
            {
                continue;
            }
            
            temp << line << "\n";
        }
        
        users.close();
        temp.close();

        while (credit_transfer_check == false){
            
            std::cout << "Please enter how much credit you would like to add" << "\n";
            std::cin >> changed_credit;

            if (changed_credit > 1000){
                std:: cout << "Maximum credit transfer exceeded" << "\n";
            }
            else{
                credit_transfer_check = true;
            }
        }
        
        
       
        new_user_credits = user.credits += changed_credit;
        
        new_admin_credits = admin_user.credits -= changed_credit;

        user.credits = new_user_credits;
        admin_user.credits = new_admin_credits;

        
        std::ofstream update_users;
        update_users.open("temp.txt", std::ios_base::app);

        

        std::cout << "Adding credits..." << "\n";
        update_users << user.username << " " << user.roles << " " << user.credits << "\n"; 
        std::cout << "Subtracting credits..." << "\n";
        update_users << admin_user.username << " " << admin_user.roles << " " << admin_user.credits << "\n";
        
        std::cout << "New credits for Admin are: " << admin_user.credits << " and new credits for user are: " << user.credits << "\n";

        update_users.close();
        remove("currentaccounts.txt");
        rename("temp.txt", "currentaccounts.txt");

        credit_success = true;
        menu.main_menu();
    }
    else
    {
        std::cout << "You do not have access to this feature with your current account role" << "\n";
        menu.main_menu();
    }
}
