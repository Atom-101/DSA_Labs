#include "que.h"


#ifndef _MULTIQ
#define _MULTIQ
typedef struct mq{
	Queue** Q;
	int num;
}MultiQ;

typedef struct T{
	int taskid;
	int pri;
}Task;

MultiQ createMQ(int num);
MultiQ addMQ(MultiQ mq, Task t);
MultiQ delNextMQ(MultiQ mq);
int isEmptyMQ(MultiQ mq);
int sizeMQ(MultiQ mq);
int sizeMQbyPriority(MultiQ mq, int pri);
Queue* getQueueFromMQ(MultiQ mq, int pri);
#endif
