/*https://www.hackerrank.com/challenges/flowers*/
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

int main()
{
	int n, k;
	vector<int> A;
	long res = 0;
	int x = 0;
	
	cin >> n;
	cin >> k;
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		A.push_back(t);
	}

	sort(A.begin(), A.end());
	
	for( unsigned int i = 0; i < A.size(); i++){
		res += (x+1)*A[A.size()-1 -i];
		if((i+1)%k == 0)
			x++;
	}
	cout << res;
	return 0;
}
