/*This Is Open Source. Written By AnhTT - HUST 
  Feedback At : tuananhhedspibk@gmail.com
  HaNoi - 2015/06/29	
*/

#include "assistant_graph.h"

void Repair_Line(char *func)
{
	int l;
	l = strlen(func);
	func[l - 1] = '\0';
}

Graph_Symbol_Table *Search_On_Table(Graph_Struct Graph,char string[])	
{
	JRB node;
	Graph_Symbol_Table *Table;
	node = jrb_find_str(Graph.Vertices,string);
	if(node != NULL)
	{
		Table = (Graph_Symbol_Table *)jval_v(node->val);
		return Table;
	}
}

int Mapping_Name_To_ID(Graph_Struct Graph,char string[])
{
	int id; 
	JRB node;
	Graph_Symbol_Table *Table;
	node = jrb_find_str(Graph.Vertices,string);
	if(node != NULL)
	{
		Table = (Graph_Symbol_Table *)jval_v(node->val);
		id = Table->id;
		return id;
	}
}

char *Mapping_ID_To_Name(Graph_Struct Graph,int i)
{
	char *vertex;
	JRB node;
	Graph_Symbol_Table *Table;

	vertex = malloc(MAX_LENGTH_STRING);

	jrb_traverse(node,Graph.Vertices)
	{
		Table = (Graph_Symbol_Table *)jval_v(node->val);
		if(Table->id == i)
		{
			strcpy(vertex,jval_s(node->key));
			return vertex;
		}
	}
}

void Erase_Data(Graph_Struct Graph)
{
	JRB node;
	Graph_Symbol_Table *Table;
	jrb_traverse(node,Graph.Vertices)
	{
		Table = (Graph_Symbol_Table *)jval_v(node->val);
		Table->colour = 'w';
		if(Table->previous != NULL)
		{
			free(Table->previous);
			Table->previous = NULL;
		}
		if(Table->comp != NULL)
		{
			free(Table->comp);
			Table->comp = NULL;
		}
		Table->in_degree = 0;
		Table->logic = 0;
		Table->number_topo_sort = 0;
		Table->counter_number_visit = 0;
	}
	//------------------------------------------------------//
	jrb_traverse(node,Graph.Vertices)
	{
		Table = (Graph_Symbol_Table *)jval_v(node->val);
		Table->comp = malloc(MAX_LENGTH_STRING);
		strcpy(Table->comp,jval_s(node->key));
	}
	//-------------------------------------------------------//
}

void Get_Adj(Graph_Struct Graph)
{
	JRB node,ele,tree;
	char *s;

	s = malloc(MAX_LENGTH_STRING);
	
	printf("Input One Vertex:");
	gets(s);

	node = jrb_find_str(Graph.Edges,s);
	if(node == NULL)
	{
		printf("This Vertex Doesn't Exists.\n");
		return ;
	}

	printf("Vertex %s: ",jval_s(node->key));
	tree = (JRB)jval_v(node->val);
	jrb_traverse(ele,tree)
	{
		printf("%s ",jval_s(ele->key));
	}
	printf("\n");
	Erase_Data(Graph);
}

void InEdge(Graph_Struct Graph)
{
	Graph_Symbol_Table *Table;
	JRB node_edge,node_vertex,tree,ele;
	char *vertices;

	vertices = malloc(MAX_LENGTH_STRING);

	jrb_traverse(node_vertex,Graph.Vertices)
	{
		Table = (Graph_Symbol_Table *)jval_v(node_vertex->val);
		vertices = jval_s(node_vertex->key);

		jrb_traverse(node_edge,Graph.Edges)
		{
			if(strcmp(vertices,jval_s(node_edge->key)))
			{
				tree = (JRB)jval_v(node_edge->val);
				jrb_traverse(ele,tree)
				{
					if(!strcmp(vertices,jval_s(ele->key)))
					{
						Table->in_degree++;
					}
				}
			}
		}
	}
}

void Print_Edge_Of_Graph_Struct(Graph_Struct Graph)
{
	JRB node,tree,ele;
	printf("\n");
	jrb_traverse(node,Graph.Edges)
	{
		tree = (JRB)jval_v(node->val);
		printf("Ver(%s):",jval_s(node->key));
		jrb_traverse(ele,tree)
		{
			printf("(%s-%s)(weighted:%d) ",jval_s(node->key),jval_s(ele->key),jval_i(ele->val));
		}
		printf("\n");
	}
}

void Print_Vertex_Of_Graph_Struct(Graph_Struct Graph)
{
	Graph_Symbol_Table *ele;
	JRB node;
	jrb_traverse(node,Graph.Vertices)
	{
		ele = (Graph_Symbol_Table *)jval_v(node->val);
		printf("%s:%d-%c-%s.\n",jval_s(node->key),ele->id,ele->colour,ele->comp);
	}
}

void welcome()
{
	printf("Welcome To Program About Graph. Written By AnhTT - HUST_HANOI. I Use jrb_structure To Buil This Program.\n");
	printf("Input 'help' For Helping. This Program Uses Command Mode.\n");
	printf("I Use Data In 2 Files: g_1.txt, g_2.txt.\n");
	printf("Please Enjoy And Help Fun !!!\n");
}

void help()
{
	printf("[make_directed]              Make Directed_Graph.\n");
	printf("[make_undirected]            Make UnDirected_Graph.\n");
	printf("[print]                      Print Graph.\n");
	printf("[bfs]                        BFS Traverse.\n");
	printf("[dfs]                        DFS Traverse.\n");
	printf("[get]                        Get Adjective_list Of Vertex.\n");
	printf("[topo]                       Topological Sort.\n");
	printf("[dijkstra]                   Dijkstra Algorithm.\n");
	printf("[dag]                        Check DAG.\n");
	printf("[exit]                       Exit Out Of Program.\n");
}