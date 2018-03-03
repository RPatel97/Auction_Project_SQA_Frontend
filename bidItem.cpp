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

void bidItem::bid_item(){
    //open database
    std::ifstream userItemFile;
    userItemFile.open("Items.txt");

    std::string line;
    std::string userName[100];
    std::string itemName[100];
    double itemBid[100];
    int daysLeft[100];

    //read into database
    while (!userItemFile.eof())
    {
        if(userItemFile.is_open())
        {
            getline(userItemFile, line);
            std::stringstream stream(line);
            stream >> userName;
            stream >> itemName;
            stream >> itemBid;
            stream >> daysLeft;
        }
    }
    userItemFile.close();

    std::cout << userName << itemName << itemBid << daysLeft << "\n";
}