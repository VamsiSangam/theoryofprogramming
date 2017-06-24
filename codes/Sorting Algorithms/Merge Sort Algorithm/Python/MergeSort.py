# ===== ===== =====
#
# Theory of Programming
#
# Merge Sort Algorithm
# http://theoryofprogramming.com/2015/01/29/merge-sort-algorithm/
# GitHub - https://github.com/VamsiSangam/theoryofprogramming
# Code Contributor - Saurabh Rane (github.com/ranesr)
#
# ===== ===== =====

# Merge Sort function using loops
def merge_sort(array):

	# Check if length of array is more than 1
	if len(array) > 1:
	
		# Getting middle element index
		mid = len(array) // 2
		left_half = array[:mid]
		right_half = array[mid:]
		
		# Merge sorting left half
		left = merge_sort(left_half)
		
		# Merge sorting right half
		right = merge_sort(right_half)
		
		# Merge the two halves & return it
		return mergeUsingLoops(left, right)
		
	else:
		# Return array with single element
		return array


# Merge function using loops	
def mergeUsingLoops(left, right):
	# If left part is empty, return right part
	if not left:
		return right
		
	# If right part is empty, return left part
	if not right:
		return left
	
	result = []
	i, j = 0, 0
	
	# Comparing values of both parts
	while(len(result) < len(left) + len(right)):
		if left[i] < right[j]:
			result.append(left[i])
			i += 1
		else:
			result.append(right[j])
			j += 1
		
		# Copying the remaining elements of one part
		if i == len(left) or j == len(right):
			result.extend(left[i:] or right[j:])
			break
	
	return result


# Merge Sort using second function
def mergesort(array):
	
	# Check if length of array is more than 1
	if len(array) > 1:
		
		# Getting middle element index
		mid = len(array) // 2
		left_half = array[:mid]
		right_half = array[mid:]
		
		# Merge sorting left half
		left = merge_sort(left_half)
		
		# Merge sorting right half
		right = merge_sort(right_half)
		
		# Merge the two halves & return it
		return merge(left, right)
		
	else:
		# Return array with single element
		return array


# Merge function
def merge(left, right):
	
	# If left part is empty, return right part
	if not left:
		return right
		
	# If right part is empty, return left part
	if not right:
		return left
	
	# Compare first element and merge the remaining elements of the part (with smaller element) with other part
	if left[0] < right[0]:
		return [left[0]] + merge(left[1:], right)
		
	return [right[0]] + merge(left, right[1:])


# Example
array = [54, 26, 93, 17, 77, 31, 44, 55, 20]
print("Merge Sort for ", array)
print("Sorted array using loops: ", merge_sort(array))
print("Sorted array using another function: ", mergesort(array))
