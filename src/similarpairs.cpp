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

int getParent(int i){
	return i - (i & -i );
}

int getNext(int i){
	return i + (i & -i);
}

void update_bit(vector<long> &tree, int index, long value){
	unsigned int i = index;
	while(i < tree.size()){
		tree[i] += value;
		i = getNext(i);
	}
}
long getSum(vector<long> &tree, int index){
	unsigned int p ;
	long sum = 0;
	index++;
	p = index;
	while(p > 0){
		sum += tree[p];
		p = getParent(p);
	}
	return sum;
}

vector<long> create_bit(vector<long> input){
	vector<long> tree(input.size()+1, 0);
	for(unsigned int i = 1; i < tree.size(); i++){
		update_bit(tree, i, input[i-1]);
	}
	return tree;
}

int simpairs(vector< pair<int, int> > edges){
	vector <int> tree(edges.size(),0);
	for(unsigned int i = 0; i < edges.size(); i++){
		//set_bit(i,edges[i].first,tree);
	}
    return 0;
}

int main()
{
	int n, t;
	vector< pair<int, int> > edges;
	cin >> n;
	cin >> t;

	for(int i = 0; i < n-1; i++){
		int a,b;
		cin >> a;
		cin >> b;
		edges.push_back(make_pair(a,b));
	}
	simpairs(edges);

	
}
