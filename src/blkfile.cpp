//blkfile.cpp
#include "blkfile.h"
#include "block.h"
#include <cstddef>
#include <fstream>
#include <sstream>
#include <string>

Blkfile::Blkfile(std::string _filename):
filename(_filename)
{
    std::ifstream file(_filename);
    std::stringstream file_ss;
    file_ss << file.rdbuf();
    file.close();
    

    //Store all block in a map.
    std::string line;
    const std::string blk_start = "BLK:", blk_end = "BLK;";
    
    while(std::getline(file_ss, line)) {

        if(line.substr(0,4) == blk_start) {

            std::string blk_name = line.substr(4);
            std::string blk;

            while(std::getline(file_ss, line) 
                    && line.substr(0,4) != blk_end) {

                blk += (line + '\n');
            }

            blk.pop_back();
            blockmap[blk_name] = Block(blk_name, blk);
        }
    }
}



std::string Blkfile::readBlock(std::string blk_name) {
    
    if(blockmap.count(blk_name))
        return blockmap[blk_name].getBlock();

    else return "";
    
}

void Blkfile::writeBlock(std::string blk_name, std::string blk,
        bool overWrite)  {

    if(!overWrite && blockmap.count(blk_name) == 1)
        return;

    else {
        blockmap[blk_name].setBlock(blk);
    }
}

void Blkfile::saveChanges() const {

    std::ofstream file(filename, std::ios::trunc);
    
    for(auto it = blockmap.begin(); it != blockmap.end(); ++it) {
        file << "BLK:" << it->first << '\n';
        file << it->second.getBlock() << '\n' << "BLK;\n\n"; 
    }
    
    file.close();
}
