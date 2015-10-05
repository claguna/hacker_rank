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

int llis(vector<int> A)
{
	unsigned int i= 0;
	unsigned int j = 1;
	int m = 0;
	vector<int> T(A.size(), 1);
	
	while(j < A.size()){
		if(A[i] < A[j]){
			T[j] = max(1 + T[i], T[j] );
		}
		i++;
		if(i==j){
			i = 0;
			j++;
		}
	}

	for(unsigned int k = 0; k < T.size(); k++){
		if(T[k] > m)
			m = T[k];
	}
	return m;
}

int main()
{
	unsigned int  n;
	vector<int> arr;
	
	cin >> n;
	for(unsigned int i = 0; i < n; i++){
		int t;
		cin>> t;
		arr.push_back(t);
	}
	cout << llis(arr);
}
