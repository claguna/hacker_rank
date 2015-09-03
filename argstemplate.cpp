#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int size;
  int i, tmp;
  long long sum;
 
  scanf("%d", &size);
    
  for(i = 0; i< size; i++)
    {
      scanf("%d", &tmp);
      sum += tmp;
    }
  cout<<sum;
  return 0;
}
