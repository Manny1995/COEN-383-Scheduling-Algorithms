//
// Created by Maxen Chung on 1/28/18.
//

#include "HPFS_Preemptive.h"
#include "../tools/process.h"


void HPFS_Preemptive::executeQuanta(int quanta){
    Process *cur_proc = this->top();
    if(cur_proc == NULL)
        return;
    if(!cur_proc->started){
        cur_proc->started = true;
        this->total_response += quanta - cur_proc->arrivalTime;
    }
    cur_proc->runTime--;
    if(cur_proc->runTime == 0){
        this->total_waiting += quanta - cur_proc->arrivalTime - cur_proc->runTime + 1;
        this->total_turnaround += quanta - cur_proc->arrivalTime;
        this->total_completed++;
        this->timeGraph+=cur_proc->identifier;
        this->container[cur_proc->priority-1].erase(container[cur_proc->priority-1].begin());
        cur_proc = NULL;
    }
}
