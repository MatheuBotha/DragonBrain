//
// Created by matheu on 9/7/16.
//

#ifndef DRAGONBRAIN_IOMANAGER_H
#define DRAGONBRAIN_IOMANAGER_H

#include <vector>
#include <string>

struct DirEntry {
    std::string path;
    bool isDirectory;
};

class IOManager
{
public:
    static bool readFileToBuffer(const char* filePath, char* buffer);
    static bool readFileToBuffer(std::string filePath, std::string& buffer);
};

#endif //DRAGONBRAIN_IOMANAGER_H