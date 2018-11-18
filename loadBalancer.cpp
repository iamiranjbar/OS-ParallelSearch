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
    for (int i = 0; i < lastElement-3; i = i+2){
        if (commandParts[i+1] == ASCEND || commandParts[i+1] == DECSEND){
            sorting[commandParts[i]] = commandParts[i+1];
        }
        else{
            filters[commandParts[i]] = commandParts[i+1];
        }
    }
    // for(std::map <std::string,std::string> ::iterator it = filters.begin(); it != filters.end(); ++it) {
    //     std::cout << it->first << "\n";
    //     std::cout << it->second << "\n";
    // }
    prc_cnt = stoi(commandParts[lastElement-2]);
    dir_name = commandParts[lastElement];
}