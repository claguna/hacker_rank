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

int maxhistrec(vector<int> A)
{
	int maxarea = 0;
	/*stack of index*/
	stack <int> s;
	for(unsigned int i = 0; i <= A.size(); i++){
		while( !s.empty() && ( A[s.top()] > A[i] || i == A.size())){
			int height = A[s.top()];
			s.pop();
			int area = height * ( s.empty()? i : i - s.top()-1 );
			maxarea = max(maxarea, area );
			//cerr << height << endl;
			
		}
		s.push(i);
	}
	return maxarea;
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
	cout << maxhistrec(array);
}
