/*https://www.hackerrank.com/challenges/two-arrays*/
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

bool twoarrays(vector <long> a, vector <long> b, int k)
{
	bool res = true;
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	for(unsigned int i = 0; i < a.size(); i++){
		if(a[i] + b[b.size()-1-i] < k)
			res = false;
	}

	return res;
}

int main()
{
	int testcases;
	int n, k;
	cin >> testcases;
	
	for(int i = 0; i < testcases; i++){
		vector <long> A;
		vector <long> B;
		
		cin >> n;
		cin >> k;
		for(int j = 0; j < n; j++){
			int t;
			cin >> t;
			A.push_back(t);
		}
		for(int j = 0; j < n; j++){
			int t;
			cin >> t;
			B.push_back(t);
		}
		if (twoarrays(A,B,k))
			cout << "YES\n";
		else
			cout << "NO\n";
		
	}
}
