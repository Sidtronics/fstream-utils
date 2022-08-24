#include "futils.h"
#include <cstddef>
#include <sstream>

inFile::inFile(std::ifstream *_ifile):
ifile(_ifile)
{
    std::stringstream buffer;
    buffer << ifile->rdbuf();
    fileContents = buffer.str();
}

std::string inFile::readBlock(std::string blkname){
    size_t initpos = ifile->tellg();
    ifile->seekg(0);
    std::string line, blk = "";
    while(std::getline(*ifile, line)) if(line == "###" + blkname + "###") break;
    while(std::getline(*ifile, line)) if(line == "###" + blkname + "###") break; else blk += line + '\n';
    ifile->seekg(initpos);
    return blk;
}

std::string inFile::getFileContents(){
    return fileContents;
}
