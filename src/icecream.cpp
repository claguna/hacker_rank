/*https://www.hackerrank.com/challenges/icecream-parlor*/
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

/*Given A an array and a number t, find two elements in A
that sum t*/
void icecream(vector<int> price, int t)
{
	map<int, int> map;
	//cout << endl;
	for(int i = 0; i < price.size(); i++){
        map[t- price[i]] = i;
		// cout << t- price[i]<<"  "<<map[t- price[i]]<<endl;
	}
	for(int i = 0; i < price.size(); i++){
		if(map.find(price[i])!= map.end()){
			if(map[price[i]]>i)
				cout<< i+1 << " "<< map[price[i]] +1<<endl;		    
      }					
	}
	
}

int main()
{
	int testcases;
	cin >> testcases;

	for(int i = 0; i < testcases; i++){
		int array_size;
		int target;
		vector<int> array;
		int tmp;

		cin >> target;
		cin >> array_size;
		for(int j = 0; j < array_size; j++){
			cin >> tmp;
			array.push_back(tmp);
		}
        icecream(array,target);
	}
	return 0;
}
