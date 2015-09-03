#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 10
#define LEFT(i) 2*(i)+1
#define RIGHT(i) 2*(i)+2
#define ARRAY_LENGHT(a) (sizeof(a)/sizeof(a[0]))
#define SWAP(a, b)  a ^= b; b ^= a; a ^= b; 

int  partition(int A[], int left, int right)
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


int k_th_largest_element(int A[],int left, int rigth,  int k)
{
  int rank;
  int j;
  int pivot=0;
  pivot = partition(A, left, rigth);
  rank = pivot-left+1;

  if(rank==k)
    return A[pivot];

  printf("%d %d\n", pivot, rank );
  if(rank > k){
    return k_th_largest_element(A, left, pivot-1, k);
  }else
    return k_th_largest_element(A, pivot+1, rigth , k-rank );

}
int main()
{
  int A[SIZE] = {6,4,8,3,10,2,5,1,9,7};
  int i= 0;
  int k =  5;

  //k = partition(A,0,SIZE-1);

  for(i = 0; i < SIZE; i++)
    printf("%d, ",A[i]);
  printf("\n");
  
  int kpos = k_th_largest_element(A,0, SIZE-1, k-1);
  printf("%d-th largest element %d \n", k, kpos );

  for(i = 0; i < SIZE; i++)
    printf("%d, ",A[i]);
  printf("\n");
}
