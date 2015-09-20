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

int cuttheboard(vector<long long> x, vector<long long> y)
{
	int current_segments = 0;
	int previous_segments = 0;   
	int cutsx = 0;
	int cutsy = 0;

	unsigned int t = 0;
	int i = x.size()-1;
	int j = y.size()-1;
	
	long long sum = 0;
	long long factor = 0;
	
	sort(x.begin(), x.end());
	sort(y.begin(), y.end());

    while(t < x.size() + y.size()){
		previous_segments = (cutsx+1) * (cutsy +1);
		if(j < 0){
			factor = x[i];
			i--;
			cutsx++;
			goto end;
		}
		  
		if(i < 0){
			factor = y[j];
			j--;
			cutsy++;
			goto end;
				
		}		   
		
		//cout << x[i] << " "<< y[j]<< endl;
		if(x[i] < y[j]){
			cutsy++;		   
			factor = y[j];
			j--;
		}else if(x[i] > y[j]){
			cutsx++;
			factor = x[i];
			i--;
		}else if(x[i] == y[j]){
			if(i < j){
				cutsy++;
				factor = y[j];
			    j--;
			}else{
				cutsx++;
				factor = x[i];
			    i--;
			}
		}
	end:
		current_segments = (cutsx+1) * (cutsy +1);
		//cout << "f "<< factor << " ter "<< (current_segments-previous_segments) << endl;
	    sum += (current_segments-previous_segments)*factor;
		t++;
	}
	sum = fmod(sum,pow(10, 9) +7 );
	return sum;
}

int main ()
{
	int testcases;
	int m, n ;
	cin  >> testcases;

	for(int i = 0; i < testcases; i++){
		vector<long long> x,y;
		cin >> m;
		cin >> n;
		m--;
		n--;
		for(int j = 0; j < m; j++){
			long long  t ;
			cin >> t;
			x.push_back(t);
		}
		for(int j = 0; j < n; j++){
			long long t ;
			cin >> t;
			y.push_back(t);
		}
		cout << cuttheboard(x, y)<< endl;
	}
}
