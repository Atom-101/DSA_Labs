#include "MergeSort.h"

int main()
{
	FILE* fileptr = fopen("10240.txt","r");
	Element* Ls = malloc(sizeof(Element)*10240);
	int i=0;
	while(fscanf(fileptr,"%[^,],%f\n",Ls[i].name,&(Ls[i].cgpa))!=EOF)
		i++;
		
	// Element* Ls = malloc(sizeof(Element)*6);
	// /*Ls[0].name = "aaaaaaaaaa";*/ Ls[0].cgpa = 2;
	// /*Ls[1].name = "aaaaaaaaaa";*/ Ls[1].cgpa = 45;
	// /*Ls[2].name = "aaaaaaaaaa";*/ Ls[2].cgpa = 16;
	// /*Ls[3].name = "aaaaaaaaaa";*/ Ls[3].cgpa = 32;
	// /*Ls[4].name = "aaaaaaaaaa";*/ Ls[4].cgpa = 99;
	// /*Ls[5].name = "aaaaaaaaaa";*/ Ls[5].cgpa = 42;
	
	printf("%f\n",Ls[0].cgpa);
	printf("%f\n",Ls[1].cgpa);
	printf("%f\n",Ls[2].cgpa);
	printf("%f\n",Ls[3].cgpa);
	printf("%f\n\n\n",Ls[4].cgpa);
	
	iterMergeSort(Ls,10240);
	
	// printf("%f\n",Ls[0].cgpa);
	// printf("%f\n",Ls[1].cgpa);
	// printf("%f\n",Ls[2].cgpa);
	// printf("%f\n",Ls[3].cgpa);
	// printf("%f\n",Ls[4].cgpa);
	FILE* sav = fopen("Save.txt","w");
	for (int i=0;i<10240;i++)
		fprintf(sav,"%s\t%f\n",Ls[i].name,Ls[i].cgpa);
}
