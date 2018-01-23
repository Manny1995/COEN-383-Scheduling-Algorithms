//
// Carlos Rivera
// tools.cpp
//
// Tools to generate set of simulated processes

#include "tools.h"
#include <cstdlib>


#include "process.h"
#include <vector>

#include <iostream>

using namespace std;


// sorts processes based on arrival time
bool processSorter (Process *i,Process *j) { 
	return (i->arrivalTime <= j->arrivalTime);
}


// generates a list of processes for simulation, default 100
vector<Process *>generate::generateProcessList() {

	vector<Process *> res;
	for (int i = 0; i < 100; i++) {
		res.push_back(generate::generateNewProcess());
		cerr << "Generated process " << res[i]->arrivalTime << endl;
	}

	std::sort(res.begin(), res.end(), processSorter);

	return res;
}



Process *generate::generateNewProcess() {

	return new Process(generate::arrivalTime(), generate::runTime(), generate::priority());
}

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
