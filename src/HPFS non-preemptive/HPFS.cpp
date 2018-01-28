#ifndef PQUEUE_CPP
#define PQUEUE_CPP

#include "HPFS.h"

#include <iostream>
#include <stdio.h>

#include "../tools/process.h"
#include <queue>

using namespace std;





HPFS::HPFS() {


	for (int i = 0; i < 4; i++) {

		// In process.c I overloaded the < and > operator to sort by priority
		// Please take a look in case though!
    	std::priority_queue<Process *, std::vector<Process *> > p;
		container.push_back(p);
	}

	curQueue = 0;

}

// takes in the duration and subtracts it from the top process
// TODO
Process *executeQuanta(double quanta) {

	return NULL;	
}

// gets the top (current process) that is running.
Process *HPFS::top() {

	int flag = 0;
	while (container[curQueue].empty() == true) {
		if (flag == container.size()) {
			cout << "All queues empty" << endl;
			return NULL;
		}
		flag++;
	}

	Process *top = container[curQueue].top();
	return top;
}

// switches over to the next priority queue
void HPFS::nextQueue() {
	curQueue++;
	if (curQueue >= 4) {
		curQueue = 0;
	}
}

// adds a new process to a queue (by number between 0 and 4)
void HPFS::addProcess(Process *p, int q) {

	if (q > 4 || q < 0) {
		cout << " need a queue between 0 and 4 " << endl;
		return;
	}

	if (p == NULL) {
		cout << "Process is nil, error" << endl;
		return;
	}

	container[q].push(p);

}


#endif
