/*This Is Open Source. Written By AnhTT - HUST 
  Feedback At : tuananhhedspibk@gmail.com
  HaNoi - 2015/06/29	
*/

#include "traverse_graph.h"

void BFS_Visit(Graph_Struct Graph,char start[])
{
	Graph_Symbol_Table *Table;
	char *u,*v;
	JRB node_rbt,tree,ele;
	Dllist node_queue,queue = new_dllist();
	printf("%s ",start);
	
	u = malloc(MAX_LENGTH_STRING);
	v = malloc(MAX_LENGTH_STRING);
	
	Table = Search_On_Table(Graph,start);
	Table->colour = 'g';
	
	dll_append(queue, new_jval_s(start));
	while(!dll_empty(queue))
	{
		node_queue = dll_first(queue);
		u = jval_s(node_queue->val);
		dll_delete_node(node_queue);
		node_rbt = jrb_find_str(Graph.Edges,u);
		if(node_rbt != NULL)
		{
			tree = (JRB)jval_v(node_rbt->val);
			jrb_traverse(ele,tree)
			{
				v = jval_s(ele->key);
				Table = Search_On_Table(Graph,v);
				if(Table->colour == 'w')
				{
					printf("%s ",v);
					Table->colour = 'g';
					if(Table->previous == NULL)
					{
						Table->previous = malloc(MAX_LENGTH_STRING);
					}
					strcpy(Table->previous,u);
					dll_append(queue, new_jval_s(v));
				}
			}
		}
	}
}

void BFS(Graph_Struct Graph)
{
	Graph_Symbol_Table *Table;
	JRB node;
	char *start,*stop;
		
	start = malloc(MAX_LENGTH_STRING);
	stop = malloc(MAX_LENGTH_STRING);
		
	do
	{
		printf("Input start vertex:");
		gets(start);
		printf("Input stop vertex:");
		gets(stop);
	}while(!strlen(stop) || jrb_find_str(Graph.Edges,stop) == NULL ||!strlen(start) || jrb_find_str(Graph.Edges,start) == NULL);
		
	Table = Search_On_Table(Graph,start);
	if(Table->colour == 'w')
	{
		BFS_Visit(Graph,start);
		printf("\n");
	}
		
	Table = Search_On_Table(Graph,stop);
	if(Table->colour != 'w')
	{
		while(strcmp(start,stop))
		{
			printf("%s <- ",stop);
			if(Table->previous != NULL)
			{
				strcpy(stop,Table->previous);
				Table = Search_On_Table(Graph,stop);
			}
		}
		printf("%s\n",start);
	}
	else
	{
		printf("Doesn't have path from %s to %s.\n",start,stop);
	}	
	Erase_Data(Graph);
}

void DFS_Visit(Graph_Struct Graph,char start[])
{
	char *v;
	JRB node_rbt,tree,ele;
	Graph_Symbol_Table *Table;
	
	Table = Search_On_Table(Graph,start);
	v = malloc(MAX_LENGTH_STRING);
	node_rbt = jrb_find_str(Graph.Edges,start);
	Table->colour = 'g';
	
	if(node_rbt!=NULL)
	{
		tree=(JRB)jval_v(node_rbt->val);
		jrb_traverse(ele,tree)
		{
			v = jval_s(ele->key);
			Table = Search_On_Table(Graph,v);
			if(Table->colour == 'w')
			{
				if(Table->previous == NULL)
				{
					Table->previous = malloc(MAX_LENGTH_STRING);
				}
				strcpy(Table->previous,start);
				printf("%s ",v);
				DFS_Visit(Graph,v);
			}
		}
		Table = Search_On_Table(Graph,start);
		Table->colour = 'b';
	}
}

void DFS(Graph_Struct Graph)
{
	Graph_Symbol_Table *Table;
	JRB node;
	char *start,*stop;
		
	start = malloc(MAX_LENGTH_STRING);
	stop = malloc(MAX_LENGTH_STRING);
		
	do
	{
		printf("Input start vertex:");
		gets(start);
		printf("Input stop vertex:");
		gets(stop);
	}while(!strlen(stop) || jrb_find_str(Graph.Edges,stop) == NULL ||!strlen(start) || jrb_find_str(Graph.Edges,start) == NULL);
		
	Table = Search_On_Table(Graph,start);
	if(Table->colour == 'w')
	{
		printf("%s ",start);
		DFS_Visit(Graph,start);
		printf("\n");
	}
		
	Table = Search_On_Table(Graph,stop);
	if(Table->colour != 'w')
	{
		while(strcmp(start,stop))
		{
			printf("%s <- ",stop);
			if(Table->previous != NULL)
			{
				strcpy(stop,Table->previous);
				Table = Search_On_Table(Graph,stop);
			}
		}
		printf("%s\n",start);
	}
	else
	{
		printf("Doesn't have path from %s to %s.\n",start,stop);
	}	
	Erase_Data(Graph);
}

int DFS_ForDag(Graph_Struct Graph,char start[],int *mark)
{
	Graph_Symbol_Table *Table;
	JRB node,tree,ele;
	char *vertex;

	Table = Search_On_Table(Graph,start);
	Table->counter_number_visit++;
	
	if(Table->counter_number_visit >= 2)
	{
		*mark = 1;
		return 1;
	}

	node = jrb_find_str(Graph.Edges,start);
	if(node != NULL)
	{
		tree = (JRB)jval_v(node->val);
		jrb_traverse(ele,tree)
		{
			vertex = jval_s(ele->key);
			Table = Search_On_Table(Graph,vertex);
			if(Table->colour == 'w')
			{
				DFS_ForDag(Graph,vertex,mark);
			}
		}
		Table = Search_On_Table(Graph,start);
		Table->colour = 'b';		
	}
}