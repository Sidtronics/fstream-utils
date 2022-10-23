#pragma once

#include<string>
#include<sstream>

class Block{
    public: 
        std::string getName();
        std::string getBlock();
        std::stringstream& getStream();

    private:
        std::string blk_name;
        std::stringstream blk_stream;
};
