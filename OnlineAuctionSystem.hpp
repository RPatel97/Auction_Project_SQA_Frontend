#ifndef OnlineAuctionSystem_H_
#define OnlineAuctionSystem_H_


/*
handles user login takes in a string and tokenizes it so it can compare the username to the current users
*/
void login();

/*
will provide users with their specified privileges, this function is only partly implemented
*/
void main_menu();

/*
after the user has logged in and wants to logout this function will allow the user to exit the system
*/
void logout1();


//TODO functions
/*
Admin privilege: will allow creation of users.
*/
void create_user();

/*
Admin privilege: will allow deletion of users.
*/
void delete_user();

/*
Takes in username, user_type and amount_of_credit to add
*/
void addCredit();

/*
Will send request to admin for a refund of a specific item 
*/
void refundCredit();

/*
Admin, full_standard, and sell_standard privilege
Allows specific user_type to advertise an item at a given price
*/
void advertise1();

/*
Admin, full_standard, and buy_standard privilege
Allows specific user_type to bid on a item and a bid value
*/
void bid1();

#endif