//
// Created by Maxen Chung on 1/28/18.
//

#include "HPFS_Non_Preemptive.h"
#include "../tools/process.h"

void HPFS_Non_Preemptive::executeQuanta(int quanta) {
    if(cur_proc == NULL){
        cur_proc = this->top();
        if(cur_proc == NULL)
            return;
        cur_proc->started = true;
        this->total_response += quanta - cur_proc->arrivalTime; //started - arrival
    }
    cur_proc->timeLeft--;
    if(cur_proc->timeLeft < 1){
        total_waiting += quanta - cur_proc->arrivalTime - cur_proc->runTime + 1; //completion - arrival - runtime
        total_turnaround += quanta - cur_proc->arrivalTime; //completion - arrival
        total_completed++;
        timeGraph+=cur_proc->identifier;
        container[cur_proc->priority-1].erase(container[cur_proc->priority-1].begin());
        cur_proc = NULL;
    }
}