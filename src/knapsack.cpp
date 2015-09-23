#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool debug = false;
/* 
Given an array of elements and k is the expected sum.

Select 0 or more elements from array such that the 
sum of these numbers is as near as possible
(but not exceeding) to k.
*/
int knapsack(vector<int> arr, int k){
  /*Create a matrix of dimension (arr.size , k)
  */
  // int **m;
  // m  = new int *[arr.size()+1];
  // for(int i = 0; i <= arr.size(); i++){
  //   m[i] = new int[k];
  // }
  vector<vector<int> > m(arr.size()+1, vector<int>(k+1));
  
  /*The entry (i,j) represents the maximum weight we can carry if we take element i
    if the sack has maximum weight of j
   */

  /* (0,j) = 0 If we are not taking any elements then the sum is zero*/
  for(int j=0; j<=k; j++)
    m[0][j] = 0;

  for(int i = 0; i <= arr.size(); i++){
	  for(int j=0; j <= k; j++)
		  m[i][j] = 0;	  
  }

  /*
    The item i has weight w, if we cannot carry w more weigth then we leave the object
   arr[i,w] = arr[i-1,w] 
   If we can carry the it we have to compare the value of pick the item vs not pick it
   arr[i,w] = max( arr[i-1,w], arr[i-1,w-wi]+vi)
    */
  for(int i=1; i<=arr.size(); i++){
    for(int w=1; w<=k; w++){
      if( arr[i] > w){ //we cannot carry this iterm
	    m[i][w] = m[i-1][w];
      }
      else{
		  //cout << m[i][w-arr[i]] << " "<< w-arr[i]<< endl;
		  m[i][w] = max( m[i-1][w], m[i][w-arr[i]] + arr[i]);		  		 
		  
		  //m[i][w] = max( m[i-1][w], m[i-1][w-arr[i]] + arr[i]);
        // in this case value of i = its weight
      }
    }
  }

  if(debug){
	  for(int i=0; i <= arr.size(); i++){
		  for(int w=0; w <= k; w++){
			  cout << m[i][w] << " ";
		  }
		  cout << "\n";
	  }	  
  }
  
  
  return m[arr.size()][k];    
}

int main()
{
  int n_cases;
  int n, k;   

  /*Input */
  cin >> n_cases;
  for(int i=0; i < n_cases; i++){
	cin >> n >> k ;
    vector <int>  ar;

    ar.push_back(-1);
    /*Read array*/
    for(int ar_i=1; ar_i <= n; ar_i++) {
      int tmp;
      cin >> tmp;
      ar.push_back(tmp);
    }
    cout << knapsack(ar, k) << endl;
  }
  return 0;
}