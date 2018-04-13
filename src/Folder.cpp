#include "Folder.h"

Folder::Folder(std::string folderPath)
{
    this->folderPath = folderPath;
    totalSize = 0;
}

void Folder::addSize(int bytes)
{
    totalSize += bytes;
}

Folder::~Folder()
{
}
