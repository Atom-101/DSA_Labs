#include "multiq.h"
#include "que.h" 

#define foreach(i,num) for(int i=0;i<num;i++)

MultiQ loadData(FILE* f)
{
	MultiQ mq = createMQ(10);
	int a,b;
	while(fscanf(f,"%d,%d",&a,&b)!=EOF)
	{
		Task t;
		t.taskid = a; t.pri = b;
		addMQ(mq,t);
	}
	
	return mq;
}

MultiQ testDel(MultiQ mq,int num)
{
	foreach(i,num)
	{
		mq = delNextMQ(mq);
	}
	
	return mq;
}

int main(int argc, char* argv[])
{
//	MultiQ mq = createMQ(3);
//	printf("%d\n",isEmptyQ(mq.Q[0]));
//	printf("%d\n",isEmptyQ(mq.Q[1]));
//	printf("%d\n",isEmptyQ(mq.Q[2]));
	
	FILE* f = fopen(argv[1],"r");
	MultiQ mq = loadData(f);
	mq = testDel(mq,5);
	
	printf("%d\n",sizeMQ(mq));
	
	
	return(0);

}
