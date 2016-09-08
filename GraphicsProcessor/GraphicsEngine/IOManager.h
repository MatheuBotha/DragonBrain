//
// Created by matheu on 9/7/16.
//

#ifndef DRAGONBRAIN_IOMANAGER_H
#define DRAGONBRAIN_IOMANAGER_H

#include <vector>
#include <string>

namespace GraphicsEngine {

    struct DirEntry {
        std::string path;
        bool isDirectory;
    };

    class IOManager
    {
    public:
        static bool readFileToBuffer(std::string filePath, std::vector<unsigned char>& buffer);
        static bool readFileToBuffer(std::string filePath, std::string& buffer);
        // Gets all directory entries in the directory specified by path and stores in rvEntries.
        // Returns false if path is not a directory.
//        static bool getDirectoryEntries(const char* path, std::vector<DirEntry>& rvEntries);
//        static bool makeDirectory(const char* path);
    };

}


#endif //DRAGONBRAIN_IOMANAGER_H