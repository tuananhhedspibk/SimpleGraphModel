#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "queue.h"
void Initialize(queue *q)
{
	q->front=NULL;
	q->rear=NULL;
}
int isEmpty(queue *q)
{
	if(q->front==NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void Enqueue(queue *q,int key)
{
	node *p;
	p=(node *)malloc(sizeof(node));
	if(p==NULL)
	{
		perror("Have error.\n");
	}
	else
	{
		p->key=key;
		if(isEmpty(q)==1)
		{
			p->next=NULL;
			q->front=p;
			q->rear=p;
		}
		else
		{
			(q->rear)->next=p;
			q->rear=p;
			p->next=NULL;
		}
	}
}
int Dequeue(queue *q)
{
	node *p;
	int key;
	if(isEmpty(q)==1)
	{
		printf("Empty queue.Can't Dequeue.\n");
	}
	else
	{
		if(q->front==q->rear && q->front!=NULL)
		{
			p=q->front;
			q->front=NULL;
			q->rear=NULL;
			key=p->key;
			free(p);
		}
		else if(q->front!=q->rear && q->front !=NULL && q->rear!=NULL)
		{
			p=q->front;
			q->front=p->next;
			key=p->key;
			free(p);
		}
		return key;
	}
}
void Print(queue q)
{
	node *p;
	p=q.front;
	if(p==NULL)
	{
		printf("Empty queue.\n");
	}
	else
	{
		while(p!=NULL)
		{
			printf("%d ",p->key);
			p=p->next;
		}	
		printf("\n");
	}
}
int Count(queue q)
{
	node *p;
	int k=0;
	p=q.front;
	while(p!=NULL)
	{
		k++;
		p=p->next;
	}
	return k;
}
void Search(queue q,int key)
{
	int i=0,k=0;
	node *p;
	p=q.front;
	if(p==NULL)
	{
		printf("Empty queue.Can't Search.\n");
	}
	else
	{
		while(p!=NULL)
		{
			i++;
			if(p->key==key)
			{
				k++;
				printf("Number:%d-Postion:%d.\n",key,i);
				p=p->next;
			}
			else
			{
				p=p->next;
			}
		}
	}
	if(k==0)
	{
		printf("Queue doesn't have %d.\n",key);
	}
}