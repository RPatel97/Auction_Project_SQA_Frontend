#include <fstream>
#include <iostream>
#include <limits>
#include <string>

template <typename T>
T get_input(const std::string &strQuery);

void login();
void login_menu();
void main_menu();
void logout();

//TODO
void create_user();
void delete_user();
void add_credit();
void refund_credit();
void advertise();
void bid();

int main()
{
    login_menu();
}

// Continious input for user is in the system
template <typename T>
T get_input(const std::string &strQuery)
{
    std::cout << strQuery << "\n> ";
    T out = T();

    while (!(std::cin >> out)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits <std::streamsize>::max(), '\n');
        std::cout << "Error!" "\n";
        std::cout << strQuery << "\n> ";
    }

    return out;
}

void login()
{
    std::string username;
    std::cout << "Please enter your username: " << "\n";
    std::cin >> username;

    std::ifstream userLoginFile;
    std::string regd_username;

    userLoginFile.open("currentUsers.txt");
    if(!userLoginFile){
        std::cout << "User info file not found.";
    }
    else{
        while(!userLoginFile.eof()){
            userLoginFile >> regd_username;
            if(username == regd_username){
                std::cout << "\nYou have been logged in! Welcome "
                << username << "!" << "\n";
                main_menu();
            }
            else if(regd_username != username){
                std::cout << "Username does not exist within database" << "\n";
                break;
            }
            
        
        }
    }
    
}

// Displays Options to users
void login_menu()
{
    int choice1 = get_input <int>(
        "Welcome to the Online Auction System! Please login to continue" "\n"
        "[1] Login" "\n"
        "[2] Exit");

    switch (choice1)
    {
    case 1:
        login();
        break;
    case 2:
        break;
    }
}

// Display all available user options to the user
void main_menu()
{
    int choice2 = get_input<int>(
        "\nPlease choose from the following options to proceed" "\n"
        "[1] Advertise new item" "\n"
        "[2] Bid on new items" "\n"
        "[3] Add Credit to your account" "\n"
        "[4] Request Refund" "\n"
        "[5] Delete User" "\n"
        "[6] Create User" "\n"
        "[7] Logout" "\n"
    );

    switch (choice2)
    {
        case 1:
            advertise();
            break;
        case 2:
            bid();
            break;
        case 3:
            add_credit();
            break;
        case 4:
            refund_credit();
            break;
        case 5:
            delete_user();
            break;
        case 6:
            create_user();
            break;
        case 7:
            logout();
            break;
    }
}

void logout()
{
    login_menu();
}
void create_user()
{
    //TODO
    login_menu();
}
void delete_user()
{
    //TODO
    login_menu();
}
void add_credit()
{
    //TODO
    login_menu();
}
void refund_credit()
{
    //TODO
    login_menu();
}
void advertise()
{
    //TODO
    login_menu();
}
void bid()
{
    //TODO
    login_menu();
}