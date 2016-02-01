#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include "heap.h"
void Swap_int(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void Swap_float(float *a,float *b)
{
	float temp;
	temp=*a;
	*a=*b;
	*b=temp;
}

void Min_Heapfy(PQ *heap,int vertex,int root)
{
	int c;
	while(root<=vertex/2)
	{
		c=2*root;
		if(heap[c].d>heap[c+1].d && c<vertex)
		{
			c++;
		}
		if(heap[root].d>heap[c].d)
		{
			Swap_int(&heap[root].d,&heap[c].d);
			Swap_int(&heap[root].top,&heap[c].top);
		}
		else
		{
			break;
		}
		root=c;
	}
}

int Heap_Extract_Min(PQ *heap,int *n)
{
	int key;
	key=heap[1].top;
	if(*n>1)
	{
		Swap_int(&heap[1].top,&heap[(*n)].top);
		Swap_int(&heap[1].d,&heap[(*n)--].d);
		Min_Heapfy(heap,*n,1);
	}
	else
	{
		(*n)--;
	}
	return key;
}

void Build_Min_Heap(PQ *heap,int *d,int vertex)
{
	int i;
	for(i=1;i<=vertex;i++)
	{
		heap[i].d=d[i];
		heap[i].top=i;
	}
	for(i=vertex/2;i>=1;i--)
	{
		Min_Heapfy(heap,vertex,i);
	}
}

void Decrease_key(PQ *heap,int v,int d,int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if(heap[i].top==v)
		{
			heap[i].d=d;
			while(heap[i].d<heap[i/2].d && i>1)
			{
				Swap_int(&heap[i].d,&heap[i/2].d);
				Swap_int(&heap[i].top,&heap[i/2].top);
				i=i/2;
			}
			break;
		}
	}
}