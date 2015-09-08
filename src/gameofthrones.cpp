#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <queue>
#include <math.h>
#include <map>
#include <stdlib.h>
using namespace std;
#define ACCEPTED 0
#define F first
#define S second
#define PI (acos(-1.0))
#define EPS (1e-11)
#define INF (1<<30)
int dx[] = {1,0,-1,0}, dy[] = {0,1,0,-1};
/* ============================================== */

int main(){
	string s;
	cin >>  s;

	vector<int> v(256, 0);
	for(int i=0; i<s.size(); i++) v[s[i]]++;

	int impar =0;
	for(int i=0; i<256; i++)
		if(v[i]%2) impar++;

	if ( (impar%2 != 0 || s.size() % 2 != 0))
	  puts("YES");
  else puts("NO");
  
  return ACCEPTED;
}
/* ============================================== */
