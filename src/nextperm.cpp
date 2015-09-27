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

void nextperm(string s){

	int i = s.size() - 1;
    while (i > 0 && s[i - 1] >= s[i])
        i--;
    // Now i is the head index of the suffix
    
    // Are we at the last permutation already?
    if (i <= 0){
		cout << "no answer"<< endl;
			return;
	}

	int j = s.size() - 1;
    while (s[j] <= s[i - 1])
        j--;
    // Now the value s[j] will become the new pivot
    // Assertion: j >= i
    
    // Swap the pivot with j
    int temp = s[i - 1];
    s[i - 1] = s[j];
    s[j] = temp;
    
    // Reverse the suffix
    j = s.size() - 1;
    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
	cout << s<< endl;
}

int main()
{
	int testcases;
	cin >> testcases;
	for(int i = 0; i < testcases; i++){
		string s;
		cin >> s;
		nextperm(s);
	}
}
