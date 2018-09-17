#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <list>
#include "./Block.h"

class BlockChain {
    public:
        BlockChain();

        Block createGenesisBlock();
        Block getLatestBlock();
        void addBlock(Block);
        bool isChainValid();
    private:
        std::list<Block> chain;
        unsigned short int difficulty = 4;
};

#endif //BLOCKCHAIN_H