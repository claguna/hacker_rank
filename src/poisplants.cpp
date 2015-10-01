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
	/*stack of index*/
	stack <int> s1;
	stack <int> s2;
	int ss1, ss2 = 0;
	
	for(unsigned int i = 0; i < A.size(); i++){	    
		s1.push(A[i]);
	}
    ss1 = s1.size();
	
	while(ss1 != ss2){
		ss1 = s1.size();
		while (!s1.empty()){
			int top = s1.top();
			s1.pop();
			if(!s1.empty() && s1.top() >= top){
				s2.push(top);
			}
			if(!s1.empty() && s1.top() < top){
				continue;
			}
			if(s1.empty() /*&& !s2.empty()*/){
				s2.push(top);
			}
		}
		ss2 = s2.size();
		while(!s2.empty()){
			s1.push(s2.top());
			s2.pop();
		}
		
		if(ss1!=ss2 && ss2 !=0)
			cycles++;
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