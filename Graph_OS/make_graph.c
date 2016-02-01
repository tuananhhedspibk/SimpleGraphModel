/*This Is Open Source. Written By AnhTT - HUST 
  Feedback At : tuananhhedspibk@gmail.com
  HaNoi - 2015/06/29	
*/

#include "make_graph.h"

Graph_Struct Initialize_Graph()
{
	Graph_Struct Graph;
	Graph.Vertices = make_jrb();
	Graph.Edges = make_jrb();
	return Graph;	
}

void Add_Vertex(Graph_Struct Graph,char vertex[],char data[])
{
	int id = 1;
	JRB node,tree;
	Graph_Symbol_Table *Table;
	if(jrb_find_str(Graph.Vertices,vertex) != NULL)
	{
		return ;
	}
	
	Table = malloc(sizeof(Graph_Symbol_Table));
	Table->comp = malloc(MAX_LENGTH_STRING);
	Table->logic = 0;
	Table->counter_number_visit = 0;
	Table->number_topo_sort = 0;
	Table->previous = NULL;
	Table->in_degree = 0;
	Table->colour = 'w';
	
	strcpy(Table->comp,data);
	jrb_insert_str(Graph.Vertices,strdup(vertex),new_jval_v(Table));
	if(jrb_find_str(Graph.Edges,vertex) == NULL)
	{
		tree = make_jrb();
		jrb_insert_str(Graph.Edges,strdup(vertex),new_jval_v(tree));
	}

	jrb_traverse(node,Graph.Vertices)
	{
		Table = (Graph_Symbol_Table *)jval_v(node->val);
		Table->id = id++;
	}
}

void Add_Edge_UnDirected(Graph_Struct Graph,char s1[],char s2[],int weighted)			
{

	JRB node,tree;
	
	node = jrb_find_str(Graph.Edges,s1);
	if(node == NULL)
	{
		tree = make_jrb();
		jrb_insert_str(Graph.Edges,strdup(s1),new_jval_v(tree));
		jrb_insert_str(tree,strdup(s2),new_jval_i(weighted));
	}
	else
	{
		tree = (JRB)jval_v(node->val);
		if(jrb_find_str(tree,s2) == NULL)
		{
			jrb_insert_str(tree,strdup(s2),new_jval_i(weighted));
		}
		else
		{
			jrb_delete_node(jrb_find_str(tree,s2));
			jrb_insert_str(tree,strdup(s2),new_jval_i(weighted));
		}
	}
	
	if(jrb_find_str(Graph.Edges,s2) == NULL)
	{
		tree = make_jrb();
		jrb_insert_str(Graph.Edges,strdup(s2),new_jval_v(tree));
	}

	node = jrb_find_str(Graph.Edges,s2);
	tree = (JRB)jval_v(node->val);
	if(jrb_find_str(tree,s1) == NULL)
	{
		jrb_insert_str(tree,strdup(s1),new_jval_i(weighted));
	}
	else
	{
		jrb_delete_node(jrb_find_str(tree,s1));
		jrb_insert_str(tree,strdup(s1),new_jval_i(weighted));
	}
}

void Add_Edge_Directed(Graph_Struct Graph,char s1[],char s2[],int weighted)			
{

	JRB node,tree;

	node = jrb_find_str(Graph.Edges,s1);
	if(node == NULL)
	{
		tree = make_jrb();
		jrb_insert_str(Graph.Edges,strdup(s1),new_jval_v(tree));
		jrb_insert_str(tree,strdup(s2),new_jval_i(weighted));
	}
	else
	{
		tree = (JRB)jval_v(node->val);
		if(jrb_find_str(tree,s2) == NULL)
		{
			jrb_insert_str(tree,strdup(s2),new_jval_i(weighted));
		}
		else
		{
			jrb_delete_node(jrb_find_str(tree,s2));
			jrb_insert_str(tree,strdup(s2),new_jval_i(weighted));
		}
	}
	if(jrb_find_str(Graph.Edges,s2) == NULL)
	{
		tree = make_jrb();
		jrb_insert_str(Graph.Edges,strdup(s2),new_jval_v(tree));
	}
}

void Read_data(Graph_Struct Graph,char file_name[],int flag)
{
	FILE *file;
	int weighted_of_edge;
	char *line,*v_1,*v_2,*weighted;

	line = malloc(MAX_LENGTH_LINE);
	v_1 = malloc(MAX_LENGTH_STRING);
	v_2 = malloc(MAX_LENGTH_STRING);
	weighted = malloc(MAX_LENGTH_STRING);

	file = fopen(file_name,"r");
	if(file == NULL)
	{
		perror("Can't Open File. Exit.\n");
		return ;
	}

	while(fgets(line,200,file) != NULL)
	{
		Repair_Line(line);
		v_1 = strtok(line," ");
		v_2 = strtok(NULL," ");
		weighted = strtok(NULL," ");
		Add_Vertex(Graph,v_1,v_1);
		Add_Vertex(Graph,v_2,v_2);
		weighted_of_edge = atoi(weighted);
		if(flag)
		{ 
			Add_Edge_Directed(Graph,v_1,v_2,weighted_of_edge);
		}
		else
		{
			Add_Edge_UnDirected(Graph,v_1,v_2,weighted_of_edge);
		}
	}

}