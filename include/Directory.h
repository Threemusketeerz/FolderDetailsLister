#ifndef DIRECTORY_H
#define DIRECTORY_H

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <boost/filesystem.hpp>
#include <Folder.h>

namespace fs = boost::filesystem;

class Directory
{
    private:
        std::string dirPath;
        std::vector<Folder> folders;

        void buildReadableString(std::stringstream &stringToBuild,
            const int &byteSizeToCheck, std::string &format);

    public:
        Directory(fs::path &path);
        ~Directory();

        void printFolders();

        void setupFolders();
        void scanFolders();

        void addFolder(Folder &folder) { folders.push_back(folder); }

        void setDirPath(std::string &dirPath);
        std::string getDirPath() { return dirPath; };

        // Convert bytes into MB and GB.
        std::string getReadableTotalSize(Folder folder);

        void bytesInFormat(int &fromByteType, int &toByteType);

    protected:

};

#endif // DIRECTORY_H
