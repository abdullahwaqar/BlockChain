#include "../include/BlockChain.h"

BlockChain :: BlockChain() {
    chain.push_back(createGenesisBlock());
}

Block BlockChain :: createGenesisBlock() {
    return Block(10, 2.00, "heloo", "hello");
}

Block BlockChain :: getLatestBlock() {
    return this->chain.back();
}

void BlockChain :: addBlock(Block newBlock_) {
    newBlock_.setPreviousHash(this->getLatestBlock().getHash());
    newBlock_.setHash(newBlock_.calculateHash());
    this->chain.push_back(newBlock_);
}