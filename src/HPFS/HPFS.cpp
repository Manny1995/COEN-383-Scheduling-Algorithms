#ifndef PQUEUE_CPP
#define PQUEUE_CPP

#include "HPFS.h"

#include <iostream>
#include <stdio.h>
#include "../tools/tools.h"
#include <queue>

using namespace std;

HPFS::HPFS() {
    total_response = 0;
    total_turnaround = 0;
    total_waiting = 0;
	total_completed = 0;
	timeGraph = "";

	for (int i = 0; i < 4; i++) {
		// In process.c I overloaded the < and > operator to sort by priority
    	std::vector<Process *> p;
		container.push_back(p);
	}
}

// gets the highest priority process
Process *HPFS::top() {
	int queue_number = -1;
	for (int i = 0; i < 4; i++){
		if(container[i].empty())
			continue;
		queue_number = i;
		break;
	}
	if(queue_number == -1){
		return NULL;
	}

	Process *top = container[queue_number][0];
	return top;
}


// adds a new process to a queue
void HPFS::addProcess(Process *p) {
	if (p == NULL) {
		cout << "Process is nil, error" << endl;
		return;
	}
	container[p->priority-1].push_back(p);
}

bool sortPQ (Process *i,Process *j) {
    return (i->arrivalTime <= j->arrivalTime);
}

void HPFS::ageProcesses(int quanta) {
    for(int queueNum = 1; queueNum < 4; queueNum++){
        for(int proc = 0; proc < container[queueNum].size(); proc++){
            int arrival = container[queueNum][proc]->arrivalTime;
            if((quanta-arrival)%5==0 && quanta-arrival!=0){
                Process *temp = container[queueNum][proc];
                container[queueNum].erase(container[queueNum].begin()+proc);
                temp->priority--;
                addProcess(temp);
            }
        }
    }

    for(int queueNum = 0; queueNum < 4; queueNum++){
        std::sort(container[queueNum].begin(), container[queueNum].end(), sortPQ);
    }
}


#endif
