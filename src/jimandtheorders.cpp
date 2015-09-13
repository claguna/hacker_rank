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

bool compare_pairs (pair <int, int> op1, pair < int, int> op2)
{
    return op1.first < op2.first;
}


int main()
{
	int norders;
	vector < pair<int,int> > orders;
	
	cin >> norders;
	for(int i = 0; i < norders; i++){
		int a, b;
		cin >> a;
		cin >> b;
		orders.push_back( make_pair(a+b, i+1));
	}
	stable_sort(orders.begin(), orders.end(), compare_pairs);

	for(int i = 0; i < orders.size(); i++)
		cout << orders[i].second << " ";

	
}
