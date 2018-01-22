//
// Carlos Rivera
// rand.cpp
//
// Tools to generate set of simulated processes

#include "rand.h"

#include <cstdlib>

#define NUMBER_OF_PROCESSES 100

float* generateArrivalTimes() {

    float* arrivalTimes = new float[NUMBER_OF_PROCESSES];

    for (int i = 0 ; i < NUMBER_OF_PROCESSES ; ++i) {
        arrivalTimes[i] = rand() % 100;
    }

    return arrivalTimes;

}


float* generateRunTimes() {

    float* runTimes = new float[NUMBER_OF_PROCESSES];
    float currentRandomNumber;

    for (int i = 0 ; i < NUMBER_OF_PROCESSES ; ++i) {

        currentRandomNumber = rand() % 10;

        if (currentRandomNumber == 0) {
            currentRandomNumber = 0.1;
        }

        runTimes[i] = currentRandomNumber;

    }

    return runTimes;

}


int* generatePriorities() {

    int* priorities = new int[NUMBER_OF_PROCESSES];

    for (int i = 0 ; i < NUMBER_OF_PROCESSES ; i++) {
        priorities[i] = (rand() % 4) + 1;
    }

    return priorities;

}


int getNumberOfProcesses() {

    return NUMBER_OF_PROCESSES; 

}

