#include <iostream>
#include "loadBalancer.hpp"

using namespace std;

int main(int argc, char const *argv[]){
    loadBalancer lb;
    while (true){
        lb.getInput();
        if (!lb.parseInput())
            break;
    }
    return 0;
}
