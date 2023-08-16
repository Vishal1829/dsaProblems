#include <bits/stdc++.h>
using namespace std;
/*
Given N, print XOR of all numbers from 1 to N.
N=1  -->  0^1=1
N=2  -->  0^1^2=3
N=3  -->  0^1^2^3=0
N=4  -->  0^1^2^3^4=4
N=5  -->  0^1^2^3^4^5=1
N=6  -->  0^1^2^3^4^5^6=7
N=7  -->  0^1^2^3^4^5^6^7=0
N=8  -->  0^1^2^3^4^5^6^7^8=8
*/

int main()
{
    int N=89;

    if(N%4==0)  cout<<N;
    else if(N%4==1)  cout<<1;
    else if(N%4==2)  cout<<N+1;
    else if(N%4==3)  cout<<0;

    return 0;
}
//Note by using this question we can find XOR of all elements from a range [L,R] by using (1-R)^(1-(L-1))
/*
C++ built-in functions :-
__builtin__popcount() -> int
__builtin__popcountl() -> long int
__builtin__popcountll() -> long long int

Note:- 
There is NO __builtin_popcount in c++, it's a built in function of GCC. The function prototype is as follows: int __builtin_popcount(unsigned int) It returns the numbers of set bits in an integer (the number of ones in the binary representation of the integer).
*/