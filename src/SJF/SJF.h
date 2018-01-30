#include <list>
#include <vector>
#include "../tools/process.h"

#ifndef SJF_H
#define SJF_H

class SJF {

public:
    SJF();
    ~SJF();

    // start simulation
    void simulate(std::vector<Process*> processList);

private:

    // used to sort list of processes into
    // the order they would be handled in SJF
    std::list<Process*> sjfSort(std::list<Process*> pList);

    // calculate 
    // - avg waiting time
    // - avg turnaroudn time
    // - avg response time
    // - generate quanta graph
    void calculateStatistics(std::list<Process*> pList, float totalTime);

};

#endif
