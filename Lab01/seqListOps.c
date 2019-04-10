/***********file:   Ops.c *********/
#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;

SeqList createlist()
{
 SeqList sl;
 sl.head = nextfreeloc++;
 sl.size = 0;
 st[sl.head].next = -1;
 return (sl);
}

void printJob (Job j)
{
printf ("JOB ID = %d, Priority = %d, Arr time = %d, Arrival time = %d \n",j.id,j.pri,j.et,j.at);
}


int inputJobs (JobList list)
{
 int i; int size;

 printf("\n Enter the Number of Jobs :");
 scanf("%d", &size);

 for (i=0;i<size;i++)
 {
  printf ("\nEnter job ID");
  scanf ("%d",&list[i].id);
  printf ("Enter Priority (from 0 - 2)");
  scanf ("%d",&list[i].pri);
  printf ("Execution Time");
  scanf ("%d",&list[i].et);
  printf ("Arrival Time");
  scanf ("%d",&list[i].at);
 }
 return size;
}

SeqList insert(Job j , SeqList sl)
{

//Implement this function
//
    int pointer = st[sl.head].next;
    int prev = sl.head;
    
    if(sl.size==0)
    {
    	st[prev].ele = j;
    	sl.size++;
    }
    
    if(compare(j,st[prev].ele)==LESSER)
    {
    	sl.head = nextfreeloc;
    	st[nextfreeloc].next = prev;
    	st[nextfreeloc].ele = j;
    	sl.size++;nextfreeloc++;
    }   	
    
    
    while(st[pointer].next != -1)
    {    	
        int com = compare(j,st[pointer].ele);
        if(com==LESSER)
        {
        	st[prev].next = nextfreeloc;
        	st[nextfreeloc].ele = j;
        	st[nextfreeloc].next = pointer;
        	nextfreeloc++; sl.size++;
        	return;
        }
        else
        {
        	prev = pointer;
        	pointer = st[pointer].next;
        }	
        	
        
    }
    st[nextfreeloc].ele = j;
    st[nextfreeloc].next = -1;
    st[prev].next = nextfreeloc;
    nextfreeloc++; sl.size++;    
        
 }
  
void insertelements (JobList list, int size, SeqList s[3])
{

// Implement this function
	for(int i=0;i<3;i++)
		s[i] = createlist();
			
	//int size = inputJobs(list);
	for(int i=0;i<size;i++)
		insert(list[i],s[list[i].pri]);
		
	
	
	

}

void copy_sorted_ele(SeqList s[3] , JobList ele)
{

// Implement this function
	int k=0;
	for(int i =0; i<3;i++)
	{
		int pointer = s[i].head;
		while(pointer != -1)
		{
			ele[k] = st[pointer].ele;
			pointer = st[pointer].next;
			k++;
		}
	}

}

void printlist(SeqList sl)
{

// Implement this function
	int pointer = sl.head;
	while(pointer != -1)
	{
		printJob(st[pointer].ele);
		pointer = st[pointer].next;
	}

}

void printJobList(JobList list, int size)
{

// Implement this function

	for(int i=0;i<size;i++)
		printJob(list[i]);

}

void sortJobList(JobList list, int size)
{
 SeqList seq[3];
 seq[0] = createlist();
 seq[1] = createlist();
 seq[2] = createlist();
 insertelements (list, size, seq);
 printlist(seq[0]);   
 printlist(seq[1]);
 printlist(seq[2]);
 copy_sorted_ele (seq , list); 
}
