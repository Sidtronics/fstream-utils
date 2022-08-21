#pragma once
#include <fstream>
#include <string>

class inFile {
public:
    inFile(std::string _path);
    std::string readBlock(std::string blkname);
    std::string getFileCon();

private:
    //std::string filePath;
    std::string fileContents;
    std::ifstream ifile;
};