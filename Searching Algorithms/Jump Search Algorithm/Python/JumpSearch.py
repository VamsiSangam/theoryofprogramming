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


# Jump Search Code
def jump_search(alist, val):
	
	length = len(alist)
	
	# Calculating jump
	jump = _integer_sqrt(length)
	
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


# Function for finding integer square root
# Details are here: http://en.wikipedia.org/wiki/Integer_square_root
def _integer_sqrt(n):

	if n < 0:
		raise ValueError('Square root not defined for negative numbers...')
		
	# Find greatest shift.
	shift = 2
	nShifted = n >> shift
	
	# We check for nShifted being n, since some implementations of logical right shifting shift modulo the word size.
	while nShifted != 0 and nShifted != n:
		shift += 2
		nShifted = n >> shift
	
	shift -= 2
	
	# Find digits of result.
	result = 0
	while shift >= 0:
		result = result << 1
		candidateResult = result + 1
		
		if (candidateResult * candidateResult) <= (n >> shift):
			result = candidateResult
		shift -= 2
	
	return result
	
    
# Examples
alist = [1, 3, 5, 7, 9, 11, 13, 15, 17]
# Jump Search Results
print(jump_search(alist, 0))	#-1
print(jump_search(alist, 3))	# 1
print(jump_search(alist, 11))	# 5
print(jump_search(alist, 16))	# -1
