#ifndef FOLDER_H
#define FOLDER_H

#include <string>
#include <vector>

class Folder
{
    private:
        int totalSize;
        std::string folderPath;

    public:
        Folder(std::string folderPath);
        ~Folder();

        std::string getFolderPath(){ return folderPath; };
        int getTotalSize() { return totalSize; };
        void addSize(int fileSize);

        void printFiles();

    protected:
};

#endif // FOLDER_H
