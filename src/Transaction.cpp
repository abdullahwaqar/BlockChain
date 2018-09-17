#include "../include/Transaction.h"

Transaction :: Transaction(std::string fromAddress_, std::string toAddress_, unsigned short int amount_) : fromAddress(fromAddress_), toAddress(toAddress_), amount(amount_) {}