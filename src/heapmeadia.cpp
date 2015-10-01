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
#include <iomanip>

using namespace std;


class mycomparison
{
public:
  mycomparison()
		{}
  bool operator() (const int& lhs, const int&rhs) const
  {
      return (lhs>rhs);
  }
};

void hmedian(vector<int> A){
	priority_queue<int> maxh;
	typedef priority_queue<int, vector<int>,mycomparison> min_pq;
	min_pq  minh;
	
	float median = A[0];
	
	for(unsigned int i = 0; i < A.size(); i++){
		if(A[i] < median){
			maxh.push(A[i]);			
		}else{
			minh.push(A[i]);			
		}
		/*balance*/
		if( abs(minh.size() - maxh.size()) > 1 ){
			if(minh.size() > maxh.size()){
				maxh.push(minh.top());
				minh.pop();
			}else{
				minh.push(maxh.top());
				maxh.pop();
			}
		}
		/*compute median*/
		if(minh.size() == maxh.size()){
			median = (float)(minh.top() + maxh.top())/2;
		}else{
			if(minh.size() > maxh.size())
				median = minh.top();
			else
				median = maxh.top();
		}
		printf("%.1f\n",median);
		//cout  << median << endl;
	}
}

int main(){
	int n;
	cin >> n;
	vector<int> input;
	
	for(int i = 0; i < n; i++){
		int t;
		cin >> t;
		input.push_back(t);
	}
	hmedian(input);
}
