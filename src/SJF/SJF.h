#include <list>
#include <vector>
#include "../tools/process.h"

class SJF {

public:
    SJF();
    ~SJF();
    void simulate(std::vector<Process*> processList);

private:
    std::list<Process*> sjfSort(std::list<Process*> pList);
    void calculateStatistics(std::list<Process*> pList);

};
