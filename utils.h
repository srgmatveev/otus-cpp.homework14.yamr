#pragma once
#include <cstddef>
#include <vector>
#include <fstream>
#include <exception>
std::streampos getFileSize(const std::string &fileName)
{
    std::streampos fSize = 0;
    std::ifstream myFile(fileName, std::ios::in);
    if (!myFile.is_open())
        throw std::invalid_argument("Error! Couldn't open file " + fileName);
    myFile.seekg(0, std::ios::end);
    fSize = myFile.tellg();
    myFile.close();
    if (fSize == -1)
        throw std::runtime_error("Error! Couldn't get file size of " + fileName);
    return fSize;
}

std::vector<std::streampos> splitFilePos(const std::string &fileName, std::size_t partNumbs = 1)
{
    std::vector<std::streampos> partsPos;

    std::ifstream file(fileName, std::ios::in);
    if (!file.is_open())
        throw std::invalid_argument("Error! Couldn't open file " + fileName);

    auto fileSize = getFileSize(fileName);
    if (!partNumbs)
        partNumbs = 1;
    auto partSize = fileSize % partNumbs ? fileSize / partNumbs + 1 : fileSize / partNumbs;
    auto pos = partSize;

    if (fileSize)
    {
        partsPos.reserve(partNumbs);
        partsPos.emplace_back(0);
        std::string line{""};
        do
        {
            file.seekg(pos, std::ios::beg);
            std::getline(file, line);
            pos = file.tellg();
            pos += partSize;
            if (pos < fileSize)
                partsPos.emplace_back(pos);
            else
            {
                partsPos.emplace_back(fileSize);
                break;
            }
        } while (!file.eof());
    }
    else
    {
        partsPos.emplace_back(0);
    }
    file.close();
    return partsPos;
}