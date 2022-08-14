//Rivka Salem 8/22
#include "oslabs.h"

//NULLPCB[PID:0, AT:0, TBT:0, EST:0, EET:0, RBT:0, Priority:0]

/*
struct NULLPCB(){
        process_id =0;
        arrival_timestamp=0;
        total_bursttime=0;
        execution_starttime=0;
        execution_endtime=0;
        remaining_bursttime=0;
        process_priority=0;
};
*/
struct PCB handle_process_arrival_pp(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, struct PCB current_process, struct PCB new_process, int timestamp)
{
    if((current_process.process_id == 0)&&
       (current_process.arrival_timestamp==0)&&
       (current_process.total_bursttime==0)&&
       (current_process.execution_starttime==0)&&
       (current_process.execution_endtime==0)&&
       (current_process.remaining_bursttime==0)&&
       (current_process.process_priority==0))
    {
        new_process.execution_starttime= timestamp;
        new_process.execution_endtime=timestamp + new_process.total_bursttime;
        new_process.remaining_bursttime = new_process.total_bursttime;
        return new_process;
    }
    //if theres current process... compare and check which priority is higher

    else if(new_process.process_priority>=current_process.process_priority)
    {
        new_process.execution_starttime =0;
        new_process.execution_endtime=0;
        new_process.remaining_bursttime = new_process.total_bursttime;
        ready_queue[*queue_cnt]=new_process;
        (*queue_cnt)++;
        return current_process;

        }
    else
    {
        new_process.execution_starttime= timestamp;
        new_process.execution_endtime=timestamp + new_process.total_bursttime;
        new_process.remaining_bursttime = current_process.execution_endtime - timestamp;
        current_process.execution_endtime=0;
        ready_queue[*queue_cnt]=current_process;
        (*queue_cnt)++;
        return new_process;
        }

}
struct PCB handle_process_completion_pp(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, int timestamp)
{
   return NULL;
}
struct PCB handle_process_arrival_srtp(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, struct PCB current_process, struct PCB new_process, int time_stamp)
{
   return NULL;
}
struct PCB handle_process_completion_srtp(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, int timestamp)
{
   return NULL;
}
struct PCB handle_process_arrival_rr(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, struct PCB current_process, struct PCB new_process, int timestamp, int time_quantum)
{
   return NULL;
}
struct PCB handle_process_completion_rr(struct PCB ready_queue[QUEUEMAX], int *queue_cnt, int timestamp, int time_quantum)
{
   return NULL;
}
