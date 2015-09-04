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
using namespace std;

void print_list(vector< pair <int, int> > *adj_l, int n_nodes)
{
  for(int i= 1; i <= n_nodes; i++){
    vector< pair<int, int> > adj_i;
    adj_i = adj_l[i];

    for(int j=0; j < adj_i.size(); j++){
      cout << i <<" -> "<< adj_i[j].first<<"\n";
    }
    if(adj_i.size() == 0)
      cout << i << "\n";
  }  
}


void print_shortest_path(vector< pair <int, int> > *adj_l, int start_node, int n_nodes)
{
  print_list(adj_l,n_nodes);
  
}
			
int main()
{
  int ntest;
  int n_nodes, n_edges;
  int start_node;
  vector< pair <int, int> > *adj_l;
  int const DEFAULT_WEIGHT = 6;

  scanf("%d", &ntest);

  for (int i=0; i<ntest; i++){
    scanf("%d %d", &n_nodes, &n_edges);

    adj_l = new vector< pair<int, int> >[n_nodes+1];

    for(int j=0; j< n_edges; j++){
      int x, y;
      scanf("%d %d",&x, &y);
      //add (x,y) and (y,x) to the adjancecy list
      adj_l[x].push_back(make_pair(y, DEFAULT_WEIGHT));
      adj_l[y].push_back(make_pair(x, DEFAULT_WEIGHT));
    }
    scanf("%d", &start_node);
    print_shortest_path(adj_l, start_node, n_nodes);
  }
}
