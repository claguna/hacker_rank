/* https://www.hackerrank.com/challenges/mark-and-toys  */
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
	int n;
	long k;
	int items = 0;
	long price = 0;
	
	vector<long> array;
	
	cin >> n;
	cin >> k;

	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		array.push_back(t);
	}
	sort(array.begin(), array.end());

	for(int i = 0; i < array.size(); i++){
		price += array[i];		
		if(price > k)
			break;
		items++;
	}

	cout << items;
}