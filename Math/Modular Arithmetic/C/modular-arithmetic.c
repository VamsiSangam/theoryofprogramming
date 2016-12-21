/* ===== ===== =====

Theory of Programming

Printing (x! + y!) mod m, where x, y can be big
http://theoryofprogramming.com/2014/12/24/modular-arithmetic-properties/
Code Contributor - Vamsi Sangam

===== ===== ===== */

#include <stdio.h>

#define PRIME 1000000007		// Or any prime

// Returns (n! % PRIME)
long long int factorial(long long int n)
{
	if (n == 0) {
		return 1;
	} else if (n == 1) {
		return 1;
	} else {
		// Applying our eq.(2) to --> n * factorial(n - 1)
		// to get --> (n! % PRIME)
		return ((n % PRIME) * (factorial(n - 1) % PRIME)) % PRIME;
	}
}

int main()
{
	long long int x, y;
	
	scanf("%lld%lld", &x, &y);		// Don't forget the &'s...!

	x = factorial(x);
	//Overwriting the value of (x! % PRIME) in x itself
	y = factorial(y);
	//Overwriting the value of (y! % PRIME) in y itself
	
	//Applying our eq.(1) to get --> (x! + y!) % PRIME
	long long int answer = (x + y) % PRIME;
	
	printf("%lld\n", answer);
	
	return 0;
}
