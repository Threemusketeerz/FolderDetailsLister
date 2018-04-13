#include "Directory.h"


Directory::Directory(fs::path &path)
{
    dirPath = path.string();
}

Directory::~Directory()
{
}

void Directory::setupFolders()
{
    for(fs::directory_entry &x : fs::directory_iterator(dirPath))
    {
        if(fs::is_directory(x))
        {
            Folder folder(x.path().string());
            addFolder(folder);
        }
    }

}

// Looks at the filesizes container in every level of folders in "folders"
void Directory::scanFolders()
{

    // Remember to pass by reference. Else c++ will not modify outside its scope.
    for(Folder &folder : folders)
    {
        std::string currentFolder = folder.getFolderPath();
        fs::path currentPath(currentFolder);

        //std::cout << folder.getFolderPath() << std::endl;
        for(fs::directory_entry &x : fs::recursive_directory_iterator(currentPath))
        {

            if(!fs::is_directory(x))
            {
                //std::cout << "File size: " << fs::file_size(x) << std::endl;
                folder.addSize(static_cast<int>(fs::file_size(x)));
            }
        }
    }
    std::cout << "Succesfully scanned folder!" << std::endl;
}

void Directory::printFolders()
{
    for(Folder &folder : folders)
    {
        //std::cout << std::endl;
        std::string folderPath = folder.getFolderPath();
        std::string builtString = getReadableTotalSize(folder);
        std::cout << "Folder name: " << folderPath << ", "
           << builtString << std::endl;
    }
}

std::string Directory::getReadableTotalSize(Folder folder)
{
    std::string byteRepr[] = { "BYTES", "KB", "MB", "GB" };
    std::stringstream returnString;
    // Indexes of MegaBytes and GigaBytes
    const int BYTES = 0, KB = 1, MB = 2, GB = 3;


    int folderSizeInBytes = folder.getTotalSize();
    int kb, mb, gb = 0;
    bytesInFormat(folderSizeInBytes, kb);
    bytesInFormat(kb, mb);
    bytesInFormat(mb, gb);

    buildReadableString(returnString, gb, byteRepr[GB]);
    buildReadableString(returnString, mb, byteRepr[MB]);
    buildReadableString(returnString, kb, byteRepr[KB]);
    buildReadableString(returnString, folderSizeInBytes, byteRepr[BYTES]);

    std::string finishedString = returnString.str();
    return finishedString;
}

void Directory::buildReadableString(std::stringstream &stringToBuild,
    const int &byteSizeToCheck, std::string &format)
{
    if(byteSizeToCheck > 0)
    {
        std::stringstream aString;
        aString << byteSizeToCheck << format << " ";
        stringToBuild << aString.str();
    }
}

void Directory::bytesInFormat(int &fromByteType, int &toByteType)
{
//    std::cout << "FromByteType: " << fromByteType << "\nToByteType: " << toByteType << std::endl;
    int differential = 1000;
    if(fromByteType > differential)
    {
        toByteType = fromByteType / differential;
        fromByteType -= toByteType * differential;
    }
}
