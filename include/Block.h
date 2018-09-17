#ifndef BLOCK_H
#define BLOCK_H

#include <iostream>
#include <string>
#include <chrono>
#include "./picosha2.h"

class Block {
    public:
        Block(unsigned short int, float, std::string, std::string);
        std::string calculateHash();

        void setPreviousHash(std::string);
        std::string getPreviousHash();

        void setHash(std::string);
        std::string getHash();

        void mineBlock(unsigned short int);
    private:
        unsigned short int index;
        std::string previousHash;
        float timeStamp;
        std::string data;
        std::string hash;
        unsigned short int nonce = 0;
};

#endif //BLOCK_H