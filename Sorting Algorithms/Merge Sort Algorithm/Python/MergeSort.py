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

def merge_sort(array):

	# Check if length of array is more than 1
	if len(array) > 1:
	
		# Getting middle element index
		mid = len(array)//2
		left_half = array[:mid]
		right_half = array[mid:]
		
		# Merge sorting left half
		merge_sort(left_half)
		
		# Merge sorting right half
		merge_sort(right_half)
		
		# Merge the two halves & return it
		merge(left_half, right_half)
		
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
	if left[0] < right[0]
		return left[0] + merge(left[1:], right)
		
	return right[0] + merge(left, right[1:])

# Example
array = [54, 26, 93, 17, 77, 31, 44, 55, 20]
print("Merge Sort for ", array)
print(merge_sort(array))
