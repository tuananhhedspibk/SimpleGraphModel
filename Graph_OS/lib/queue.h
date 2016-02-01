#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct 
{
	int key;
	struct node *next;
}node;
typedef struct 
{
	node *front,*rear;
}queue;
void Initialize(queue *q);
int isEmpty(queue *q);
void Enqueue(queue *q,int key);
int Dequeue(queue *q);
void Print(queue q);
int Count(queue q);
void Search(queue q,int key);