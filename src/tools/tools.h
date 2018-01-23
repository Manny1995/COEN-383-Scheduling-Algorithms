//
// Carlos Rivera
// rand.h
//
// Interface for processes information generation

#ifndef TOOLS_H
#define TOOLS_H

#include "process.h"

namespace generate {


	vector<Process *> generateProcessList() {
	Process *generateNewProcess();
    
    
    float arrivalTime();
    float runTime();
    int priority();

}

#endif /* TOOLS_H */
