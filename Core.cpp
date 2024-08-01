//
// Created by User on 31/07/2024.
//

#include "Core.h"

Core::Core() {
    std::cout << "Indexing you DIR" << std::endl;
    this->downloads = new fs::path(Constants::TRY_DIR_PATH.string());
    files = new std::unordered_set<std::string>();

    for (auto &file: fs::directory_iterator(*downloads)) {
        files->insert(file.path().string());
    }
}

void Core::showKnownFiles() const {
    std::cout << "Writing known files: " << std::endl;
    for(auto const &file: *files) {
        std::cout << "\t" << file << std::endl;
    }
}

void Core::checkFile() {
    while(true) {
        for(auto &file: fs::directory_iterator(*downloads)) {
            std::string fPath = file.path().string();
            if(files->find(fPath) == files->end()) {
                files->insert(fPath);
                std::cout << "Move file...";
                moveFile(fPath);
            }
        }
        //delete for release
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

void Core::moveFile(std::string path) {
    fs::path file = fs::path(path);
    fs::path dir = fs::path(downloads->string() + "/" + file.extension().string().substr(1));

    if(!fs::exists(dir)) {
        fs::create_directories(dir);
        files->insert(dir);
    }

    fs::path file2 = fs::path(dir.string() + "/" + file.filename().string());
    std::cout << "Old path: " << file.string() << "/ new path: " << file2.string() << std::endl;

    try {
        fs::rename(file, file2);
    } catch (const fs::filesystem_error& e) {
        std::cerr << "Error moving file: " << e.what() << std::endl;
    }
}

Core::~Core() {
    delete downloads;
    //serealize the files)
    delete files;

    std::cout << "Memory was freed";
}