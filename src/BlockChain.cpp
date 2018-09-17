#include "../include/BlockChain.h"

BlockChain :: BlockChain() {
    chain.push_back(createGenesisBlock());
}

Block BlockChain :: createGenesisBlock() {
    return Block(2.00, "heloo", "0");
}

Block BlockChain :: getLatestBlock() {
    return this->chain.back();
}

void BlockChain :: addBlock(Block newBlock_) {
    newBlock_.setPreviousHash(this->getLatestBlock().getHash());
    // newBlock_.setHash(newBlock_.calculateHash());
    newBlock_.mineBlock(this->difficulty);
    this->chain.push_back(newBlock_);
}

void BlockChain :: minePendingTransactions(std::string miningAddress) {
    std::list<Transaction>::iterator it;
    for (it = pendingTransactions.begin(); it != pendingTransactions.end(); ++it) {
        Block newBlock = Block(2.00, std::to_string(it->amount), this->getLatestBlock().getHash());
        newBlock.mineBlock(difficulty);
        this->chain.push_back(newBlock);
    }
    Transaction t = Transaction("", miningAddress, this->miningReward);
    this->pendingTransactions.push_back(t);
}

void BlockChain :: createTransaction(Transaction t) {
    this->pendingTransactions.push_back(t);
}

unsigned short int BlockChain :: getBalanceOfAddress(std::string address) {
    unsigned short int balance = 0;
    std::list<Block>::iterator itB;
    std::list<Transaction>::iterator it;
    for (itB = chain.begin(); itB != chain.end(); ++it) {
        for (it = this->pendingTransactions.begin(); it != this->pendingTransactions.end(); ++it) {
            if (it->fromAddress == address) {
                balance -= it->amount;
            }
            if (it->toAddress == address) {
                balance += it->amount;
            }
        }

    }
    return balance;

}

bool BlockChain :: isChainValid() {
    std::cout << this->chain.size() << "\n \n";
    std::list<Block>::iterator it;
    for (it = std::next(chain.begin()); it != chain.end(); ++it) {
        std::cout << it->getPreviousHash() << "\n \n";
        std::cout << it->getHash() << "\n \n";
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