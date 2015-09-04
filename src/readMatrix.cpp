#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
  int n, i,j;
  int ** matrix;
    
  scanf("%d", &n);
  matrix = new int *[n];
  for (i=0; i < n; i++)
    matrix[i] = new int [n];
    
  for(i= 0; i < n; i++)
    for(j=0; j < n; j++)
      scanf("%d", &matrix[i][j]);
    
  //  cout << diagonal_diff(matrix, n);
  return 0;
}
