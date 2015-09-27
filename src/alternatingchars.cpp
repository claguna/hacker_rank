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

int altchars(string s){
	int res = 0;
	
	for(unsigned int i = 0, j = 1; j < s.size(); j++){
		if(s[i] == s[j]){
			res++;
			continue;			
		}
		i = j;
	}
	return res;
}

int main(){
	int testcases;
	cin >> testcases;
	while(testcases--){
		string s;
		cin >> s;
		cout << altchars(s) << endl;
	}
}
