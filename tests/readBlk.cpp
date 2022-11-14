#include<iostream>
#include<txtblocks.h>

int main(int argc, char* argv[]) {
    if(argc != 2) return 1;

    Blkfile in("testFile.txt");
    std::cout << in.readBlock(argv[1]);
}
