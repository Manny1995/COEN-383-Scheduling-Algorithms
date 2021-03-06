

#ifndef SJFDRIVER_CPP
#define SJFDRIVER_CPP


#include "sjfDriver.h"
#include "../tools/process.h"
#include "../tools/tools.h"

void sjfDriver(vector <vector <Process *> > batch) {

	for (int i = 0; i < batch.size(); i++) {

		cout << "Starting Shortest Job First" << endl;
        cout << "Simulation #" << i+1 << endl;

		SJF sjf;
    	sjf.simulate(batch[i]);
    }
}

#endif