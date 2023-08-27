#include<bits/stdc++.h>
using namespace std;

/*
Catalan Number is a sequence of numbers just like fibonacci numbers.
1, 1, 2, 5, 14, 42, 132, .....
Also - C0 = 1, C1 = 1
Nth Catalan Number formula:-
Cn = C0*C(N-1) + C1*C(N-2) + C2*C(N-3) + C3*C(N-4) + ..... + C(N-1)*C0

C2 = C0*C1 + C1*C0
C3 = C0*C2 + C1*C1 + C2*C0
C4 = C0*C3 + C1*C2 + C2*C1 + C3*C0
C5 = C0*C4 + C1*C3 + C2*C2 + C3*C1 + C4*C0
*/

int getNthCalatalNo(int n) {
    vector<int> dp(n+1, 0);
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }

    return dp[n];
}
/*
Questions based on Nth Catalan Numbers are:-
No. of BST's :- for a given no. of nodes find how many BST can be possible.
Ans =  Nth Catalan Number
Ex:- suppose 4 nodes given A,B,C,D also A<B<C<D. Also we can choose any one as root node and can create BST.
so for A:- 0 on left and 3 on right
so for B:- 1 on left and 2 on right
so for C:- 2 on left and 1 on right
so for D:- 3 on left and 0 on right
so Ans = C0*C3 + C1*C2 + C2*C1 + C3*C0 = C4
*/

int main() {

  return 0;
}
