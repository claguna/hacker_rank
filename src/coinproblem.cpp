#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

long knapsack_coins(vector <int>  c, int dlls)
{
  /*Create a matrix of dimension (currency.size , k)
  */
  long **m;
  m  = new long *[c.size()+1];
  for(int i = 0; i <= c.size(); i++){
    m[i] = new long[dlls];
  }

  /*Initialize first row*/
  for(int i = 1; i<= dlls; i++){
    if(i % c[1] == 0)
      m[1][i] = 1;
    else
      m[1][i] = 0;
  }

  for(int i = 2; i<= c.size(); i++){
    for(int w = 0; w <= dlls; w++){     
      if(w == c[i]){
	m[i][w] = 1 + m[i-1][w];
      }else if(w < c[i]){
	m[i][w] = m[i-1][w];
      }
      else{       
	m[i][w] = m[i-1][w] + m[i][w-c[i]];
      }
    }
  }
 // for(int i=0; i < c.size(); i++){
 //    cout << c[i] << "   ";
 //    for(int w=0; w <= dlls; w++){
 //      cout << m[i][w] << " ";
 //    }
 //    cout << "\n";
 //  }

  return m[c.size()-1][dlls];

}

int main(){
  int dlls, ncoins;   

  /*Input */

    scanf("%d %d",&dlls, &ncoins);
    vector <int>  ar;

    ar.push_back(0);
    /*Read currency*/
    for(int ar_i=1; ar_i <= ncoins; ar_i++) {
      int tmp;
      cin >> tmp;
      ar.push_back(tmp);
    }
    cout << knapsack_coins(ar, dlls) << "\n";
  return 0;
}
