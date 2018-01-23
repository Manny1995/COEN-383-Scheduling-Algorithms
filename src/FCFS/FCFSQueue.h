#ifndef FCFSQUEUE_H
#define FCFSQUEUE_H

#include <iostream>
#include <stdlib.h>
#include <queue>

#include "../tools/process.h"


using namespace std;

class FCFSQueue {
	private:
		queue<Process *> container;
	public:
		FCFSQueue();
		Process *top();
		void pop();
		void push(Process *);
		bool isEmpty();
		void startSimulation(vector<Process *> processList);
};


#endif