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
/*https://www.hackerrank.com/challenges/candies*/
int candies(vector<long> rank)
{
	vector<int> c;
	int res = 0;
	
	/*In the beginning all the children have one candy*/
	for(unsigned int i=0; i < rank.size(); i++){
		c.push_back(1);	
	}
	
    /*compute increasing sequences from left to right*/
	for(unsigned int i = 0; i < rank.size()-1; i++){
		if(rank[i] < rank[i+1])
			c[i+1] = 1 + c[i];
	}
	
	/*Compute incresing sequences from right to left*/
	for(unsigned int i = rank.size()-1; i > 0; i--){
		/*Check the rank is incresing to the left
          and the coins of the higher rank needs to be
          adjusted*/
		if(rank[i-1] > rank[i] && c[i-1] <= c[i])
			c[i-1] = 1+ c[i];
			
	}
	
    /*Sum the number of candies given*/
	for(unsigned int i=0; i < c.size(); i++){
		res += c[i];
	}		
	return res;
}

int main(){
	
	int number_children = 0;
	vector <long> ranks;
	
	cin >> number_children;
	for(int i = 0; i < number_children; i++){
		long tmp;
		cin >> tmp;
		ranks.push_back(tmp);
	}
	cout << candies(ranks) << "\n";
	return 0;
}