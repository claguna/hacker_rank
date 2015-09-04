#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int getanswer(int **m, int n, vector<int> currency){
  int i,j,r;
  r =0;

  i=currency.size()-1; j=n;
 
  while(i>0 && j> 0){
    if(m[i][j] == m[i-1][j]){ //comming from top
      i -=1;      
    }else{ //take coin
      j = j- currency[i];
      r += currency[i];
      cout << currency[i] << "\n";
    }
  }
  //cout << "\n";
  return r;
}


/* 
Given an array of elements and k is the expected sum.

Select 0 or more elements from array such that the 
sum of these numbers is as near as possible
(but not exceeding) to k.
*/
int knapsack_coins(vector<int> currency, int k){
  /*Create a matrix of dimension (currency.size , k)
  */
  int **m;
  m  = new int *[currency.size()+1];
  for(int i = 0; i <= currency.size(); i++){
    m[i] = new int[k];
  }
  
  /*The entry (i,j) represents the maximum weight we can ccurrencyy if we take element i
    if the sack has maximum weight of j
   */

  /* (0,j) = 0 If we are not taking any elements then the sum is zero*/
  for(int j=0; j<=k; j++)
    m[0][j] = j;
  
  /*
    The item i has weight w, if we cannot ccurrencyy w more weigth then we leave the object
   currency[i,w] = currency[i-1,w] 
   If we can ccurrencyy the it we have to compare the value of pick the item vs not pick it
   currency[i,w] = max( currency[i-1,w], currency[i-1,w-wi]+vi)
    */
  for(int i=1; i<currency.size(); i++){
    for(int w=1; w<=k; w++){
      if(currency[i]==w)
	m[i][w] = 1;

      if(currency[i] > w){ // the coin we have is bigger than teh current w -> we can't pick the coin
	m[i][w] = m[i-1][w]; 

      }else{ 
        m[i][w] = min(m[i-1][w], 1 + m[i][w-currency[i]] );
      }
    }
  }

  for(int i=0; i < currency.size(); i++){
    cout << currency[i] << "   ";
    for(int w=0; w <= k; w++){
      cout << m[i][w] << " ";
    }
    cout << "\n";
  }

  return getanswer(m, k, currency);
  //return m[currency.size()][k];
}

int main()
{
  int n_cases;
  int n, k;   

  /*Input */
  scanf("%d",&n_cases);
  for(int i=0; i < n_cases; i++){
    scanf("%d %d",&n, &k);
    vector <int>  ar;

    ar.push_back(0);
    /*Read currency*/
    for(int ar_i=1; ar_i <= n; ar_i++) {
      int tmp;
      cin >> tmp;
      ar.push_back(tmp);
    }
    cout << knapsack_coins(ar, k) << "\n";
  }
  return 0;
}
