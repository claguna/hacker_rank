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

#define MAX_NODES 100005

using namespace std;

bool funnystring(string a)
{
	bool result = true;
	int j = a.size()-1;
	for(unsigned int i = 1; i < a.size(); i++){
	    if( abs(a[i-1] - a[i]) != abs( a[j-1] - a[j]) ) {
			result = false;			
			break;
		}
		j--;
	}
	return result;
}

int main()
{
	int testcases;
	cin >> testcases;
	
	for(int i = 0; i < testcases; i++){
		string t;
		cin >> t;
		if(funnystring(t))
			cout << "Funny" << endl;
		else
			cout << "Not Funny" << endl;
	}
}