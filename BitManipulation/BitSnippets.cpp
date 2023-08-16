#include <bits/stdc++.h>
using namespace std;

bool checkIthBitSetOrNot1(int n,int i){
    int mask=(1<<i);
    int set=(n & mask);
    cout<<set<<endl;
    if(set != 0)
      return true;
    return false;
}
bool checkIthBitSetOrNot2(int n,int i){
    int mask=(n>>i);
    int set=(mask & 1);
    cout<<set<<endl;
    if(set == 1)
      return true;
    return false;
}
void setIthBit(int &n,int i){
    int mask=(1<<i);
    n |= mask;
}
void clearIthBit(int &n,int i){
    int mask = ~(1<<i);
    n &= mask;
}
void removeTheLastSetBit(int &n){
    //Look always here the pattern for two consecutive numbers in bits -the last set
    //bit of big number and the same bit is off in smaller and after that bit in smaller
    //all the bits after that are 1's.
    //96 - 01100000
    //95 - 01011111
    //64 - 01000000
    n = n&(n-1);
}
bool checkPowerOfTwo(int n){
    if(( n & (n-1) ) == 0)
      return true;
    return false;
}
int countSetBits(int n){
    int cnt=0;
    while(n){
        cnt++;
        removeTheLastSetBit(n);
    }
    return cnt;
}
int main()
{
    int n=8;
    
    //Check ith bit set or not.
    checkIthBitSetOrNot2(n, 2);

    return 0;
}
/*
C++ built-in functions :-
__builtin__popcount() -> int
__builtin__popcountl() -> long int
__builtin__popcountll() -> long long int

Note:- 
There is NO __builtin_popcount in c++, it's a built in function of GCC. The function prototype is as follows: int __builtin_popcount(unsigned int) It returns the numbers of set bits in an integer (the number of ones in the binary representation of the integer).
*/