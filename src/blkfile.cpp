#include "txtblocks.h"
#include <cstddef>
#include <fstream>
#include <sstream>

Blkstream::Blkstream(std::string _filename):
filename(_filename)
{
    std::ifstream file(_filename);
    fbuffer << file.rdbuf();
}

std::string Blkstream::readBlock(std::string blkname){

    fbuffer.clear();
    size_t initpos = fbuffer.tellg();
    fbuffer.seekg(0);

    std::string line, blk = "";
    blkname = "###" + blkname + "###";

    while(std::getline(fbuffer, line)) if(line == blkname) break;
    while(std::getline(fbuffer, line)) if(line == blkname) break; else blk += line + '\n';
    
    fbuffer.seekg(initpos);

    return blk.erase(blk.length()-1);

}

bool Blkstream::writeBlock(std::string blkname, std::string blk){
    
    blkname = "###" + blkname + "###";

    if(fbuffer.str().find(blkname) == std::string::npos){

        fbuffer.clear();
        size_t initpos = fbuffer.tellp();
        fbuffer.seekp(0,std::ios_base::end);
        fbuffer << "\n" + blkname + "\n" << blk;
        fbuffer << "\n" + blkname + "\n";
        fbuffer.seekp(initpos);
        this->flush();

        return BLK_SUCCESS;
    }

    else return BLK_FAIL;
}

void Blkstream::flush(){
    std::ofstream out(filename, std::ios::trunc);
    out << fbuffer.rdbuf();
}
