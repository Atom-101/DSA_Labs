#include "multiq.h"

MultiQ createMQ(int num)
{
	MultiQ mq;
	mq.num = num;
	mq.Q = malloc(sizeof(Queue*)*num);
	for(int i=0;i<num;i++)
		mq.Q[i]=newQ();
	return mq;
}

MultiQ addMQ(MultiQ mq, Task t)
{
	addQ(mq.Q[t.pri-1],t.taskid);
}

Task nextMQ(MultiQ mq)
{	
	Task t; int taskid,i;
	for(i=mq.num-1;i>=0;i--)
	{
		if(!isEmptyQ(mq.Q[i]))
		{
			taskid = front(mq.Q[i]).elem;
			break;
		}
	}
	
	t.taskid = taskid;
	t.pri = i+1;
}

MultiQ delNextMQ(MultiQ mq)
{
	for(int i=mq.num-1;i>=0;i--)
	{
		if(!isEmptyQ(mq.Q[i]))
		{
			delQ(mq.Q[i]);
			break;
		}
	}
	
	return mq;
}

int isEmptyMQ(MultiQ mq)
{
	for(int i=mq.num-1;i>=0;i--)
	{
		if(!isEmptyQ(mq.Q[i]))
		{
			return 0;
		}
	}
	
	return 1;
}

int sizeMQ(MultiQ mq)
{
	int len =0;
	for(int i=mq.num-1;i>=0;i--)
	{
		if(!isEmptyQ(mq.Q[i]))
		{
			len+=lengthQ(mq.Q[i]);
		}
	}
	return len;
}

int sizeMQbyPriority(MultiQ mq, int pri)
{	
	return lengthQ(mq.Q[pri-1]);
}

Queue* getQueueFromMQ(MultiQ mq, int pri)
{
	return mq.Q[pri-1];
}
