#ifndef LOADBALANCER_HPP
#define LOADBALANCER_HPP

#include <iostream>
#include <vector>
#include <map>
#include <dirent.h>
#include <unistd.h>

#include "tools.hpp"
#include "define.hpp"

class loadBalancer{
private:
    std::string commandLine;
    std::vector<std::string> commandParts;
    std::map <std::string,std::string> filters;
    std::map <std::string,std::string> sorting;
    std::string filterString;
    std::string sortingString;
    int prcCnt;
    std::string dirPath;
    std::vector<std::string> dirFiles;
    std::vector<int> workerNumFiles;
public:
    void getInput();
    bool parseInput();
    void setFields();
    void getFiles();
    void devideFilesAndCreateWorkers();
    void clear();
};

#endif