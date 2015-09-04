#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int n, i, j;
    
  scanf("%d", &n);
  for(i = 1; i <= n; i++){
    for(j=0; j < n ; j++){
      if(j < n-i)
	cout << " ";
      else
	cout << "#";
	  }
    cout << "\n";
  }
        
    
    
  return 0;
}
