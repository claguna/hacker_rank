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

int stockmax(vector<int> prices)
{
	int max_profit = 0;
	int local_min = 0;
	int local_max = 0;
	int local_buy = 0;
    int shares_bought = 0;
	
	//cout << "------\n";
	for(unsigned int i = 0; i < prices.size(); i++){		
		if(prices[i] < prices[local_min])
			local_min = i;
		//cout <<"lmin "<< local_min << "\n";
		if(prices[i] > prices[local_max])
			local_max = i;
		//cout <<"lmax "<< local_max << "\n";
		
		if( (i < prices.size()-1 && prices[i] > prices[i+1]) || (i == prices.size()-1 && prices[i-1] < prices[i]) ){
			if(local_buy > 0)
				max_profit += prices[local_max]*shares_bought - local_buy;
			else
			  max_profit += prices[local_max] - prices[local_min];
			local_min = i;
			local_max = i+1;
			local_buy = 0;
			shares_bought = 0;
		}
		
		if(i < prices.size()-1 && prices[i] < prices[i+1])
		{
			local_buy += prices[i];
			shares_bought ++;
			//cout << "lbuy "<<local_buy<<"\n";
		}
	}
	return max_profit;
}

int main()
{
	int testcases;

	cin >> testcases;

	for(int i = 0; i < testcases; i++){
		int nelements;
		vector<int> array;
		int tmp;
		
		cin >> nelements;
		
		for(int j = 0; j < nelements; j++){
			cin >> tmp;
			array.push_back(tmp);
		}
		cout << stockmax(array) << "\n";
	}
	return 0;
	
}