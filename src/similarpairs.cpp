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

#define MAX_NODES 100005

using namespace std;

long similar_pairs;

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

int gi_smallest_thanx(vector<long> tree,int x)
{
	int low, high, mid;
	long sum, sumt;
	low = 0; high = tree.size()-1;
	while (low < high){
		mid = low + (high - low)/2;		
		sum = getSum(tree, mid);
		cout << low << " "<<mid << " "<< high <<" "<<sum << endl;
		if(sum < x)
			low = mid +1;
		else if(sum > x)
			high = mid -1;
		else
			return mid;
					
	}
			
	sumt = getSum(tree, low);
	while(sumt <= x){
		low ++;
		sumt = getSum(tree, low);			   
	 }
	 
	return low-1;
}

int dfs(vector<int> al, int node, int t){
	int diff = getSum(al, min(al.size(),node + t));
	sum = sum - getSum(al, max(1,node-t));

	similar_pairs += sum;
	update_bit(al, node, 1);
	
	for(int i = 0; i < al[node].size(); i++){
		dfs(al[node][i]);
	}
	
    return 0;
}


int main()
{
	int n, root, t;
    bool root_node[MAX_NODES];

	/*adjancency list*/
	vector<long> al[MAX_NODES];
	vector<long> tree;

	cin >> n;
	cin >> t;
	/*Initially, all the nodes are markes as root*/
	for(int i = 1; i <= n; i++){
		root_node[i] = true;
	}
   
	for(int i = 0; i < n-1; i++){
		int a,b;
		cin >> a >> b;
        al[a].push_back(b);
		/*a is parent of b, therefore b is not root*/
		root_node[b] = false;		
	}
	
	/*find out who is root. There should be only one*/
	for(int i = 1; i <= n; i++){
		if(root_node[i]){
			root = i;
			break;
		}			
	}
	dfs(root);
	return 0;
}
