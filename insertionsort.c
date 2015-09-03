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
void insertionSort(vector <int>  ar) {
  int i, j; 
  j = i;
  for (int j = 1; j < ar.size(); j++){
    i = j;
    int t = ar[i];    
    while(t < ar[i-1] && i > 0 ){
      ar[i] = ar[i-1];                    
      i--;     
    }    
    ar[i]=t;          
    for(int k = 0; k < ar.size(); k++)
	cout<<ar[k]<<" ";  
    cout << "\n";
  }

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
