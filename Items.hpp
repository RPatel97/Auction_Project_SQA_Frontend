#ifndef Items_H_
#define Items_H_
#include<string>
#include<vector>


class Item {
    public:
        std::string username;
        std::string item_name;
        double price;
        int days_left;
};

class Items{
    public:
        static std::vector<Item> GetItems();
};

#endif
