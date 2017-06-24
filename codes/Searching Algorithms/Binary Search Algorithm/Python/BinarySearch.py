# ===== ===== =====
# Theory of Programming
# Binary Search Algorithm
# http://theoryofprogramming.com/2016/11/04/binary-search-algorithm/
# GitHub - https://github.com/VamsiSangam/theoryofprogramming
# Code Contributor - Saurabh Rane (github.com/ranesr)
# ===== ===== ===== */

def binarySearch(alist, item):

	low = 0
	high = len(alist) - 1
	
	# Searching item in array
	while low <= high:
		mid = (low + high) // 2

		if alist[mid] == item:
			return mid
		elif alist[mid] < item:
			low = mid + 1
		else:
			high = mid - 1
	
	# Item not found
	return -1

# Examples
list = [17, 20, 26, 31, 44, 54, 55, 77, 93]
print("Search list: ", list)
print("Index for 44 is %s" % (binarySearch(list, 44)))
print("Index for 93 is %s" % (binarySearch(list, 93)))
print("Index for 30 is %s" % (binarySearch(list, 30)))