/*https://www.hackerrank.com/challenges/missing-numbers*/
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

void printMissingNumbers(vector<int>l1, vector<int> l2 )
{
	/*frequency table*/
	vector<int> miss(101,-1);	

	/*find min number*/
	int min = 100010;
	for(unsigned int i = 0; i < l2.size(); i++){		
		if(l2[i]<min)
			min = l2[i];
	}	
	for(unsigned int i = 0; i < l2.size(); i++){
		if(miss[l2[i]-min]== -1)
		    miss[l2[i]-min] = 0;
		miss[l2[i]-min]++;
	}	
	for(unsigned int i = 0; i < l1.size(); i++){
		miss[l1[i]-min]--;
	}
	
	for(unsigned int i = 0; i < 101; i++){
		if(miss[i]>0)
			cout << i + min << " ";
	}

	
}

int main()
{
	int firstl_size;
	int seclist_size;
	vector<int> l1;
	vector<int> l2;
	
	cin >> firstl_size;

	for(int i = 0; i < firstl_size; i++){
		int t;
		cin >> t ;
		l1.push_back(t);
	}

	cin >> seclist_size;
	for(int i = 0; i < seclist_size; i++){
		int t;
		cin >> t;
		l2.push_back(t);
	}
	printMissingNumbers(l1,l2);
	
	
}
