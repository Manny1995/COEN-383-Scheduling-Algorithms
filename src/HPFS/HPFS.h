#ifndef HPFS_H
#define HPFS_H

#include <iostream>
#include <stdlib.h>
#include <queue>
#include "../tools/process.h"
#include <string>


using namespace std;

class HPFS {
	public:
        vector<std::vector<Process *> > container;
        HPFS();
		Process *top();
        int total_turnaround, total_waiting, total_response, total_completed;
        string timeGraph;
		void addProcess(Process *p);
		virtual void executeQuanta(int quanta){};
		void ageProcesses(int quanta);
};


#endif