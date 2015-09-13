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

int pairs(vector<long> a, long k){	
	int res = 0;
	map <int, int > m;
	    
	for(int i = 0; i < a.size(); i++){
		m[a[i]] = i;
	}
	
	for(int i = 0; i < a.size(); i++){
		if(m.find(a[i]-k) != m.end())
			res++;
	}
	return res;
		 
}

int main()
{
	long n, k;
	vector<long> array;
	cin >> n;
	cin >> k;

	for(int i = 0; i < n; i++){
		long t;
		cin >> t;
		array.push_back(t);
	}
	cout << pairs (array, k);
	return 0;
}