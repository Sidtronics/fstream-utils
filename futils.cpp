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

   std::string blkstring =  "###" + blkname + "###";
   size_t blkbeg = fileContents.find(blkstring);

   ifile->seekg(blkbeg);
   ifile->ignore(blkstring.length());
   blkbeg = ifile->tellg();

   size_t blkend = fileContents.find(blkstring, blkbeg);

   return fileContents.substr(blkbeg, blkend - blkbeg);
}

std::string inFile::getFileContents(){
    return fileContents;
}
