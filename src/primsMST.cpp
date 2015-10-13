#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <utility> 
#include <limits>
#include "graph.h"
using namespace std;

int prim(int start_node){
	
}

int main()
{
	Graph g;
	int n, m, start_node;
	
	cin >> n >> m;
	
    g.add_vertices(n);
	
	for(int i = 0; i < n; i++){
		int x, y, w;
		cin >> x >> y >> w;
		g.add_edge(x,y,w);
	}
	cin >> start_node;
	cout << prim(start_node);
	//g.print_adj(2);
}
