//block.h
#pragma once

#include<string>
#include<sstream>

class Block {
    public:
        Block(std::string name, std::string blk);
        Block() = default;

        std::string getName() const;
        std::string getBlock() const;
        std::stringstream& getStream();

        void setBlock(std::string blk);

    private:
        std::string blk_name;
        std::stringstream blk_stream;
};
