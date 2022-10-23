#include "block.h"
#include <sstream>

std::string Block::getName() {
    return blk_name;
}

std::stringstream& Block::getStream() {
    return blk_stream;
}

std::string Block::getBlock() {
    return blk_stream.str();
}

