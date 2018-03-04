#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <sstream>
#include <list>
#include <iterator>
#include "mainMenu.hpp" 
#include "advertiseItem.hpp"
#include "bidItem.hpp"
#include "Users.hpp"
#include "Login.hpp"
#include "Items.hpp"

bool bidItem::bid_success;
std::string bidItem::item_name, bidItem::seller_name;
int bidItem::bid_amount, bidItem::days_left;

void bidItem::bid_item(){

    User user;
    Item item;
    mainMenu menu;
    std::string line;
    bool price_threshold_check = false;
    

    for (User a : Users::GetUsers()){
        if (Login::username == a.username){
            user = a;
        }
    }

    if (user.roles == "SS"){
        std::cout << "You do not have access to this feature" << "\n";
    }
    else{
        
        std:: cout << "Please enter the name of the item: ";
        std:: cin >> item_name;

        std:: cout << "Please enter the name of the seller: ";
        std:: cin >> seller_name;

        std:: cout << "Please enter the number of days left on the item: ";
        std:: cin >> days_left;

        for (Item i : Items::GetItems())
        {
            if (item_name == i.item_name && seller_name == i.username && days_left == i.days_left)
            {
                item = i;
            }
        }

        while (price_threshold_check == false)
        {
            std::cout << "Current bid is " << item.price << ". How much would you like to bid?" << "\n";
            std::cin >> bid_amount;

            if(bid_amount <= (item.price * 0.05) + item.price)
            {
                std::cout << "Bid amount must be 5 percent greater than current bid." << "\n";
            }
            else
            {
                item.price = bid_amount;
                price_threshold_check = true;
            }
        }
        
        item.price = bid_amount;

        std::ofstream update_items;
        update_items.open("Items.txt", std::ios_base::app);

        update_items << item.username << " " << item.item_name << " " << item.price << " " << item.days_left << "\n";

        update_items.close();

        std::cout << "Your new bid has been saved" << "\n";

        bid_success = true;
        menu.main_menu();
    }
}