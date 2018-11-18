#include "loadBalancer.hpp"

void loadBalancer::getInput(){
    getline(std::cin, commandLine);
}

bool loadBalancer::parseInput(){
    if (commandLine == "quit")
        return 0;
    const char chars[]= { '-' , '=' };
    commandParts = Tools::split(commandLine, chars);
    this->setFields();
    return 1;
}

void loadBalancer::setFields(){
    int lastElement = commandParts.size() - 1;
    for (int i = 0; i < lastElement-3; i++){
        // if (i )
    }
    prc_cnt = stoi(commandParts[lastElement-2]);
    dir_name = commandParts[lastElement];
}