

#ifndef RRDRIVER_CPP
#define RRDRIVER_CPP


#include "rrDriver.h"
#include "../tools/process.h"
#include "../tools/tools.h"

void rrDriver(vector <vector <Process *> > batch) {

	for (int i = 0; i < batch.size(); i++) {
		RR rr;
		rr.startRR(batch[i]);
	}
}

#endif