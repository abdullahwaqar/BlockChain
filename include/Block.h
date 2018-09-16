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
    private:
        unsigned short int index;
        std::string previousHash;
        float timeStamp;
        std::string data;
        std::string hash;
};

#endif //BLOCK_H