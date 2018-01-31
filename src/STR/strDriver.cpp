

#ifndef STRDRIVER_CPP
#define STRDRIVER_CPP


#include "strDriver.h"
#include "../tools/process.h"
#include "../tools/tools.h"

void strDriver(vector <vector <Process *> > batch) {

	for (int i = 0; i < batch.size(); i++) {


		cout << "Starting Shortest Time Remaining" << endl;
        cout << "Simulation #" << i+1 << endl;

		STR model;
		model.startSimulation(batch[i]);
	}
}

#endif