#ifndef PROCESS_H
#define PROCESS_H

#include <vector>
#include <string>

using namespace std;

class Process {

public:
    
    Process();
    Process(float arrivalTime, float runTime, int priority);
    Process(Process &p);

    double startExecution(double time);
    
    
    float arrivalTime;
    float runTime;
    float startTime; //time the process first executes
    int priority;

    float timeLeft;

    bool started;

    // identifier for the time graph
    char identifier;

    friend bool operator < ( Process& lhs,  Process& rhs);
    friend bool operator > ( Process& lhs,  Process& rhs);

};

bool processPtrCompare(Process *a, Process *b);

std::vector<Process*> generateProcessVector(int numberOfProcesses);

#endif /* PROCESS_H */
