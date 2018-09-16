#include "include/BlockChain.h"

int main() {
    BlockChain bChain;
    Block b1(14, 23.00, "heloo", "helloooo");
    Block b2(14, 23.00, "hesdddloo", "helloooo");
    bChain.addBlock(b1);
    bChain.addBlock(b2);
    std::cout << bChain.isChainValid();
    return 0;
}