#include<iostream>
#include<fstream>
#include "Login.hpp"
#include "Users.hpp"
#include "advertiseItem.hpp"
#include "Logout.hpp"
#include "createUser.hpp"
#include "deleteUser.hpp"
#include "advertiseItem.hpp"

void Logout::logout(){
    User user;
    
    for (User u : Users::GetUsers()){
        if (Login::username == u.username){
            user = u;
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
    
    dtf << "00" << " " << user.username << " " << user.roles << " " << user.credits << "\n"; 
    dtf.close();
}