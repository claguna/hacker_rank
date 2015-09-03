#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

#define SIZE 10
#define LEFT(i) 2*(i)+1
#define RIGHT(i) 2*(i)+2
#define ARRAY_LENGHT(a) (sizeof(a)/sizeof(a[0]))
#define SWAP(a, b)  a ^= b; b ^= a; a ^= b; 

void max_hepify(int A[], int i, int sizeA)
{
  int l = LEFT(i);
  int r = RIGHT(i);
  int largest = i;

  if(l < sizeA && A[l]>A[i])
    largest = l;
  else
    largest = i;

  if(r < sizeA && A[r]>A[largest])
    largest = r;

  if(largest != i)
  {
    SWAP(A[largest],A[i]);
    max_hepify(A,largest,sizeA);
  }
}

void build_heap(int A[], int size)
{
  /*build the heap from bottom up.
    all the elemenst bigger than floor(size/2)
    are leafs, then those elements are already a max heap
   */
  int i;
  for(i = size/2; i>=0 ; i--)
     max_hepify(A, i, size);  
}


void heapsort(int A[], int size)
{
  int i;

  build_heap(A,size);

  for(i = size-1; i > 0; i--){    
    SWAP(A[0],A[i]);
    max_hepify(A,0, i);
  }
}
int main()
{   
  int A[SIZE] = {6,4,8,9,10,2,5,1,9,10};
  int i= 0;

  //build_heap(A,SIZE);
  heapsort(A,SIZE);

  for(i = 0; i < SIZE; i++)
    printf("%d, ",A[i]);
  printf("\n");

  return 0;
}
