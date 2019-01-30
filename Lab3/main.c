#include "que.h"

int main(int argc, char* argv[])
{
	FILE* f = fopen(argv[1],"r");
	Queue* q = newQ();
	printf("%d\n",isEmptyQ(q));
	int a,b;
	while(fscanf(f,"%d,%d",&a,&b)!=EOF)
	{
		//printf("%d\n", b);
		addQ(q,b);
	}
	
	delQ(q);
	printf("%d\n",lengthQ(q));
	return 0;
}
