#include "include/BlockChain.h"
#include "include/Transaction.h"

int main() {
    /* Testing the Block Chain */

    // ** Creating Chain Object
    BlockChain bChain;

    // ** Creating Transactions
    Transaction t1("address1", "adress2", 200);
    bChain.createTransaction(t1);

    Transaction t2("address2", "adress1", 500);
    bChain.createTransaction(t2);

    bChain.minePendingTransactions("idk-adress");

    // std::cout << bChain.getBalanceOfAddress("idk-adress");
    return 0;
}