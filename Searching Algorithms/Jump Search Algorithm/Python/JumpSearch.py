# ===== ===== =====
#
# Theory of Programming
#
# Jump Search Algorithm
# http://theoryofprogramming.com/2016/11/10/jump-search-algorithm/
# GitHub - https://github.com/VamsiSangam/theoryofprogramming
# Code Contributor - Saurabh Rane (github.com/ranesr)
#
# ===== ===== ===== */

import math

# Jump Search Function
def jump_search(alist, val):
	
	length = len(alist)
	
	# Calculating jump
	jump = int(math.sqrt(length))
	
	left, right = 0, 0

	while left < length and alist[left] <= val:
		right = min(length - 1, left + jump)
		
		if alist[left] <= val and alist[right] >= val:
			break
			
		left += jump;
		
	if left >= length or alist[left] > val:
		return -1
		
	right = min(length - 1, right)
	
	i = left
	while i <= right and alist[i] <= val:
		if alist[i] == val:
			return i
		i += 1
	
	return -1
	
    
# Examples
alist = [1, 3, 5, 7, 9, 11, 13, 15, 17]
# Jump Search Results
print(jump_search(alist, 0))	# -1
print(jump_search(alist, 3))	#  1
print(jump_search(alist, 11))	#  5
print(jump_search(alist, 16))	# -1
