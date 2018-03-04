#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <list>
#include <iterator>
#include <sstream>
#include "Items.hpp"


std::vector<Item> Items::GetItems() {
    
    std::vector<Item> result;

    //open database
    std::ifstream itemFile;
    itemFile.open("Items.txt");

    std::string line;

    //read into database
    while (!itemFile.eof())
    {
        getline(itemFile, line);
        if (line.empty())
            continue;

        std::stringstream stream(line);
        
        Item item;
        
        stream >> item.username;
        stream >> item.item_name;
        stream >> item.price;
        stream >> item.days_left;

        result.push_back(item);
    }
    itemFile.close();

    return result;
}