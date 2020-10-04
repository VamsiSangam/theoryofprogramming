#include <iostream>
using namespace std;
#define PRIME 1000000007		// Prime Number

long long int factorial(long long int n)
{
	if(n==1||n==0){ // the factorial of 1 and 0 is 1 
  return 1;
	} else {
		return ((n % PRIME) * (factorial(n - 1) % PRIME)) % PRIME;
	}
}

int main()
{
	long long int x, y;

    cin>>x>>y;

	x = factorial(x);

	y = factorial(y);


	long long int answer = (x + y) % PRIME;

   cout<<answer<<endl;

	return 0;
}
