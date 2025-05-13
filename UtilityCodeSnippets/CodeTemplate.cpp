#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int,int>;
using int3 = tuple<int, int, int>;
using pis = pair<string, int>;

#define MOD 1000000007
#define INF 1e18
#define PI 3.141592653589793238462

#define pb push_back
#define ppb pop_back

//comparator for priority_queue
struct myCmp {
    bool operator()(const pis& a, const pis& b) {
        if (a.second == b.second) {
            return a.first < b.first; // if freq equal, lexicographically bigger comes first
        }
        return a.second > b.second; // otherwise, smaller freq comes first
    }
};


int main() {

  //MAX & MIN Values
  long maxLong = LONG_MAX;
  long minLong = LONG_MIN;
  long maxLongLong = LLONG_MAX;
  long minLongLong = LLONG_MIN;

  int i=1, j=2;
  //direction vector for up, down, right, left in a matrix
  const static int d[5] = {0, 1, 0, -1, 0}; // note: length is 5
  for (int a = 0; a < 4; a++) {
      int r = i + d[a], s = j + d[a + 1];
  }

  int3 triplet = {1, 2, 3};
  //to access tuple
  std::get<0>(triplet);

  []() {
    cout<<"immediately invoked lambda function";
  }();

  cout<<endl;
  auto val = []() -> int {
      cout<<"immediately invoked lambda function with return value";
      return 1;
  }();
  cout<<endl<<val;

  return 0;
}
