//Rivka Salem 8/22
#include "oslabs.h"

#ifndef CPU_OSLABS_H
#define CPU_OSLABS_h
#define QUEUEMAX 10
#define MAPMAX 10
#define TABLEMAX 10
#define POOLMAX 10
#define REFERENCEMAX 20
//#define MAX(a,b) ((a>b)?a:b)
//#define MIN(a,b) ((a>b)?b:a)

//NULLPCB[PID:0, AT:0, TBT:0, EST:0, EET:0, RBT:0, Priority:0]


struct NULLPCB(PCB){
        process_id =0;
        arrival_timestamp=0;
        total_bursttime=0;
        execution_starttime=0;
        execution_endtime=0;
        remaining_bursttime=0;
        process_priority=0;

};
struct PCB handle_process_arrival_pp(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, struct PCB current_process, struct PCB new_process, int timestamp)
{
    /*If no current running process (current process is nullpcb
    */
    if(current_process == NULLPCB)
    {
        /*method returns PCB of newly arriving process
        PCB of new process- modify so execution start is = to current timestamp
        execution end time = timestamp + total burst time.
        remaining burst time = total bursttime.
        */
        PCB.execution_starttime= timestamp;
        PCB.execution_endtime=timestamp + PCB.total_bursttime;
        PCB.remaining_bursttime = PCB.total_bursttime;
        return new_process;
    }
    //if theres current process... compare and check which priority is higher
    if(current_process!= NULLPCB)
    {
        if(PCB.process_priority>=new_process.process_priority)
        {
            ready_queue.insert(new_process);
            new_process.execution_starttime =0;
            new_process.execution_endtime=0;
            new_process.remaining_bursttime = new_process.total_bursttime;
        }
        if(PCB.process_priority>new_process)
        {
            ready_queue.insert(current_process);
            current_process.execution_starttime= timestamp;
            current_process.execution_endtime=timestamp + PCB.total_bursttime;
            PCB.remaining_bursttime = PCB.total_bursttime;
            current_process.execution_endtime=0;
        }
    }
};
struct PCB handle_process_completion_pp(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, int timestamp)
{

};
struct PCB handle_process_arrival_srtp(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, struct PCB current_process, struct PCB new_process, int time_stamp)
{

};
struct PCB handle_process_completion_srtp(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, int timestamp)
{

};
struct PCB handle_process_arrival_rr(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, struct PCB current_process, struct PCB new_process, int timestamp, int time_quantum)
{

};
struct PCB handle_process_completion_rr(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, int timestamp, int time_quantum)
{

};

#endif // CPU_OSLABS_H
