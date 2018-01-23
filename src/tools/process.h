#ifndef PROCESS_H
#define PROCESS_H

#include <vector>

class Process {

public:
    
    Process();
    Process(float arrivalTime, float runTime, int priority);
    
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
    float startTime;
    float responseTime;
    

};

bool processPtrCompare(Process *a, Process *b);

std::vector<Process*> generateProcessVector(int numberOfProcesses);

#endif /* PROCESS_H */
