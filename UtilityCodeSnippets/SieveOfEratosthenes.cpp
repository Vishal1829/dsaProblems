#include <bits/stdc++.h> 
using namespace std; 

void SieveOfEratosthenes(int n) 
{ 
	// Create a boolean array "prime[0..n]" and initialize 
	// all entries it as true. A value in prime[i] will 
	// finally be false if i is Not a prime, else true. 
	bool prime[n+1]; 
	memset(prime, true, sizeof(prime)); 

	for (int p=2; p*p<=n; p++) 
	{ 
		// If prime[p] is not changed, then it is a prime 
		if (prime[p] == true) 
		{ 
			// Update all multiples of p greater than or 
			// equal to the square of it 
			// numbers which are multiple of p and are 
			// less than p^2 are already been marked. 
			for (int i=p*p; i<=n; i += p) 
				prime[i] = false; 
		} 
	} 

	// Print all prime numbers 
	for (int p=2; p<=n; p++) 
    if (prime[p]) 
      cout << p << " "; 
} 
/*
Reason for the inner loop starts with i^2 is suppose we are at n=5 so we will start marking all the multiples of 5 as false
and these are - 5*2,5*3,5*4 and so on but we can clealy see that 2,3 already processed and so we already marked all their
multiples as false we can can directly start from i^2 which is 5*5=25 as upto 24 all have been marked by 2 or 3 as false.

Another observation:- Explanation for outer loop runs upto sqrt(n) times is
https://math.stackexchange.com/questions/2692425/sieve-of-eratosthenes-why-sqrt-n-work

For n not to be prime, it needs at least two prime factors. The square root of n provides a 'pivot': 
if x is less than the square root of n, then y=n/x is greater than the square root of n.

So, if no prime factors are found by the square root of n and n is composite, at least two factors of n
must be greater than the square root of n, which is an obvious contradiction.
*/

int main() 
{ 
	int n = 30; 
	cout << "Following are the prime numbers smaller "
		<< " than or equal to " << n << endl; 
	SieveOfEratosthenes(n); 
	return 0; 
} 