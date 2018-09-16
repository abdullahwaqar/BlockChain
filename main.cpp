#include "include/BlockChain.h"

int main() {
    BlockChain bChain;
    std::cout << bChain.getLatestBlock().getHash() << "\n \n";
    Block b1(14, 23.00, "heloo", "helloooo");
    bChain.addBlock(b1);
    std::cout << bChain.getLatestBlock().getPreviousHash();
    return 0;
}