#pragma once

#include <fstream>
#include <sstream>
#include <string>

class Fstrm {
public:
    Fstrm(std::string _filename);

    std::string readBlock(std::string blkname);
    void writeBlock(std::string blkname, std::string blk);
    
    void flush();

private:
    std::stringstream fbuffer;
    std::string filename;
};
