#include <iostream>
#include <map>
#include <boost/filesystem.hpp>
#include <vector>
#include "Folder.h"
#include "Directory.h"

namespace fs = boost::filesystem;

int main(const int argc, const char* argv[])
{
    fs::path path(argv[1]);
    Directory startDir(path);

    startDir.setupFolders();
    startDir.scanFolders();
    startDir.printFolders();
    return 0;
}
