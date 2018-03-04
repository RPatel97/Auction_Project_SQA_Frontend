#include<iostream>
#include<fstream>
#include<string>
#include "Users.hpp"
#include "Login.hpp"
#include "refundCredit.hpp"
#include "mainMenu.hpp"

std::string refundCredit::refund_username;
std::string refundCredit::seller_username;
int refundCredit::changed_credit;
bool refundCredit::refund_success;

void refundCredit::refund_credit(){
    std::string line;
    mainMenu menu;
    User sell_user;
    User refund_user;
    User admin_user;
    int buyer_credits, seller_credits;

    for (User a : Users::GetUsers()){
        if (Login::username == a.username){
            admin_user = a;
        }
    }
        
    if (admin_user.roles == "AD"){
        std::cout << "Please enter username to send refund to: ";
        std::cin >> refund_username;

        std::cout << "Please enter seller username: ";
        std::cin >> seller_username;

        std::ifstream users;
        users.open("currentaccounts.txt");

        std::ofstream temp;
        temp.open("temp.txt");

        for (User r : Users::GetUsers()){
            if (refund_username == r.username)
            {
                refund_user = r;
            }
        }

        for (User s : Users::GetUsers()){
            if (seller_username == s.username)
            {
                sell_user = s;
            }
        }

        //supposed to look for everything other than user and admin
        while (getline(users, line))
        {
            if (line.substr(0, refund_username.size()) == refund_user.username || line.substr(0, seller_username.size()) == sell_user.username)
            {
                continue;
            }
            
            temp << line << "\n";
        }
        
        users.close();
        temp.close();

        std::cout << "Please enter how much credit you would like to refund" << "\n";
        std::cin >> changed_credit;
        
       
        buyer_credits = refund_user.credits += changed_credit;
        
        seller_credits = sell_user.credits -= changed_credit;

        refund_user.credits = buyer_credits;
        sell_user.credits = seller_credits;

        
        std::ofstream update_users;
        update_users.open("temp.txt", std::ios_base::app);

        

        std::cout << "Adding credits..." << "\n";
        update_users << refund_user.username << " " << refund_user.roles << " " << refund_user.credits << "\n"; 
        std::cout << "Subtracting credits..." << "\n";
        update_users << sell_user.username << " " << sell_user.roles << " " << sell_user.credits << "\n";
        
        std::cout << "New credits for Seller are: " << sell_user.credits << " and new credits for user are: " << refund_user.credits << "\n";

        update_users.close();
        remove("currentaccounts.txt");
        rename("temp.txt", "currentaccounts.txt");

        refund_success = true;
        menu.main_menu();
    }
    else
    {
        std::cout << "You do not have access to this feature" << "\n";
        menu.main_menu();
    }
}