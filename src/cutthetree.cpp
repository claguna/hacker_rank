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
/*https://www.hackerrank.com/challenges/cut-the-tree*/

vector<bool> visited;

bool reachable_from_root(vector< int >  *al, int start_node, int endnode, pair<int,int> oe)
{
	bool reachable = false;
	
	if(start_node == endnode)
		return true;
	
	visited[start_node] = true;
	vector<int>  adj_nodes;
	adj_nodes = al[start_node];
	for(unsigned int i = 0; i < adj_nodes.size(); i++){
		
		if( (start_node == oe.first && adj_nodes[i] == oe.second ) ||
			(start_node == oe.second && adj_nodes[i] == oe.first))
			continue;
		
		if(!visited[adj_nodes[i]])
			return  reachable_from_root(al, adj_nodes[i], endnode, oe);
	}
	return reachable;
}

int dfs(vector< int >  *al, int start_node, vector<int> vvalues, pair<int,int> oe)
{
	int res = 0;
	
    visited[start_node] = true;
	
	//cout << start_node<<endl;
	vector<int>  adj_nodes;
	adj_nodes = al[start_node];
	for(unsigned int i = 0; i < adj_nodes.size(); i++){
		
		if( (start_node == oe.first && adj_nodes[i] == oe.second ) ||
			(start_node == oe.second && adj_nodes[i] == oe.first))
			continue;
		
		if(!visited[adj_nodes[i]])
			res += dfs(al, adj_nodes[i], vvalues, oe);
	}
	return vvalues[start_node-1] + res;	
}

int mintreediff(vector< int > *al, vector< pair<int,int> > edges, vector<int> vvalues)
{
	int min = numeric_limits<int>::max();
	for(int i = 0; i< vvalues.size(); i++)
		visited[i] = false;
	
    //return dfs(al, 3, vvalues, make_pair(2,3));

	
	for(unsigned int i = 0; i < edges.size(); i++){
		pair <int, int> p = edges[i];
		int tnode = p.first;
		
		cout << "rem edge "<< p.first<< " "<<  p.second << endl;
			
		for(int k = 0; k< vvalues.size(); k++)
			visited[k] = false;
		int t1 = dfs(al, 1, vvalues, p);
		
		for(int k = 0; k< vvalues.size(); k++)
			visited[k] = false;
		
		if(reachable_from_root(al, 1, p.first, p))
			tnode = p.second;
		else
			tnode = p.first;
		cout << tnode << endl;	
		for(int k = 0; k< vvalues.size(); k++)
			visited[k] = false;
		
		int t2 = dfs(al, tnode, vvalues, p);

		cout << "t1 "<<t1 <<" t2 "<< t2 <<endl;
		int tdiff = abs(t2 - t1);
		if(tdiff < min && tdiff != 0)
			min = tdiff;		
	}
	return min;
}

int main()
{
	int nvertices;
	vector<int> vvalues;
	vector< int > *al;
	vector< pair<int,int> > edges;
	
	cin >> nvertices;

	for(int i = 0; i< nvertices; i++){
		int t;
		cin >> t;
		vvalues.push_back(t);
		visited.push_back(false);
	}
	al = new  vector< int > [nvertices+1];
	for(int i = 0; i < nvertices-1; i++){
		int a, b;
		cin >> a;
		cin >> b;
		al[a].push_back(b);
		al[b].push_back(a);
		edges.push_back(make_pair(a,b));
	}
	for(int i = 1; i < nvertices; i++){
		vector<int>  adj_nodes;
	    adj_nodes = al[i];
	    for(unsigned int j = 0; j < adj_nodes.size(); j++){	   
	     	cout << i <<" -> "<<adj_nodes[j]<<endl;		
	    }
	}
	cout << mintreediff(al, edges,vvalues);
}
