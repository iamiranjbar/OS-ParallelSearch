#include <iostream> 

#include "presenter.hpp"

using namespace std;

int main(int argc, char const *argv[]){
    presenter pr;
    pr.config(argv[1]);
    pr.getDataFromWorkers();
    return 1;
}