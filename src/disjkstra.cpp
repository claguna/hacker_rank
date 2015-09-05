/* https://www.hackerrank.com/challenges/dijkstrashortreach */
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

using namespace std;

/*This compare class implements a comparator function between two pairs.
  The function is used to order the elements in the queue based on its weight
  (second entry)
 */
class Compare
{
public:
  bool operator() (pair <int, int> &op1, pair < int, int> &op2)
  {
    return op1.second == op2.second;
  }
};

void dijkstra(vector< pair <int, int> > *adj_l, unsigned int n_nodes, unsigned int source)
{
  /*pq to get smaller elementn*/
  priority_queue< pair <int,int > , vector< pair<int, int> >, Compare> pq;
  
  /*given node i, it store its shortest distance from source*/
  vector<int> distances;

  /*intialize distances to inifity*/
  for(unsigned int i=0; i <= n_nodes; i++)
    distances.push_back(numeric_limits<int>::max());

  pq.push(make_pair(source, 0));
  distances[source]=0;

  while(!pq.empty()){
    /*This will be the closest neightbor*/
    pair<int, int> node = pq.top();
    pq.pop();
    
    vector< pair<int, int> > adj_nodes;
    adj_nodes = adj_l[node.first];

    /*Get all neightbors*/
    for (unsigned int i=0; i< adj_nodes.size(); i++){
      pair<int, int> v = adj_nodes[i];

      int tmpdist = distances[node.first] + v.second;
      
      /*We have a shortest path using node v*/
      if( tmpdist < distances[v.first] ){
	/* Wikipedia says we don't have to add the node if we have seen it.
	   Actually, the node must be added if the distance has changed
	   so that we update the information of the node neigthbors.
	  if(distances[adj_node[i]] == numeric_limits<int>::max())*/
	pq.push( make_pair( v.first, tmpdist) );
	distances[v.first] = tmpdist;
      }      
    }      
  }
   for(unsigned int i=1; i< distances.size(); i++){      
    if(i == source)
      continue; //do not print start_node
    if(distances[i] != numeric_limits<int>::max())
      cout <<  distances[i] << " ";
    else      
      cout << "-1 ";     
  }
  cout << "\n";

}

int main()
{
  int test_cases;
  int number_nodes, number_edges;
  vector< pair<int, int> > *adj_l;

  scanf("%d", &test_cases);
  
  for(int i=0; i < test_cases; i++ ){
    int x, y, r;
    int start_node;

    scanf("%d %d", &number_nodes, &number_edges);
    adj_l = new  vector < pair<int, int> >[number_nodes+1];

    for(int j=0; j < number_edges; j++){
      /*node_x, node_y, weight*/
      scanf("%d %d %d", &x, &y, &r);
      adj_l[x].push_back( make_pair(y,r) );
      adj_l[y].push_back( make_pair(x,r) );      
    }
    scanf("%d", &start_node);
    dijkstra(adj_l, number_nodes, start_node);
  }
  
  return 0;
}