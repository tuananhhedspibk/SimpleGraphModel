/*This Is Open Source. Written By AnhTT - HUST 
  Feedback At : tuananhhedspibk@gmail.com
  HaNoi - 2015/06/29	
*/

#ifndef TRAVERSE_GRAPH
#define TRAVERSE_GRAPH

#include "make_graph.h"
#include "assistant_graph.h"
#include "lib/dllist.h"

void BFS_Visit(Graph_Struct Graph,char start[]);
void BFS(Graph_Struct Graph);
void DFS_Visit(Graph_Struct Graph,char start[]);
void DFS(Graph_Struct Graph);
int DFS_ForDag(Graph_Struct Graph,char start[],int *mark);

#endif