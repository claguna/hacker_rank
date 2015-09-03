#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int calculateFine(int d1, int m1, int y1, int d2, int m2, int y2){
  // book return on the due date or before return 0
  if(d1 <= d2 && m1 <= m2 && y1 <= y2)
    return 0;
  if(m1 < m2 && y1 <= y2)
    return 0;
        
  //same month -> 15*number late days
  if(m1 == m2 && y1 == y2)
    return abs(d2 - d1)*15;
    
  //same year  -> 500*number of late months
  if(y1 == y2)
    return 500 * abs(m2 - m1);
  //more than a year -> 10000
  if(y2<y1)
    return 10000;

  return 0;
}

int main() {
  int d1, m1, y1, d2, m2, y2;
    
  scanf("%d %d %d", &d1, &m1, &y1);
  scanf("%d %d %d", &d2, &m2, &y2);
  cout << calculateFine(d1, m1, y1, d2, m2, y2) << "\n";
  return 0;
}
