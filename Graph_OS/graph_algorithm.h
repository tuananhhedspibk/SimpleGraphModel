/*This Is Open Source. Written By AnhTT - HUST 
  Feedback At : tuananhhedspibk@gmail.com
  HaNoi - 2015/06/29	
*/

#ifndef GRAPH_ALGORITHM
#define GRAPH_ALGORITHM

#include "make_graph.h"
#include "assistant_graph.h"
#include "traverse_graph.h"
#include "lib/heap.h"


long Dijkstra(Graph_Struct Graph);
void Topological(Graph_Struct Graph);
int IsDAG(Graph_Struct Graph);

#endif