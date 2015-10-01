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

int buytoys(vector<int> a){
	int toys = 1;
	int min, max;
	
	sort(a.begin(), a.end());

	min = a[0];
	max = min +4;
	for(unsigned int i = 0; i < a.size(); i++){
		if(a[i] >= min && a[i]<= max){			
			continue;
		}		
		toys++;
		min = a[i];
		max = min+4;
	}
	return toys;
}

int main(){
	int n;
	vector <int> array;
	cin >> n;

	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		array.push_back(t);
	}
	cout << buytoys(array);

	
}