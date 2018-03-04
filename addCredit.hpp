#ifndef addCredit_H_
#define addCredit_H_
#include<string>
#include<vector>


class addCredit {
    public:
        void add_credit();
        static bool credit_success;
        static std::string username;
        static int changed_credit;
};

#endif