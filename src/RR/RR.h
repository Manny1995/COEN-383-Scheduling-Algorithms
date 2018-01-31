#ifndef RR_H
#define RR_H

#include <iostream>
#include <stdlib.h>

#include "../tools/process.h"


using namespace std;

class RR {
	public:
		void startRR(vector<Process *> processList);
		void injectProc(double quanta);
		void runProc(double quanta);
};


#endif