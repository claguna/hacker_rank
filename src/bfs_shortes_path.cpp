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

/* https://www.hackerrank.com/challenges/bfsshortreach */

using namespace std;

int const DEFAULT_WEIGHT = 6;

void print_list(vector< pair <int, int> > *adj_l, int n_nodes)
{
  for(int i= 1; i <= n_nodes; i++){
    vector< pair<int, int> > adj_i;
    adj_i = adj_l[i];

    for(unsigned int j=0; j < adj_i.size(); j++){
      cout << i <<" -> "<< adj_i[j].first<<"\n";
    }
    if(adj_i.size() == 0)
      cout << i << "\n";
  }  
}

/* Since the weights are positive we can implement Dijsktra's algorithm.
   However, in this case all the weights are the same, we only need to BFS each node
   and count the number of steps we need to take from start_node to each other node.
*/
void print_shortest_path(vector< int > *adj_l, int start_node, int n_nodes)
{
  queue<int> queue; /*Queue of pairs (node, distance to start_node)*/
  vector<int> distances;
  
  for(int i=0; i<= n_nodes; i++){
    distances.push_back(numeric_limits<int>::max());
  }  
  //print_list(adj_l, n_nodes);
  queue.push(start_node);
  distances[start_node] = 0;

  while(!queue.empty()){
    int node = queue.front();
    queue.pop();        

    /*Get node neighbors*/
    vector< int > adj_node;
    adj_node = adj_l[node];
    for(unsigned int i = 0; i < adj_node.size(); i++){
      if(distances[adj_node[i]] == numeric_limits<int>::max()){
        queue.push(adj_node[i]);
        distances[adj_node[i]] = distances[node] + 1;
      }      
    }    
  }
  
  for(unsigned int i=1; i< distances.size(); i++){      
    //cout<< i << " ";
    if(i == start_node)
      continue; //do not print start_node
    if(distances[i] != numeric_limits<int>::max())
      cout << DEFAULT_WEIGHT * distances[i] << " ";
    else      
      cout << "-1 ";     
  }
  cout << "\n";
}
			
int main()
{
  int ntest;
  int n_nodes, n_edges;
  int start_node;
  vector< int > *adj_l;

  scanf("%d", &ntest);

  for (int i=0; i<ntest; i++){
    scanf("%d %d", &n_nodes, &n_edges);
    adj_l = new vector< int >[n_nodes+1];

    for(int j=0; j< n_edges; j++){
      int x, y;
      scanf("%d %d",&x, &y);
      //add (x,y) and (y,x) to the adjancecy list
      adj_l[x].push_back(y);
      adj_l[y].push_back(x);
    }
    scanf("%d", &start_node);
    print_shortest_path(adj_l, start_node, n_nodes);
  }
}
