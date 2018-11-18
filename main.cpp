#include <iostream>
#include "loadBalancer.hpp"

using namespace std;

int main(int argc, char const *argv[]){
    loadBalancer lb;
    while (true){
        lb.getInput();
        if (!lb.parseInput())
            break;
        lb.getFiles();
        lb.devideFilesAndCreateWorkers();
        // lb.clear();
    }
    return 0;
}
