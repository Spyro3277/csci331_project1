/**
 * @file Buffer.cpp
 * @brief Implementation file for the Buffer class.
 * @author Team 3
 * @date october 1 , 2024
 * @version 1.0
 */

#include "Buffer.h"
#include <iostream>

using namespace std;

Buffer::Buffer(const std::string &file) {
    if (!openFile(file)) {
        std::cerr << "Failed to openFile file: " << file << std::endl;
    } else {
        // Read the header, so it is not read in as data
        std::string header;
        std::getline(inputStream, header);
    }
}

Buffer::~Buffer() {
    closeFile();
}

bool Buffer::readLine(std::string &line) {
    if (inputStream.is_open()) {
        if (std::getline(inputStream, line)) {
            return true;
        }
    }
    return false;
}

bool Buffer::openFile(string file) {
    inputStream.open(file.c_str());

    if (!inputStream) {
        return false;
    }

    return true;
}

bool Buffer::closeFile() {
    if (inputStream.is_open()) {
        inputStream.close();
        return true;
    }
    return false;
}
