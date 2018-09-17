#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

class Transaction {
    public:
        Transaction(std::string, std::string, unsigned short int);
        std::string fromAddress;
        std::string toAddress;
        unsigned short int amount;
};

#endif //TRANSACTION_H