//block.cpp
#include "block.h"
#include <sstream>
#include <string>

Block::Block(std::string name, std::string blk):
    blk_name(name),
    blk_stream(blk) {}

std::string Block::getName()  const {
    return blk_name;
}

std::stringstream& Block::getStream() {
    return blk_stream;
}

std::string Block::getBlock() const {
    return blk_stream.str();
}

void Block::setBlock(std::string blk) {
    blk_stream.str(blk);
}
