#ifndef FCFSQUEUE_H
#define FCFSQUEUE_H

#include <iostream>
#include <stdlib.h>

using namespace std;

class FCFSQueue {
	private:
		queue<Process *> container;
	public:
		FCFSQueue();
		Process *pop();
		void push(Process *);
};


#endif