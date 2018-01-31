#include "process.h"
#include "tools.h"

using namespace std;

Process::Process() {
    this->arrivalTime = generate::arrivalTime();
    this->runTime = generate::runTime();
    this->priority = generate::priority();
    this->startTime = 0;
    this->timeLeft = runTime;
    this->started = false;
    this->identifier = 'N';
}


Process::Process(float arrivalTime, float runTime, int priority) {
	this->arrivalTime = arrivalTime;
	this->runTime = runTime;
	this->priority = priority;
    this->timeLeft = runTime;
    this->started = false;
    this->startTime = 0;
    this->identifier = 'N';

}

Process::Process (Process &p) {
    this->arrivalTime = p.arrivalTime;
    this->runTime = p.runTime;
    this->priority = p.priority;
    this->timeLeft = p.timeLeft;
    this->identifier = p.identifier;
    this->started = p.started;
    this->startTime = p.startTime;
}


// call this once execution is started to get the response time
double Process::startExecution(double time) {
    this->timeLeft = time - this->arrivalTime;
    this->started = true;
    this->startTime = time;
    return this->timeLeft;
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

