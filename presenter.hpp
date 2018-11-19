#ifndef PRESENTER_HPP
#define PRESENTER_HPP

#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <unistd.h>

#include "tools.hpp"
#include "define.hpp"

class presenter{
private:
    std::map <std::string,std::string> sorting;
    int prcCnt;
public:
    void config(std::string configLine);
    void fillMap(std::string sortingString);
    void getDataFromWorkers();
    std::vector<std::string> splitData(std::string data);
    void sortResult(std::vector<std::vector<std::string> > &res, std::string sortBy,
        std::string type);
};

#endif