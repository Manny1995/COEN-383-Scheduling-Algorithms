#ifndef PROCESS_H
#define PROCESS_H

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

};

bool processPtrCompare(Process *a, Process *b);

#endif /* PROCESS_H */
