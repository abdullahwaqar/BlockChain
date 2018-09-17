#include "../include/Block.h"

Block :: Block(float time_, std::string data_, std::string previousHash_) : previousHash(previousHash_), timeStamp(time_), data(data_) {
    hash = calculateHash();
}

std::string Block :: calculateHash() {
    std::string src_str = previousHash + std::to_string(timeStamp) + data + std::to_string(nonce);

    std::vector<unsigned char> hash(picosha2::k_digest_size);
    picosha2::hash256(src_str.begin(), src_str.end(), hash.begin(), hash.end());

    std::string hex_str = picosha2::bytes_to_hex_string(hash.begin(), hash.end());
    return hex_str;
}

void Block :: setPreviousHash(std::string prevHash_) { previousHash = prevHash_; }

std::string Block :: getPreviousHash() { return previousHash; }

void Block :: setHash(std::string hash_) { hash = hash_; }

std::string Block :: getHash() { return hash; }

void Block :: mineBlock(unsigned short int difficulty) {
    // std::string array[difficulty + 1];
    std::string array = "";
    for (int i = 0; i < difficulty; i++)
        array += "0";
    while (this->hash.substr(0, difficulty) != array) {
        this->nonce++;
        this->hash = this->calculateHash();
    }
}