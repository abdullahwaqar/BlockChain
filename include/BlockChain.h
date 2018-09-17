#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <list>
#include "./Block.h"
#include "./Transaction.h"

class BlockChain {
    public:
        BlockChain();

        Block createGenesisBlock();
        Block getLatestBlock();
        void addBlock(Block);
        void minePendingTransactions(std::string);
        void createTransaction(Transaction);
        unsigned short int getBalanceOfAddress(std::string);
        bool isChainValid();
    private:
        std::list<Block> chain;
        unsigned short int difficulty = 2;
        std::list<Transaction> pendingTransactions;
        unsigned short int miningReward = 100;
};

#endif //BLOCKCHAIN_H