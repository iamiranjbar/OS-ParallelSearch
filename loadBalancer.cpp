#include "loadBalancer.hpp"

void loadBalancer::getInput(){
    getline(std::cin, commandLine);
}

bool loadBalancer::parseInput(){
    if (commandLine == "quit")
        return 0;
    return 1;
}