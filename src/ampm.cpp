#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
  char ampm[3];
  int hh, mm, ss;
    
  scanf("%d:%d:%d%s",&hh, &mm, &ss, ampm);
  if(ampm[0]=='P' && hh < 12){
    hh+=12;
  }else if(ampm[0]=='A' && hh==12)
    hh=0;

  printf("%02d:%02d:%02d\n",hh,mm,ss);
  return 0;
}
