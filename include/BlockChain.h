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
    private:
        std::list<Block> chain;
};

#endif //BLOCKCHAIN_H