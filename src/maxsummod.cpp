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

int max_sum_mod(vector<long> array, int mod)
{
	long current_sum = 0;
	long best_sum    = 0;
	int start_dx     = -1;
	int end_idx      = -1;

	for(unsigned int i = 0; i < array.size(); i++ ){
		int tmp = current_sum;
		current_sum += array[i];
		if (current_sum >= 0){
			if(tmp % mod == 0){
				start_dx = i;
			}
			if(current_sum % mod > best_sum){
				best_sum = current_sum % mod;
				end_idx = i;
			}			    
		}else{
			current_sum = 0;
		}
	}
    cout << start_dx << " "<< end_idx << endl;
	return best_sum;
}

int main()
{
	int testcases;
	cin >> testcases;
	for(int i = 0; i < testcases; i++){
		int n,m;
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
