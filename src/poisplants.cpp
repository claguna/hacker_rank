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



int poisplants(vector<int> A)
{
	int cycles = 0;
	list <int> l;
	list<int>::iterator it1,it2;
	
	int s1, s2 = 0;
	/*stack of index*/
	
	for(unsigned int i = 0; i < A.size(); i++){	    
		l.push_back(A[i]);
	}
	s1 = l.size();

	while(s1 != s2){
		
		it1 = l.begin();
		it2 = l.begin();
		it2++;
		while(it2 != l.end()){
			
		}
		
	}
	
	
	return cycles;
}

int main(){
	int n;
	vector<int> array;
	cin >> n;

	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		array.push_back(t);
	}	
	cout << poisplants(array);
}
