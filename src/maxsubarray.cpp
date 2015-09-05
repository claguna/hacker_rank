#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <utility> 
#include <limits>

using namespace std;
/*https://www.hackerrank.com/challenges/maxsubarray*/


/*Get the max contigous sub array.
  We keep track of the sum and best sum from the start of the
  array to the end.
  if the sum goes negative, it means all the elements we have 
  visited will not be part of the result then, we can discard
  them and save the start position only when the sum is cero.
  The end position is updated only when the current sum is
  better than the best sum.
*/
int max_sub_array(vector<long> array)
{

  int start_pos   = -1;
  int end_pos     = -1;
  long best_sum    = 0;
  long current_sum = 0;
  bool all_negatives = true;
  long biggest_element = numeric_limits<long>::min();
  
  for(unsigned int i = 0; i < array.size(); i++){
	  int tmp = current_sum;
	  
	  if(array[i] > 0)
		  all_negatives = false;
	  
	  if(biggest_element < array[i])
		  biggest_element = array[i];
	  
	  current_sum += array[i];
	  if(current_sum >= 0){
		  if(tmp == 0){
			  start_pos = i;
		  }
		  if(best_sum < current_sum){
			  best_sum = current_sum;
			  end_pos = i;
		  }
	  }else{
		  current_sum = 0;
	  }
  }
  /*all the elements are negative, then return the max element*/
  if(best_sum == 0 && all_negatives)
	  return biggest_element; 
  return best_sum;
}
int main()
{
  int testcases;

  scanf("%d", &testcases);

  for(int i = 0; i < testcases; i++){
    int array_l;
	long max_non_contiguos = 0;
	long max_contiguos = 0;
	
    vector <long> array;
      
    scanf("%d", &array_l);     
    for(int j = 0; j < array_l; j++){
      long tmp;
      cin >>tmp;
      array.push_back(tmp);
	  if(tmp > 0)
		  max_non_contiguos += tmp;
    }
	/*it's possible that all elements are negative.
      In that case max_sub_array will return the max element 
      (it will be negative) so, the max_non_contigous sum will 
      be that number*/
	max_contiguos = max_sub_array(array);
	if(max_contiguos < 0 && max_non_contiguos == 0)
		max_non_contiguos = max_contiguos;
	
	cout << max_sub_array(array) << " "<< max_non_contiguos << "\n";
  }
  return 0;
}
