#ifndef refundCredit_H_
#define refundCredit_H_
#include<string>
#include<vector>


class refundCredit {
    public:
        void refund_credit();
        static std::string refund_username;
        static std::string seller_username;
        static int changed_credit;
        static bool refund_success;
};

#endif