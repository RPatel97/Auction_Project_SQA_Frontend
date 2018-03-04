#ifndef bidItem_H_
#define bidItem_H_
#include <string>

class bidItem{
    public:
        void bid_item();
        static bool bid_success;
        static std::string item_name;
        static std::string seller_name;
        static int bid_amount;
        static int days_left;

};

#endif
