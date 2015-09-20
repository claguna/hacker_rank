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

#define SWAP(a, b)  a ^= b; b ^= a; a ^= b; 

void partition(vector <int>  ar) {
	int s = ar.size()-1;
	int p = ar[s];
	unsigned int i = 0;
	
	SWAP(ar[0], ar[s]);
	p = ar[s];

    for(unsigned int j = i + 1; j < ar.size(); j++){

		if(ar[j] <= p){     
			SWAP(ar[i],ar[j]);
			i++;
		}		
	}
	
	SWAP (ar[i], ar[s]);
	
	for(unsigned int i = 0; i < ar.size(); i++)
		cout << ar[i]<< " ";
	cout << endl;

}
int main(void) {
	vector <int>  _ar;
	int _ar_size;
	cin >> _ar_size;
	for(int _ar_i=0; _ar_i<_ar_size; _ar_i++) {
		int _ar_tmp;
		cin >> _ar_tmp;
		_ar.push_back(_ar_tmp); 
	}

	/*p is at the beginning*/
	partition(_ar);
   
	return 0;
}
