#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  int n, i, tmp;
  int number_pos = 0;
  int number_neg = 0;
  int number_zero = 0;
  float ratio = 0.0;
    
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", &tmp);
    if(tmp > 0)
      number_pos++;
    if(tmp < 0)
      number_neg++;
    if(tmp == 0)
      number_zero++;
  }
  ratio = number_pos/(float)n;
  printf("%.3f\n",ratio);
    
  ratio = number_neg/(float)n;
  printf("%.3f\n",ratio);
    
  ratio = number_zero/(float)n;
  printf("%.3f\n",ratio);
    
  return 0;
}
