#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

ll expo(ll a, ll b, ll mod){
    ll res = 1;
    while(b > 0) {
        if(b & 1)
          res = (res * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return res;
}


int main() {
  // cout<<expo(2,8,10007);
  return 0;
}