/*https://www.hackerrank.com/challenges/maximise-sum*/
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

int max_sum_mod(vector<long> array, long mod)
{
	long current_sum = 0;
	long best_sum    = 0;
    long global_max_mod = 0;
	vector <long> psum;

	for(unsigned int i = 0; i < array.size(); i++){
		current_sum += array[i];
		psum.push_back(current_sum);
	}

	for(unsigned int start = 0; start < array.size(); start++){
		for(unsigned int end = start; end < array.size(); end++){
			int t;
			current_sum = psum[end];
			if( start >= 1 )
				current_sum = current_sum - psum[start - 1];
			t = current_sum % mod ;
			if( t > best_sum){
				best_sum = t;
				if(global_max_mod < best_sum)
					global_max_mod = best_sum;
			}
		}
	}
	
	return global_max_mod;
}

int main()
{
	int testcases;
	cin >> testcases;
	for(int i = 0; i < testcases; i++){
		int n;
		long m;
		vector<long> array;
		cin >> n;
		cin >> m;
		for(int j = 0; j < n; j++){
			int t;
			cin >> t;
			array.push_back(t);
		}
		cout << max_sum_mod(array, m) << endl;
	}
}