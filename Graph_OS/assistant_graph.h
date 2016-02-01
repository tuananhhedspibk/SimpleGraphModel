/*This Is Open Source. Written By AnhTT - HUST 
  Feedback At : tuananhhedspibk@gmail.com
  HaNoi - 2015/06/29	
*/

#ifndef ASSISTANT_GRAPH
#define ASSISTANT_GRAPH

#include "make_graph.h"

void Repair_Line(char *func);
void Erase_Data(Graph_Struct Graph);
Graph_Symbol_Table *Search_On_Table(Graph_Struct Graph,char string[]);
int Mapping_Name_To_ID(Graph_Struct Graph,char string[]);
char *Mapping_ID_To_Name(Graph_Struct Graph,int i);
void Get_Adj(Graph_Struct Graph);
void InEdge(Graph_Struct Graph);
void Print_Edge_Of_Graph_Struct(Graph_Struct Graph);
void Print_Vertex_Of_Graph_Struct(Graph_Struct Graph);
void welcome();
void help();

#endif