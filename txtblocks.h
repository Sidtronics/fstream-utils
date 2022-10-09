#pragma once

#include <fstream>
#include <sstream>
#include <string>

#define BLK_FAIL 1
#define BLK_SUCCESS 0

class Blkstream {
public:
    Blkstream(std::string _filename);

    std::string readBlock(std::string blkname);
    bool writeBlock(std::string blkname, std::string blk);
    
    void flush();

private:
    std::stringstream fbuffer;
    std::string filename;
};
