//
// Created by User on 31/07/2024.
//

#ifndef FILE_TYPE_SCRIPT_CORE_H
#define FILE_TYPE_SCRIPT_CORE_H

#include <filesystem>
#include <unordered_set>
#include "Constant.h"
#include <iostream>
#include <thread>
#include <chrono>

namespace fs = std::filesystem;

class Core {
    fs::path* downloads;
    // add serialization of set!!!
    std::unordered_set<std::string>* files;
public:
    Core();
    ~Core();

    void showKnownFiles() const;

    void moveFile(std::string path);
    void checkFile();
};


#endif //FILE_TYPE_SCRIPT_CORE_H
