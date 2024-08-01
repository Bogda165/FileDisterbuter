#include <iostream>
#include "Core.h"
int main() {

    std::cout << "Begin" << std::endl;

    Core application = Core();

    application.showKnownFiles();

    application.checkFile();

    return 0;
}
