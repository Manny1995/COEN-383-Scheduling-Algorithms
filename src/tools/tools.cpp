//
// Carlos Rivera
// tools.cpp
//
// Tools to generate set of simulated processes

#include "tools.h"
#include <cstdlib>


float generate::arrivalTime() {
    return rand() % 100;
}


float generate::runTime() {

    float runTime;
    runTime = rand() % 10;
    
    if (runTime == 0) {
        runTime = 0.1;
    }
    
    return runTime;

}


int generate::priority() {
    return (rand() % 4) + 1;
}
