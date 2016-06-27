# Minimum number of swaps to get each pair next to each other

# We have a relationship of pairs R and an array of numbers
# The goal is rearrange the elements of the array so that the numbers are together
# using swaps

# Input:
# n = 3
# pairs[] = {1->3, 2->6, 4->5}  // 1 is partner of 3 and so on
# arr[] = {3, 5, 6, 4, 1, 2}

# Output: 2
# We can get {3, 1, 5, 4, 6, 2} by swapping 5 & 6, and 6 & 1

# Algorithm
def min_swaps(array, start, end, relations, index):
    if start >= end:
        return 0
    # if  first two elements are already in the relationship then
    # recurse on the array[n-2]
    if relations[array[start]] == array[start + 1]:
        return min_swaps(array, start + 2, end, relations)

    # There are two posibilites, return the minimum of those:

    # 1.- swap second element with pair of first element and recurse on the
    # remaining n-2 elements
    i = start + 1
    j = index[relations[array[start]]]
    array[i], array[j] = array[j], array[i]
      # update index
    index[array[j]] = i
    index[array[i]] = j
    a = min_swaps(array, start + 2, end, relations, index)
    # restore array to original values
    array[j], array[i] = array[i], array[j]
    index[array[j]] = j
    index[array[i]] = i

    # 2.- swap first element with pair of the second and recurse on the
    # remaining n-2 elements
    i = start
    j = index[relations[array[start +1 ]]]
    array[i], array[j] = array[j], array[i]
    index[array[j]] = i
    index[array[i]] = j
    b = min_swaps(array, start+ 2, end, relations, index)
    # restore array to original values
    array[i], array[j] = array[j], array[i]
    index[array[j]] = j
    index[array[i]] = i

    return 1 + min(a,b)



relations = {1 : 3, 3 : 1, 2 : 6, 6: 1, 4:5, 5 : 4}
arr = [3, 5, 6, 4, 1, 2]
index = {3:0, 5:1, 6:2, 4:3, 1:4, 2:5}

print min_swaps(arr, 0, len(arr), relations, index)