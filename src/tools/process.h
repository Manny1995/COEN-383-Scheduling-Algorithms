#ifndef PROCESS_H
#define PROCESS_H

#include <vector>
#include <string>

using namespace std;

class Process {

public:
    
    Process();
    Process(float arrivalTime, float runTime, int priority);

    double startExecution(double time);

    bool hasStarted() {
        return responseTime > -1;
    }

    double finishExecution(double time) {
        return time - (arrivalTime + responseTime);
    }

    
    bool operator <(const Process &l) const {
        if (arrivalTime < l.arrivalTime) {
            return true;
        }
        return false;
    }
    
    float arrivalTime;
    float runTime;
    int priority;

    // the time that the process actually started execution
    float responseTime;

    // identifier for the time graph
    char identifier;


};

bool processPtrCompare(Process *a, Process *b);

std::vector<Process*> generateProcessVector(int numberOfProcesses);

#endif /* PROCESS_H */
