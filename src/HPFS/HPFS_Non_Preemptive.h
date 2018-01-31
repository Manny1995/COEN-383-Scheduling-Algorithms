//
// Created by Maxen Chung on 1/28/18.
//

#include "HPFS.h"
#ifndef COEN_383_SCHEDULING_ALGORITHMS_HPFS_NON_PREEMPTIVE_H
#define COEN_383_SCHEDULING_ALGORITHMS_HPFS_NON_PREEMPTIVE_H


class HPFS_Non_Preemptive : public HPFS {
private:
    Process *cur_proc;
public:
    HPFS_Non_Preemptive() : HPFS(){
        cur_proc = NULL;
    };
    void executeQuanta(int quanta);
};


#endif //COEN_383_SCHEDULING_ALGORITHMS_HPFS_NON_PREEMPTIVE_H
