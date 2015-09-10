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
int dfs(vector< int >  *al, int start_node, vector<int> vvalues, pair<int, int> omitedge)
{
	int res = 0;
	if(al[start_node].size()==0){
		cout << start_node<< " " << vvalues[start_node] << endl;
		return vvalues[start_node];
	}		
	vector<int>  adj_nodes;
	adj_nodes = al[start_node];
	for(unsigned int i = 0; i < adj_nodes.size(); i++){
		if(start_node == omitedge.first && i == omitedge.second)
			continue;
		res += dfs(al, adj_nodes[i], vvalues, omitedge);
	}
	return res;	
}

int mintreediff( vector< int > *al, vector<int> vvalues)
{
	int min = numeric_limits<int>::max();
	for(unsigned int i = 0; i < vvalues.size(); i++){
		vector<int> adj_i;
		adj_i = al[i];
		for(unsigned int j = 0; j < adj_i.size(); j++){
			cout << "rem edge "<< i<< " "<< adj_i[j]<<endl;
			int t1 = dfs(al, 1, vvalues, make_pair(i, adj_i[j]));
			int t2 = dfs(al, i, vvalues, make_pair(i, adj_i[j]));
			int tdiff = abs(t2- t1);
			if(tdiff < min)
				min = tdiff;
		}
	}
	return min;
}

int main()
{
	int nvertices;
	vector<int> vvalues;
	vector< int > *al;
	cin >> nvertices;

	for(int i = 0; i< nvertices; i++){
		int t;
		cin >> t;
		vvalues.push_back(t);
	}
	al = new  vector< int > [nvertices];
	for(int i = 0; i < nvertices-1; i++){
		int a, b;
		cin >> a;
		cin >> b;
		al[a-1].push_back(b-1);
	}
	cout << mintreediff(al, vvalues);
}
