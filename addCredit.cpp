#include<iostream>
#include<fstream>
#include<string>
#include "Users.hpp"
#include "Login.hpp"
#include "addCredit.hpp"
#include "mainMenu.hpp"

void addCredit::add_credit(){
    std::string line, username;
    mainMenu menu;
    User admin_user;
    User user;
    int changed_credit, user_credits, admin_credits, new_user_credits, new_admin_credits;

    for (User a : Users::GetUsers()){
        if (Login::username == a.username){
            admin_user = a;
        }
    }
    
    //std::cin >> admin_user.credits;
    
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

        //supposed to look for everything not user
        while (getline(users, line))
        {
            if (line.substr(0, username.size()) != user.username || line.substr(0, username.size()) != admin_user.username)
            {
                temp << line << "\n";
            }
        }
     

        std::cout << "Please enter how much credit you would like to add" << "\n";
        std::cin >> changed_credit;
        
       
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

        menu.main_menu();
    }
    else
    {
        std::cout << "You do not have access to this feature" << "\n";
        menu.main_menu();
    }
}
