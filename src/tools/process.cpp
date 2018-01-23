#include "process.h"
#include "tools.h"

Process::Process() {
    arrivalTime = generate::arrivalTime();
    runTime = generate::runTime();
    priority = generate::priority();
}


Process::Process(float arrivalTime, float runTime, int priority) {
	this->arrivalTime = arrivalTime;
	this->runTime = runTime;
	this->priority = priority;
}


bool processPtrCompare(Process* a, Process* b) {
    return (a->arrivalTime < b->arrivalTime);
}
