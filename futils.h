#pragma once
#include <fstream>
#include <string>

class inFile {
public:
    inFile(std::ifstream *_ifile);
    std::string readBlock(std::string blkname);
    std::string getFileContents();

private:
    std::string fileContents;
    std::ifstream *ifile;
};
