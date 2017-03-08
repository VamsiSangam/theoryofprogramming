# ===== ===== =====
#
# Theory of Programming
#
# Quick Sort Algorithm
# http://theoryofprogramming.com/2015/01/20/quick-sort-algorithm/
# GitHub - https://github.com/VamsiSangam/theoryofprogramming
# Code Contributor - Saurabh Rane (github.com/ranesr)
#
# ===== ===== ===== */

# Quick Sort Function
def quickSort(alist):
	quickSortHelper(alist, 0, len(alist) - 1)


# Helper Function
def quickSortHelper(alist, start, end):

	# If there are two or more elements
	if start < end:
		
		# Partition the list
		split = partition(alist, start, end)
		
		# Sort both halves
		quickSortHelper(alist, start, split - 1)
		quickSortHelper(alist, split + 1, end)


# Partition Function
def partition(alist, start, end):

	# Partition around the last value
	pivot = alist[end]
	bottom = start - 1
	top = end
	
	done = 0
	
	# Until all elements are partitioned
	while not done:
		
		# Until we find an out of place element
		while not done:
			# Move 'bottom' up
			bottom += 1
			
			# If we hit the 'top', we are done
			if bottom == top:
				done = 1
				break
			
			# 'bottom' out of place, put it at the 'top', and start searching from the 'top'
			if alist[bottom] > pivot:
				alist[top] = alist[bottom]
				break

		# Until we find an out of place element
		while not done:
			# Move 'top' down
			top -= 1
			
			# If we hit the 'bottom', we are done
			if top == bottom:
				done = 1
				break
				
			# 'top' out of place, put it at the 'bottom', and start searching from the 'bottom'
			if alist[top] < pivot:
				alist[bottom] = alist[top]
				break
	
	# Put the pivot in its place
	alist[top] = pivot
	
	# Return the split point
	return top
	
	
# Example	
alist = [1, 5, 2, 7, 3, 9, 4]
quickSort(alist)
print(alist)
