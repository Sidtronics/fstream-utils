#include<iostream>
#include<txtblocks.h>

int main(int argc, char* argv[]) {
    if(argc != 2) return 1;

    Blkstream out("INPUT");
    std::cout << out.readBlock(argv[1]);
}
