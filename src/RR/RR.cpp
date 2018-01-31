/*
 * Isaac Jorgensen
 * roundrobin.cpp
 *
 * NOTE: All comments denote what changes need to be made in order
 * for a main from a separate file to access and run these contents.
*/

#ifndef RR_CPP
 #define RR_CPP

#include <iostream>
#include <queue>

#include "RR.h"
 #include "../tools/tools.h"
using namespace std;
using namespace generate;

vector<Process *> procs;
queue<Process *> procQueue;
double avgTurn;
double avgWait;
double avgResp;

void RR::injectProc(double quanta){
        //inject the process(es) into the queue upon its arrival time
        while(procs[0]->arrivalTime == (double)quanta){ //seg faulting here, trying to access procs[0]
		    if(procs.size() != 0){
            procQueue.push(procs[0]);
            procs.erase(procs.begin());
            }else{ 
                break;
            }
	    }

}

void RR::runProc(double quanta){
    if(procQueue.size() > 0){
        if(!(procQueue.front())->started){
            (procQueue.front())->startExecution((double)quanta);
        }  
        (procQueue.front())->runTime-=1;
        
        cout << "Quanta " << quanta << ": pid " << (procQueue.front())->identifier << endl;
        
        //calculating metrics when process finished
        if((procQueue.front())->runTime <= 0){ 
            avgTurn += ((float)quanta - (procQueue.front())->startTime);
            avgWait += ((float)quanta - (procQueue.front())->arrivalTime);
            avgResp += (((procQueue.front())->startTime)-((procQueue.front())->arrivalTime));
            procQueue.pop();
        }else{
            //moving the top process to the back of the queue
            Process *temp = procQueue.front();
            procQueue.pop();
            procQueue.push(temp);
        }
    }
}

void RR::startRR(vector<Process *> inProcs){ //--replace the following line
//int main(){
    //comment out 'procs' once main is changed and uncomment the procs = inProcs assignment line
    //procs = generateProcessList();
    procs = inProcs;
    int num = procs.size();
    double quanta = 0;
    avgTurn = 0;
    avgWait = 0;
    avgResp = 0;
	while(quanta < 110 || !procQueue.empty()){
		injectProc(quanta);
		runProc(quanta);
        quanta += 1;
	}
    cout << "Turnaround         Wait            Response" << endl;
    cout << "--------------------------------------------" << endl;
    cout << avgTurn/num << "               " << avgWait/num << "              " << avgResp/num << endl;
    cout << "Throughput: " << num/quanta << endl; 

}

#endif
