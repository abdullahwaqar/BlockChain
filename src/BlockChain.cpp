#include "../include/BlockChain.h"

BlockChain :: BlockChain() {
    chain.push_back(createGenesisBlock());
}

Block BlockChain :: createGenesisBlock() {
    return Block(10, 2.00, "heloo", "0");
}

Block BlockChain :: getLatestBlock() {
    return this->chain.back();
}

void BlockChain :: addBlock(Block newBlock_) {
    newBlock_.setPreviousHash(this->getLatestBlock().getHash());
    newBlock_.setHash(newBlock_.calculateHash());
    this->chain.push_back(newBlock_);
}

bool BlockChain :: isChainValid() {
    std::cout << this->chain.size() << "\n \n";
    std::list<Block>::iterator it;
    for (it = std::next(chain.begin()); it != chain.end(); ++it) {
        // std::cout << it->getPreviousHash() << "\n \n";
        // std::cout << it->getHash() << "\n \n";
        const auto currentBlock = it;
        const auto previousBlock = std::prev(it);
        if (currentBlock->getHash() != currentBlock->calculateHash()) {
            std::cout << "Test Passed" << "\n";
            return false;
        }
        if (currentBlock->getPreviousHash() != previousBlock->getHash()) {
            std::cout << "Test failed" << "\n";
            return false;
        }
    }
    return true;
}