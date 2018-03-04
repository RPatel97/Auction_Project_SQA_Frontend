#include<iostream>
#include<fstream>
#include "Login.hpp"
#include "Users.hpp"
#include "advertiseItem.hpp"
#include "Logout.hpp"
#include "createUser.hpp"
#include "deleteUser.hpp"
#include "advertiseItem.hpp"
#include "bidItem.hpp"
#include "refundCredit.hpp"
#include "addCredit.hpp"
#include "Items.hpp"

void Logout::logout(){
    User user;
    Item item;
    
    for (User u : Users::GetUsers()){
        if (Login::username == u.username){
            user = u;
        }
    }

    for (Item i : Items::GetItems())
        {
            if (bidItem::item_name == i.item_name && bidItem::seller_name == i.username && bidItem::days_left == i.days_left)
            {
                item = i;
            }
        }
    
    std::ofstream dtf;
    dtf.open("dailyTransactionFile.atf", std::ios_base::app);

    if (Login::loginSuccess == true){
        dtf << "10" << " " << user.username << " " << user.roles << " " << user.credits << "\n";
    }
    
    if (createUser::create_user_success == true){
        dtf << "01" << " " << createUser::username << " " << createUser::user_role << " " << createUser::user_credits << "\n";
    }
    
    if (deleteUser::delete_success == true){
        dtf << "02" << " " << deleteUser::username << " " << createUser::user_role << " " << createUser::user_credits << "\n";
    }
    if (advertiseItem::advertise_success == true){
        dtf << "03" << " " << user.username << " " << user.roles << " " << user.credits << "\n";
    }
    if (bidItem::bid_success == true){
        dtf << "04" << " " << item.item_name << " " << bidItem::seller_name << " " << user.username << " " << bidItem::bid_amount << "\n";
    }
    if (refundCredit::refund_success == true){
         dtf << "05" << " " << refundCredit::refund_username << " " << refundCredit::seller_username << " " << refundCredit::changed_credit << "\n";
    }
    if (addCredit::credit_success == true){
        dtf << "06" << " " << addCredit::username << " " << addCredit::changed_credit << "\n";
    }
    
    dtf << "00" << " " << user.username << " " << user.roles << " " << user.credits << "\n"; 
    dtf.close();
}