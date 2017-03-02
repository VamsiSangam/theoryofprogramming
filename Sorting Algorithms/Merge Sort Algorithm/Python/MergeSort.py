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
		
		i = 0
		j = 0
		k = 0
		
		# Merge the two halves
		while i < len(left_half) and j < len(right_half):
			if left_half[i] < right_half[j]:
				array[k] = left_half[i]
				i = i + 1
			else:
				array[k] = right_half[j]
				j = j + 1
			k = k + 1
		
		# Copying leftover elements from left half
		while i < len(left_half):
			array[k]=left_half[i]
			i = i + 1
			k = k + 1
			
		# Copying leftover elements from right half
		while j < len(right_half):
			array[k]=right_half[j]
			j = j + 1
			k = k + 1

array = [54,26,93,17,77,31,44,55,20]
print("Merge Sort for ", array)
merge_sort(array)
print(array)