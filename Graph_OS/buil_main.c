/*This Is Open Source. Written By AnhTT - HUST. I Use jrb_struture To Write It. Help Fun !!! =)) 
  Feedback At : tuananhhedspibk@gmail.com
  HaNoi - 2015/06/29	
*/

#include <stdio.h>

#include "make_graph.h"
#include "assistant_graph.h"
#include "graph_algorithm.h"
#include "traverse_graph.h"

void main(int argc, char *argv[])
{
	Graph_Struct Graph;
	int flag,mark = 0;
	char *string;
	if(argc != 2)
	{
		perror("Error Command.\n");
		exit(1);
	}
	welcome();

	string = malloc(MAX_LENGTH_STRING);

	while(1)
	{
		printf(">>");
		gets(string);
		if(!strcmp(string,"help"))
		{
			help();
		}
		else if(!strcmp(string,"make_directed"))
		{
			mark = 1;
			flag = 1;
			Graph = Initialize_Graph();
			Read_data(Graph,argv[1],flag);
		}
		else if(!strcmp(string,"make_undirected"))
		{
			mark = 1;
			flag = 0;
			Graph = Initialize_Graph();
			Read_data(Graph,argv[1],flag);
		}
		else if(!strcmp(string,"print"))
		{
			if(mark)
			{
				Print_Edge_Of_Graph_Struct(Graph);
				Print_Vertex_Of_Graph_Struct(Graph);
			}
			else
			{
				printf("Must make_graph.\n");
			}
		}
		else if(!strcmp(string,"bfs"))
		{
			if(mark)
			{
				BFS(Graph);
			}
			else
			{
				printf("Must make_graph.\n");
			}
		}
		else if(!strcmp(string,"dfs"))
		{
			if(mark)
			{
				DFS(Graph);
			}
			else
			{
				printf("Must make_graph.\n");
			}
		}
		else if(!strcmp(string,"get"))
		{
			if(mark)
			{
				Get_Adj(Graph);
			}
			else
			{
				printf("Must make_graph.\n");
			}
		}
		else if(!strcmp(string,"topo"))
		{
			if(mark)
			{
				if(flag)
				{
					Topological(Graph);
				}
				else
				{
					printf("Graph is undirected. Can't topo.\n");
				}
			}
			else
			{
				printf("Must make_graph.\n");
			}
		}
		else if(!strcmp(string,"dijkstra"))
		{
			if(mark)
			{
				Dijkstra(Graph);
			}
			else
			{
				printf("Must make_graph.\n");
			}
		}
		else if(!strcmp(string,"dag"))
		{
			if(mark)
			{
				if(flag)
				{
					IsDAG(Graph);
				}
				else
				{
					printf("Graph is undirected. Can't IsDAG.\n");
				}
			}
			else
			{
				printf("Must make_graph.\n");
			}
		}
		else if(!strcmp(string,"exit"))
		{
			printf("Bye.\n");
			exit(1);
		}
		else
		{
			printf("Error Command. Try 'help' For Helping.\n");
		}
	}
}  