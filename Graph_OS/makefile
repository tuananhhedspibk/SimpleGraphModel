build_main.c = main_c
assistant_graph.c = assistant_c
graph_algorithm.c = graph_algo_c
make_graph.c = make_c
traverse_graph.c = traverse_c

lib/heap.c = heap
lib/dllist.c = dllist
lib/jrb.c = jrb
lib/jval.c = jval

build_main = main


$(main): $(main_c) $(assistant_c) $(graph_algo_c) $(heap) $(dllist) $(jrb) $(jval)
			$(CC) -o $(main) $(main_c) $(assistant_c) $(graph_algo_c) $(heap) $(dllist) $(jrb) $(jval) -w 
clean:
	rm -f build_main
	rm -f *.o