#ifndef _HEAP_H_
#define _HEAP_H_

typedef struct 
{
	int top,d;
	//float d;
}PQ;

void Swap_int(int *a,int *b);
void Swap_float(float *a,float *b);
void Min_Heapfy(PQ *heap,int vertex,int root);
void Build_Min_Heap(PQ *heap,int *d,int vertex);
void Decrease_key(PQ *heap,int v,int d,int n);
int Heap_Extract_Min(PQ *heap,int *n);

#endif