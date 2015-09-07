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

bool const debug = false;

bool search(vector<long> array)
{
	vector<long> sum_left, sum_right;
	int tmpsum = 0;

	if(array.size() == 1)
		return true;
   
	for(unsigned int i = 0; i < array.size(); i++){
		tmpsum += array[i];
		sum_left.push_back(tmpsum);
		sum_right.push_back(-1);
	}

	tmpsum = 0;
	
	for(int i = array.size()-1; i >= 0; i--){
		tmpsum += array[i];
		sum_right[i] = tmpsum;
	}
	if(debug){
		for(unsigned int i = 0; i < array.size(); i++){
			cout << sum_left[i]<<" ";
		}
		cout<< endl;
		for(unsigned int i = 0; i < array.size(); i++){
			cout << sum_right[i]<<" ";
		}
		cout<< endl;
	}	
	
	for(int i = 1; i < array.size()-1; i++){
		if(sum_left[i-1] == sum_right[i+1])
			return true;
		
	}	

	return false;
}

int main()
{

	int testcases;

	cin >> testcases;
	for(int i = 0; i < testcases; i++){
		int nelems;
		vector <long> array;
		int t;
		
		cin >> nelems;
		for(int j = 0; j < nelems; j++){
			cin >> t;
			array.push_back(t);
		}
		if(search(array))
			cout << "YES\n";
		else
			cout << "NO\n";
		
	}
}
