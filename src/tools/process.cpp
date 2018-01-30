#include "process.h"
#include "tools.h"

using namespace std;

Process::Process() {
    arrivalTime = generate::arrivalTime();
    runTime = generate::runTime();
    priority = generate::priority();
    responseTime = -1;
    started = false;
}


Process::Process(float arrivalTime, float runTime, int priority) {
	this->arrivalTime = arrivalTime;
	this->runTime = runTime;
	this->priority = priority;
    this->responseTime = -1;
    this->started = false;

}

Process::Process (Process &p) {
    this->arrivalTime = p.arrivalTime;
    this->runTime = p.runTime;
    this->priority = p.priority;
    this->responseTime = p.responseTime;
    this->identifier = p.identifier;
    this->started = p.started;
}


// call this once execution is started to get the response time
double Process::startExecution(double time) {
    this->responseTime = time - this->arrivalTime;
    return this->responseTime;
}


bool processPtrCompare(Process* a, Process* b) {
    return (a->arrivalTime < b->arrivalTime);
}


std::vector<Process*> generateProcessVector(int numberOfProcesses) {

    std::vector<Process*> processVector;

    for(int i = 0 ; i < numberOfProcesses ; i++) {
        processVector.push_back(new Process());
    }

    return processVector;

}


// Sort the priority in an order where greatest first!
bool operator < (Process& lhs, Process& rhs)
{
    return lhs.priority >= rhs.priority;
}

bool operator > (Process& lhs, Process& rhs)
{
    return lhs.priority < rhs.priority;
}

