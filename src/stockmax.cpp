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

long stockmax(vector<long> prices,unsigned int start, unsigned int end)
{
	long max_profit = 0;
	long max_in_interval = start;
	long spent_money = 0;
	long shares_bought = 0;
	
	if(start > end)
		return 0;
    //cout << "start "<< start << " end "<< end<<endl;	
	/*Get Maximum price in interval*/
	for(unsigned int i = start; i < end; i++){
		if(prices[max_in_interval] < prices[i])
			max_in_interval = i;
	}
	

	//cout << "max_int "<< max_in_interval << " shares "<< shares_bought << "\n"; 
	for(unsigned int i = start; i < max_in_interval; i++){
		spent_money += prices[i];
		shares_bought++;
	}	
	
	if(shares_bought){
		max_profit = shares_bought* prices[max_in_interval] - spent_money;
        max_profit += stockmax(prices, max_in_interval+1, end);
	}
	
	return max_profit;
}

int main()
{
	int testcases;

	cin >> testcases;

	for(int i = 0; i < testcases; i++){
		int nelements;
		vector<long> array;
		int tmp;
		pair<int, int> dummy;
		cin >> nelements;
		
		for(int j = 0; j < nelements; j++){
			cin >> tmp;
			array.push_back(tmp);
		}
		cout << stockmax(array, 0, array.size()) << "\n";
	}
	return 0;
	
}
