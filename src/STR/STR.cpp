#ifndef STR_CPP
#define STR_CPP

#include "STR.h"

#include <iostream>
#include <stdio.h>
#include <limits>
#include <string>

#include "../tools/process.h"

using namespace std;



void STR::startSimulation(vector<Process *> processList) {

	int i = 0;
	double totalResponseTime = 0;
	double totalTurnaroundTime = 0;
	int jobsFinished = 0;
	Process *currProc;
	double waitTime[100] = {0};
	double startTime[100] = {0};
	double finishedTime[100] = {0};
	int currentLocation;
	float originalRT[100];
	double tempDur = 0;
	double wtime = 0;
	string timeGraph = "";
	int finished;
	double cur_time = 0.0;
	bool completed = false;


	//Initialize orignial runtime array
	//used to see if the current job has started 
	for(Process *c : processList){
		originalRT[i] = c->runTime;
		i++;
	}

	while (!completed) {

		cur_time+=0.1;
		i = 0;
		double minTime = numeric_limits<double>::max();
		currentLocation = -1;


		//Locating the process with the shortest run time
		//sets the current location index for global arrays
		//sets checked flag for when there are no processes eligble to run
		for (Process *c : processList) {
            if ((c->arrivalTime <= cur_time) &&
            (c->runTime < minTime) && (c->runTime > 0)) {
                minTime = c->runTime;
                currProc = c;
                currentLocation = i;
            }
            i++;
        }



        i = 0;
        //Increment the wait time for all of the processes not running
        for(Process *c : processList){
        	if((c->runTime >= 0) && (i != currentLocation) && (c->arrivalTime <= cur_time)){
        		waitTime[i] = waitTime[i] + 0.1;
        	}
        	i++;
        }


        //If there isn't a process running at this time then:
        //skip to the next time quanta
        if(currentLocation == -1){
        	continue;
        }


        //check to see if the current process has just started 
        //adding this time to the total response time
        //increment the counter for the 
        if(currProc->runTime == originalRT[currentLocation]){
			totalResponseTime += cur_time;
			startTime[currentLocation] = cur_time;
		}


		//decrement the run time of the current process
		//add the current process to the time graph
        currProc->runTime-= (double) 0.1;
        timeGraph+=currProc->identifier;
		

		//checks to see if the current process has finished
		//if so then increment the number of job completed 
		//and set the current time as the finished time for the current process
		if (currProc->runTime <= 0) {
			jobsFinished+=1;
			finishedTime[currentLocation] = cur_time;
		}

		//checks to see if all the processes have completed
		//if the processes have been completed then the loop will break
		if(jobsFinished == processList.size()){
			completed = true;
		}

	}

	//calculate the total turnaround time
	//calculate the total waiting time
	cout << "pid   a time   e time   r time.  w time" << endl;
	i = 0;
	for (Process *c : processList) {
		totalTurnaroundTime += (finishedTime[i] - startTime[i]);
		wtime += (waitTime[i]);
		cout << c->identifier << "       " << c->arrivalTime << "       " << finishedTime[i] << "      " << originalRT[i] << "       " << waitTime[i] << endl;
		i++;
	}
	for(i= 0; i < cur_time * 10; i++){
		if(i % 10 == 0){
			cout << "Quanta " << (i / 10) <<  ": " << timeGraph[i] <<  " ";
		} else if((i+1) % 10 == 0){
			cout << timeGraph[i] << " " << endl;
		} else {
			cout << timeGraph[i] << " ";
		}
	}

	cout << " " << endl;
	cout << "Avg response time is " << totalResponseTime/processList.size() << endl;
	cout << "Avg waiting time is " << wtime / processList.size() << endl;
	cout << "Avg Turnaround time is " << totalTurnaroundTime / processList.size() << endl;
	cout << "Throughoutput is " << processList.size() / cur_time << endl;
}


#endif
