#ifndef HPFS_H
#define HPFS_H

#include <iostream>
#include <stdlib.h>
#include <queue>

#include "../tools/process.h"


using namespace std;

class HPFS {
	private:
		vector<std::priority_queue<Process *, std::vector<Process *> > > container;
		int curQueue;
		void nextQueue();
	public:
		HPFS();
		Process *top();
		void addProcess(Process *p, int q);
		Process *executeQuanta(double quanta); // NOT FINISHED YET


};


#endif