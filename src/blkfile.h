//blkfile.h
#pragma once

#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include "block.h" 

#define BLK_FAIL 1
#define BLK_SUCCESS 0

class Blkfile {
public:
    Blkfile(std::string _filename);

    std::string readBlock(std::string blk_name);
    void writeBlock(std::string blk_name, std::string blk,
            bool overWrite);
    
    void saveChanges() const;

private:
    std::unordered_map<std::string, Block> blockmap;
    std::string filename;
};
