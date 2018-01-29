


#include <iostream>
#include <stdio.h>

#include "../tools/process.h"
#include "../tools/tools.h"
#include "FCFSQueue.h"

using namespace std;


void printProcessList(vector<Process *> &processList) {

	cout << "Process name	|	Arrival time	|	Duration	|	Priority" << endl;
	cout << "---------------------------------------------------------------" << endl;
	for (int i = 0; i < processList.size(); i++) {

		Process *p = processList[i];
		cout << p->identifier << "	|	" << p->arrivalTime << "	|	" << p->runTime << "	|	" << p->runTime << "	|	" << p->priority << endl;  
	}

	cout << "---------------------------------------------------------------" << endl;
	cout << "\n" << endl;
}


int main(int argc, char* argv[]) {

	for (int i = 0; i < 5; i++) {
		FCFSQueue model;

		cout << "Simulation #" << i+1 << endl;
		vector<Process *> processList = generate::generateProcessList();
		printProcessList(processList);
		processList.sort();
		printProcessList(processList);
		cout << "Starting First Come First Serve"

		model.startSimulation(processList);
	}
	return 1;
}

