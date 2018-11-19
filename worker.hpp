#ifndef WORKER_HPP
#define WORKER_HPP

#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include <unistd.h>

#include "tools.hpp"

class worker{
private:
    std::map <std::string,std::string> filters;
    std::vector<std::string> files;
    std::vector<std::vector<std::string> > searchTable;
    std::string dataForPresenter;
public:
    void setFields(std::string data);
    void fillMaps(std::string filterString);
    void setFiles(std::string fileString);
    void processFiles();
    void search();
    void makeDataReady();
};

#endif 
