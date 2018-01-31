//
// Carlos Rivera
// tools.cpp
//
// Tools to generate set of simulated processes

#include "tools.h"
#include <cstdlib>

#include "process.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;


// sorts processes based on arrival time
bool processSorter (Process *i,Process *j) { 
	if (i == NULL || j == NULL) {
		//cerr << "This IS NULL" << endl;
		if (i == NULL) {
			i = new Process();
		}

		if (j == NULL) {
			j = new Process();
		}

	}

	return (i->arrivalTime <= j->arrivalTime);
}


// generates a list of processes for simulation, default 100
vector<Process *>generate::generateProcessList() {

	int max = 40;

	vector<Process *> res;
	for (int i = 0; i < max; i++) {

		Process *p = generate::generateNewProcess();

		res.push_back(p);
	}

	std::sort(res.begin(), res.end(), processSorter);

	for (int i = 0; i < max; i++) {
		char temp = 'A' + i;
		res[i]->identifier = temp;
	}

	return res;
}


vector<vector<Process *> > generate::generateSimulationData() {

	// for different number
	srand(time(NULL));

	vector<vector<Process *> > res;
	for (int i = 0; i < 5; i++) {
		vector<Process *> temp = generate::generateProcessList();
		res.push_back(temp);
		cerr << "Generated data" << temp.size() << endl;

	}
	return res;
}

vector<vector<Process *> > generate::getCopiedData(const vector<vector<Process *> > data) {

	vector <vector<Process *> > res;
	for (int i = 0; i < data.size(); i++) {
		vector<Process *> temp;
		for (int j = 0; j < data[i].size(); j++) {
			temp.push_back(new Process(*data[i][j]));
		}

		res.push_back(temp);

	}
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
