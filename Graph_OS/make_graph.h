/*This Is Open Source. Written By AnhTT - HUST 
  Feedback At : tuananhhedspibk@gmail.com
  HaNoi - 2015/06/29	
*/

#ifndef MAKE_GRAPH
#define MAKE_GRAPH

#define MAX_LENGTH_STRING 30
#define INFINITIVE_VALUE 10000
#define MAX_LENGTH_LINE 200
#define MAX_LENGTH_ARRAY 100

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "lib/jrb.h"

typedef struct 
{
	JRB Vertices;				//Set Vertices = {v}
	JRB Edges;					//Set Edges = {E}
}Graph_Struct;

typedef struct 
{
	int id;						//ID Of Vertex
	char *previous;				//Previous Vertex Of Current Vertex
	char colour; 				//w:white --- b:black --- g:gray  ---
	int logic;					//logic = 1 :TRUE  ||   logic = 0 :FALSE
	int in_degree;				//Indegree Of Vertex
	int number_topo_sort;		//Use For Topological Sort
	int counter_number_visit;	//Count Number Time(s) Visit Vertex
	char *comp;					//ID Of Connected Component Conatain Vertex
	int i,j;
}Graph_Symbol_Table;

void Add_Vertex(Graph_Struct Graph,char vertex[],char data[]);
Graph_Struct Initialize_Graph();
void Add_Edge_UnDirected(Graph_Struct Graph,char s1[],char s2[],int weighted);
void Add_Edge_Directed(Graph_Struct Graph,char s1[],char s2[],int weighted);
void Read_data(Graph_Struct Graph,char file_name[],int flag);

#endif