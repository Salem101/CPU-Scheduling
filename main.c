#include <stdio.h>
#include <stdlib.h>
#include "oslabs.h"

void print_entry(struct PCB process)
{
        printf("{%d %d %d %d %d %d %d }\n",
            process.process_id,
            process.arrival_timestamp,
            process.total_bursttime,
            process.execution_starttime,
            process.execution_endtime,
            process.remaining_bursttime,
            process.process_priority)
};

void testcase_pp1()
{
    struct PCB ready_queue[QUEUEMAX];
    struct PCB current_process = {1, 1, 4, 1, 5, 4, 8};
    struct PCB new_process = {2, 2, 3, 0, 0, 3, 6};
    struct PCB process;
    int queue_cnt = 0;
    int timestamp = 2;

    memset(ready_queue, 0, sizeof(ready_queue, 0, sizeof(ready_queue[QUEUEMAX]))
    process = handle_process_arrival_pp(ready_queue, &queue_cnt, current_process, new_process, timestamp);

    /*print out current process*/
    print_entry(process);

    printf("\nqueue count = %d \n\n", queue_cnt);

    for(int i =0; i<queue_cnt; i++){
        print_entry(ready_queue[i]);
    }
}
int main()
{
    testcase_pp1();
    printf("Hello world!\n");
    return 0;
}
