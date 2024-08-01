#ifndef FILE_TYPE_SCRIPT_CONSTANTS_H
#define FILE_TYPE_SCRIPT_CONSTANTS_H

#include <filesystem>

namespace fs = std::filesystem;

namespace Constants {
    const fs::path DOWNLOADS_PATH("/Users/user/Downloads");
    const fs::path PDF_FILES_PATH("/Users/user/Downloads/pdf_files");
    const fs::path TXT_FILES_PATH("/Users/user/Downloads/txt_files");
    const fs::path OTHER_FILES_PATH("/Users/user/Downloads/other_files");
    const fs::path TRY_DIR_PATH("/Users/user/Downloads/TRY");
}

#endif //FILE_TYPE_SCRIPT_CONSTANTS_H