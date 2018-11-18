#ifndef LOADBALANCER_HPP
#define LOADBALANCER_HPP

#include <iostream>
#include <vector>
#include <map>

#include "tools.hpp"

class loadBalancer{
private:
    std::string commandLine;
    std::vector<std::string> commandParts;
    std::map <std::string,std::string> filters;
    std::map <std::string,std::string> sorting;
    int prc_cnt;
    std::string dir_name;
public:
    void getInput();
    bool parseInput();
    void setFields();
};

#endif