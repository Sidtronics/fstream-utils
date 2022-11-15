#include<iostream>
#include<txtblocks.h>

int main() {

    Blkfile out("testFile.txt");
    std::string name = "newBlock";
    std::string blk = R"(This is new Block created 
    using txtblocks lib.)";

    out.writeBlock(name, blk, true);
    out.saveChanges();
    std::cout << "\nWritten";
}
