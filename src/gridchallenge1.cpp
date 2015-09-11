#include <cstdio>
#include <cmath>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <map>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>

using namespace std;

#define rep(i,a,b) for(int i = a; i < b; i++)
#define S(x) scanf("%d",&x)
#define P(x) printf("%d\n",x)

typedef long long int LL;
string s[111];

int main() {
   int t;
   S(t);
   while(t--) {
      int n;
      S(n);
      rep(i,0,n) {
         cin >> s[i];
         sort(s[i].begin(), s[i].end());
      }

      bool flag = true;
      rep(i,0,n) {
		  rep(j,1,n) {			  
			  if( s[i][j-1] > s[i][j]  ){
				  cout << i <<" "<<j << s[i][j] <<" " <<s[i][j+1] << endl;
				  flag = false;
			  }             
		  }
      }
      if(!flag) printf("NO\n");
      else printf("YES\n");
   }

   return 0;
}
