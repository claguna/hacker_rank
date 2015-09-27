#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>

#define SWAP(a, b)  a ^= b; b ^= a; a ^= b; 

using namespace std;

int  partition(vector<int> &A, int left, int right)
{
  int i = left;
  int j= i+1;
  int pivot = A[right];
  
  while(j < right){

    if(A[j] <= pivot){     
      SWAP(A[i],A[j]);
      i++;
    }
    j++;
  }
  SWAP(A[i],A[right]);

  return i;
}


int k_th_largest_element(vector<int> &A,int left, int rigth,  int k)
{
	int rank, pivot;	
	pivot = partition(A, left, rigth);
	rank = pivot-left +1;
	
	for (int i = 0; i < A.size(); i++)
		cout << A[i];
	cout << endl;
	
	if(rank == k)
		return A[pivot];

	if(rank > k)
		return k_th_largest_element(A, left, pivot -1, k);
	else
		return k_th_largest_element(A, pivot+1, rigth, k-rank);
}

int main()
{
	int n;
	cin >> n;
	vector<int> a;
	for (int i = 0; i < n; i++){
		int t;
		cin >> t;
		a.push_back(t);
	}
	cout << k_th_largest_element(a, 0, a.size()-1, (a.size())/2);
}
