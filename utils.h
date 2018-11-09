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

std::vector<std::size_t> splitFile(const std::string &fileName, std::size_t partNumbs)
{
    std::vector<std::size_t> partsPos;
    partsPos.reserve(partNumbs);
    std::ifstream file(fileName, std::ios::in);
    if (!file.is_open())
        throw std::invalid_argument("Error! Couldn't open file " + fileName);
    return partsPos;

    /*if (!file.size())
        throw std::invalid_argument("Error! Empty file " + fileName);*/
}