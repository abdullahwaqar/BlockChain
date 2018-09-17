#include "include/BlockChain.h"

int main() {
    /* Testing the Block Chain */
    BlockChain bChain;
    Block b1(14, 23.00, "heloo", "helloooo");
    Block b2(14, 23.00, "hesdddloo", "helloooo");

    std::cout << "[-] Mining Block 1....\n";
    bChain.addBlock(b1);
    std::cout << "[*] Done Mining Block 1....\n";

    std::cout << "[-] Mining Block 2....\n";
    bChain.addBlock(b2);
    std::cout << "[*] Done Mining Block 2....\n";

    std::cout << bChain.isChainValid();
    return 0;
}