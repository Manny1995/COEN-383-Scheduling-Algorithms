#ifndef STR_CPP
#define STR_CPP

#include "STR.h"

#include <iostream>
#include <stdio.h>
#include <limits>

#include "../tools/process.h"

using namespace std;



void STR::startSimulation(vector<Process *> processList) {

	int i = 0;


	int jobsStarted = 0;
	double totalResponseTime = 0;
	double totalTurnaroundTime = 0;
	int jobsFinished = 0;
	Process *currProc;
	double waitTime[100] = {0};
	double startTime[100] = {0};
	double finishedTime[100] = {0};
	int currentLocation;
	float originalRT[100]; 
	bool checked = false;
	double tempDur = 0;
	double wtime = 0;
	string timeGraph = "";
	int finished;
	double cur_time = 0.0;
	bool completed = false;

	int t = 0;
	for(Process *c : processList){
		originalRT[t] = c->runTime;
	}

	while (!completed) {

		cur_time+=0.1;

		if (processList.empty()) {
			break;
		}

		int x = 0;
		double minTime = numeric_limits<double>::max();
		for (Process *c : processList) {
            if ((c->arrivalTime <= cur_time) &&
            (c->runTime < minTime) && (c->runTime > 0)) {
                minTime = c->runTime;
                currProc = c;
                checked = true;
                currentLocation = x;
            }
            x++;
        }
        x = 0;
        for(Process *c : processList){
        	if(c->runTime > 0 && x != currentLocation){
        		waitTime[x] = waitTime[x] + 0.1;
        	}
        	x++;
        }

        if(!checked){
        	continue;
        }

        if(currProc->runTime == originalRT[currentLocation]){
			totalResponseTime += cur_time;
			jobsStarted+=1;
			startTime[currentLocation] = cur_time;
		}


        currProc->runTime-= (double) 0.1;
        timeGraph+=currProc->identifier;
		
		if (currProc->runTime <= 0) {
			jobsFinished+=1;
			finishedTime[currentLocation] = cur_time;
		}


		completed = true;
		cout << "STARTTTTTTTTTTTTTTTTTTTTT" << endl;
		for(Process *c : processList){
			if(c->runTime >= 0){
				completed = false;
			}
			cout <<"current run times left" << c->runTime << endl;
		}

	}
	int p = 0;
	//finished = 0;
	for (Process *c : processList) {
		// if(c->runTime <= 0){
		// 	finished++;
		// }
		totalTurnaroundTime += (finishedTime[p] - startTime[p]);
		wtime += (waitTime[p] - c->arrivalTime);
		p++;
	}


	cout << "Avg response time is " << totalResponseTime/jobsStarted << endl;
	cout << "Avg waiting time is " << wtime << endl;
	cout << "Avg Turnaround time is " << totalTurnaroundTime / 100 << endl;
	cout << "Throughoutput is " << 100 / cur_time << endl;
	cout << "Time graph is " << timeGraph << endl;
}


#endif
