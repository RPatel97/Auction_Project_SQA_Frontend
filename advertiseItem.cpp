#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <list>
#include <iterator>
#include "mainMenu.hpp"
#include "advertiseItem.hpp"
#include "Login.hpp"
#include "Users.hpp"

bool advertiseItem::advertise_success;

void advertiseItem::advertise_item(){

    User user;
    mainMenu menu;

    bool item_name_check = false;
    bool min_bid_check = false;
    bool days_left_check = false;
    
    std::string item_name;
    float min_bid, max_bid, user_bid;
    min_bid = 0;
    max_bid = 999.99;
    int days_left;
    
    for (User u : Users::GetUsers())
    {
        if (Login::username == u.username)
        {
            user = u;
        }
    }

    if (user.roles == "BS"){
        std::cout << "You dont have access to this feature with your current account role" << "\n";
    }
    else 
    {
        while (item_name_check == false){
            std::cout << "Please enter the name of the item" << "\n";
            std::cin >> item_name;

            if (item_name.length() > 25){
                std::cout << "Name of item is too long, must be within 25 characters" << "\n";
            }
            else{
                item_name_check = true;
            }
        }


        while (min_bid_check == false){
            std::cout << "Please enter price of the item" << "\n";
            std::cin >> user_bid;

            if (user_bid < min_bid ){
                std::cout << "Minimum bid price is $0" << "\n";
            }
            else if (user_bid > max_bid){
                std::cout << "Maximum bid price is $999.99" << "\n";
                }
            else{
                min_bid_check = true;
            }
        }

        while (days_left_check == false){
            days_left = 0;
            std::cout << "Please enter the number of days until the auction ends" << "\n";
            std::cin >> days_left;

            if (days_left > 100){
                std::cout << "Maximum Auction time is 100 days" << "\n";
            }
            else{
                days_left_check = true;
            }
        }

        std::ofstream items;
        items.open("Items.txt", std::ios_base::app);
        items << Login::username << " " << item_name << " " << user_bid << " " << days_left << "\n";
        items.close();

        advertise_success = true;

        menu.main_menu();
    }
}