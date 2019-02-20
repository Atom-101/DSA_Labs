#include "MergeSort.h"

int main()
{
	FILE* fileptr = fopen("10240.txt","r");
	Element* Ls = malloc(sizeof(Element)*10240);
	int i=0;
	while(fscanf(fileptr,"%[^,],%f\n",Ls[i].name,&(Ls[i].cgpa))!=EOF)
		i++;
		
	printf("%f\n",Ls[0].cgpa);
	printf("%f\n",Ls[1].cgpa);
	printf("%f\n",Ls[2].cgpa);
	printf("%f\n",Ls[3].cgpa);
	printf("%f\n\n\n",Ls[4].cgpa);
	
	iterMergeSort(Ls,10240);
	
	printf("%f\n",Ls[0].cgpa);
	printf("%f\n",Ls[1].cgpa);
	printf("%f\n",Ls[2].cgpa);
	printf("%f\n",Ls[3].cgpa);
	printf("%f\n",Ls[4].cgpa);
	
	return 0;
}
