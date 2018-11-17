#ifndef LOADBALANCER_HPP
#define LOADBALANCER_HPP

#include <iostream>

class loadBalancer{
private:
    std::string commandLine;    
public:
    void getInput();
    bool parseInput();
};

#endif