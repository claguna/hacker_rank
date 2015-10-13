#include <sstream>
#include <iostream>
#include <utility> 
#include <limits>
#include <vector>

using namespace std;

struct Edge{
	int vertex1;
	int vertex2;
	int weight;
	Edge(int v1, int v2, int w):vertex1(v1), vertex2(v2), weight(w){}
};

class Graph{
	
private:
	vector<Edge> edges;
	vector<Edge> *adj_l;
	bool update_edge(int v1, int v2, int w);
public:
	int add_vertices(int i);
	int add_edge(int v1, int v2, int w);
	vector<Edge> adjacent(int v);

	/*debugger functions*/
    void print_adj(int v);
};

int Graph::add_vertices(int number_nodes){
	adj_l = new vector <Edge> [number_nodes+1];
	return 0;
}

int Graph::add_edge(int v1, int v2, int w){
	if(update_edge(v1, v2, w)){
		return 0;
	}
	//cout << "add "<<v1 << " "<<v2 << " " << w << endl;
	Edge e(v1, v2, w);
	adj_l[v1].push_back(e);
	adj_l[v2].push_back(e);
	return 0;
}

bool Graph::update_edge(int v1, int v2, int w){
	bool change = false;
	
	vector<Edge>adj_v1 = adjacent(v1);
	for(unsigned int i = 0; i < adj_v1.size(); i++){
		Edge it = adj_v1[i];
		if( ((it.vertex1 == v1 && it.vertex2 == v2) || (it.vertex1 == v2 && it.vertex2 == v1))
		   && (it.weight > w) )
		{
			adj_l[v1][i].weight = w;			
			change = true;;
		}
	}
	if(change){
		update_edge(v2, v1, w);
	}
	return change;
}
vector<Edge> Graph::adjacent(int v){
	return adj_l[v];
}

void Graph::print_adj(int v){
	for(Edge e: adjacent(v)){
		cout << e.vertex1 << " " <<  e.vertex2 << " "<< e.weight << endl;
	}
}
