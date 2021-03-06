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
using namespace std;
int shifts;

void insertionSort(vector <int>  ar) {
	int i;
	shifts = 0;
	for (unsigned int j = 1; j < ar.size(); j++){
		i = j;
		int t = ar[i];    
		while(t < ar[i-1] && i > 0 ){
			shifts++;			
			ar[i] = ar[i-1];                    
			i--;     
		}
		ar[i]=t;
	}
	cout <<shifts<< "\n";

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

	insertionSort(_ar);
   
	return 0;
}