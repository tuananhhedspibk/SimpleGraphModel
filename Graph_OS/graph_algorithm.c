/*This Is Open Source. Written By AnhTT - HUST 
  Feedback At : tuananhhedspibk@gmail.com
  HaNoi - 2015/06/29	
*/

#include "graph_algorithm.h"

long Dijkstra(Graph_Struct Graph)
{
	Graph_Symbol_Table *Table;
	char *s1,*s2,*start_vertex,*stop_vertex;
	PQ heap[MAX_LENGTH_ARRAY];
	JRB node_edge,node_vertex_1,node_vertex_2,tree,ele;
	int n,v,d[MAX_LENGTH_ARRAY],vertex = 0,u,l;

	start_vertex = malloc(MAX_LENGTH_STRING);
	stop_vertex = malloc(MAX_LENGTH_STRING);
	s1 = malloc(MAX_LENGTH_STRING);
	s2 = malloc(MAX_LENGTH_STRING);
	
	printf("Input start_vertex:");
	gets(start_vertex);
	printf("Input stop_vertex:");
	gets(stop_vertex);

	jrb_traverse(node_vertex_1,Graph.Vertices)
	{
		vertex++;
	}
	n = vertex; 
	for(v = 1 ; v <= vertex ; v++)
	{
		d[v] = INFINITIVE_VALUE;
	}

	u = Mapping_Name_To_ID(Graph,start_vertex);
	d[u] = 0;
			
	Table = Search_On_Table(Graph,start_vertex);
	Table->previous = malloc(MAX_LENGTH_STRING);
	strcpy(Table->previous,start_vertex);
			
	Build_Min_Heap(heap,d,vertex);
	while(n)
	{
		u = Heap_Extract_Min(heap,&n);
		s1 = Mapping_ID_To_Name(Graph,u);
				
		node_edge = jrb_find_str(Graph.Edges,s1);
		node_vertex_2 = jrb_find_str(Graph.Vertices,s1);
		Table = (Graph_Symbol_Table *)jval_v(node_vertex_2->val);
		Table->logic = 1;
				
		if(node_edge != NULL)
		{
			tree = (JRB)jval_v(node_edge->val);
			jrb_traverse(ele,tree)
			{
				s2 = jval_s(ele->key);
				l = jval_i(ele->val);
				v = Mapping_Name_To_ID(Graph,s2);

				Table = (Graph_Symbol_Table *)jval_v(jrb_find_str(Graph.Vertices,s2)->val);
						
				if(d[v] > d[u] + l && Table->logic == 0)
				{
					d[v] = d[u] + l;
					Table->previous = malloc(MAX_LENGTH_STRING);
					strcpy(Table->previous,s1);
					Decrease_key(heap,v,d[v],n);
				}
			}
		}
	}

	node_vertex_2 = jrb_find_str(Graph.Vertices,stop_vertex);
	Table = (Graph_Symbol_Table *)jval_v(node_vertex_2->val);	
	if(Table->previous != NULL)
	{
		while(strcmp(start_vertex,stop_vertex))
		{
			printf("%s <- ",stop_vertex);
			if(Table->previous != NULL)
			{
				strcpy(stop_vertex,Table->previous);
				Table = Search_On_Table(Graph,stop_vertex);
			}
		}
		printf("%s\n",start_vertex);
	}
	else
	{
		printf("Doesn't have path from %s to %s.\n",start_vertex,stop_vertex);
	}	
	Erase_Data(Graph);
}

void Topological(Graph_Struct Graph)
{
	int num = 0,i;
	char *u;
	Graph_Symbol_Table *Table;
	JRB node_edge,node_vertex,tree,ele;
	Dllist queue,node_queue;
		
	u = malloc(MAX_LENGTH_STRING);

	InEdge(Graph);
	queue = new_dllist();
	
	jrb_traverse(node_vertex,Graph.Vertices)
	{
		Table = (Graph_Symbol_Table *)jval_v(node_vertex->val);
		if(!Table->in_degree)
		{
			dll_append(queue,new_jval_s(jval_s(node_vertex->key)));
		}
	}
	
	while(!dll_empty(queue))
	{
		node_queue = dll_first(queue);
		u = jval_s(node_queue->val);
		dll_delete_node(node_queue);
			
		node_vertex = jrb_find_str(Graph.Vertices,u);
		Table = (Graph_Symbol_Table *)jval_v(node_vertex->val);
		Table->number_topo_sort = ++num;
		
		node_edge = jrb_find_str(Graph.Edges,u);
			
		if(node_edge != NULL)
		{
			tree = (JRB)jval_v(node_edge->val);
			jrb_traverse(ele,tree)
			{
				u = jval_s(ele->key);
				node_vertex = jrb_find_str(Graph.Vertices,u);
				Table = (Graph_Symbol_Table *)jval_v(node_vertex->val);
				Table->in_degree--;
				if(!Table->in_degree)
				{
					dll_append(queue,new_jval_s(u));
				}
			}
		}
	}

	num = 0;
	
	jrb_traverse(node_vertex,Graph.Vertices)
	{
		num++;
	}
	for(i = 1 ; i <= num ; i++)
	{
		jrb_traverse(node_vertex,Graph.Vertices)
		{
			Table = (Graph_Symbol_Table *)jval_v(node_vertex->val);
			if(Table->number_topo_sort == i)
			{
				printf("%s(%d) ",jval_s(node_vertex->key),Table->number_topo_sort);
			}
		}
	}
	printf("\n");
}

int IsDAG(Graph_Struct Graph)
{
	char *vertex;
	Graph_Symbol_Table *Table;
	JRB node_edge,node_vertex;
	int mark = 0;

	vertex = malloc(MAX_LENGTH_STRING);

	jrb_traverse(node_edge,Graph.Vertices)
	{
		jrb_traverse(node_vertex,Graph.Vertices)
		{
			Table = (Graph_Symbol_Table *)jval_v(node_vertex->val);
			Table->counter_number_visit = 0;
		}
		
		vertex = jval_s(node_edge->key);
		Table = Search_On_Table(Graph,vertex);
		if(Table->colour == 'w')
		{
			DFS_ForDag(Graph,vertex,&mark);
			if(mark)
			{
				Erase_Data(Graph);
				printf("Graph Isn't DAG.\n");
				return 0;
			}
		}
	}
	printf("Graph Is DAG.\n");
	Erase_Data(Graph);
	return 1;
}