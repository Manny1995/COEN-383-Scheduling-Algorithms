//
// Created by Maxen Chung on 1/30/18.
//



#include "HPFS_Non_Preemptive.h"
#include "../tools/process.h"
#define NUM_QUANTA 100
using namespace std;

void simulate_hpfs_non_preemptive(vector < Process * > processList){
    HPFS_Non_Preemptive* queue = new HPFS_Non_Preemptive;
    int cur_proc = 0;
    for(int quanta = 0; quanta < NUM_QUANTA; quanta++){
        while(cur_proc < processList.size() && processList[cur_proc]->arrivalTime <= quanta){
            queue->addProcess(processList[cur_proc]);
            cur_proc++;
        }

        //timeGraph+=cur_proc->identifier;
        if (queue->top() != NULL)
            cout << queue->top()->identifier << endl;

        queue->executeQuanta(quanta);
        queue->ageProcesses(quanta);
    }

    int completed = queue->total_completed;
    cout << "Stats" << endl;
    cout << "----------------" << endl;
    cout << "Avg response time is " << queue->total_response/completed << endl;
    cout << "Avg waiting time is " << queue->total_waiting/completed << endl;
    cout << "Avg Turnaround time is " << queue->total_turnaround/completed << endl;
    cout << "Throughouput is " << ((double)completed)/((double)NUM_QUANTA) << endl;
    cout << "Timegraph is " << queue->timeGraph << endl;

}

void printProcessListNP(vector<Process *> &processList) {
    cerr << "ajsdk" << endl;

    cout << "\tP name\t|\tArrival\t|\tDur\t|\tPri" << endl;
    cout << "---------------------------------------------------------------" << endl;
    for (int i = 0; i < processList.size(); i++) {

        Process *p = processList[i];
        cout << "\t" << p->identifier << "\t|\t" << p->arrivalTime << "\t|\t" << p->runTime << "\t|\t" << p->priority << endl;  
    }

    cout << "---------------------------------------------------------------" << endl;
    cout << "\n" << endl;
}


void hpfsNpDriver(vector <vector <Process *> > batch){


    for (int i = 0; i < batch.size(); i++) {
        printProcessListNP(batch[i]);
        simulate_hpfs_non_preemptive(batch[i]);
    }
}