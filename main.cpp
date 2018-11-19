#include <iostream>
#include "loadBalancer.hpp"

using namespace std;

int main(int argc, char const *argv[]){
    loadBalancer lb;
    while (true){
        lb.getInput();
        if (!lb.parseInput())
            break;
        lb.createNamedPipe();
        lb.getFiles();
        lb.devideFilesAndCreateWorkers();
        lb.createPresenter();
        // lb.clear();
    }
    return 0;
}
