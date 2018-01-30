

#ifndef SJFDRIVER_CPP
#define SJFDRIVER_CPP


#include "sjfDriver.h"
#include "../tools/process.h"
#include "../tools/tools.h"

void sjfDriver(vector <vector <Process *> > batch) {

	for (int i = 0; i < batch.size(); i++) {
		SJF sjf;
    	sjf.simulate(batch[i]);
    }
}

#endif