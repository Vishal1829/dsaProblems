#include <bits/stdc++.h>
using namespace std;
using pis=pair<int,string>;

vector<string> getAllNeighbours(string &a) {
    vector<string> neighbors;
    for(int i=0;i<a.length();i++) {
        char ch=a[i];
        
        int digit = a[i] - '0';

        // Increment
        if (digit < 9) {
            a[i] = (digit + 1) + '0';
            neighbors.push_back(a);
        }

        // Decrement
        if (digit > 0) {
            a[i] = (digit - 1) + '0';
            neighbors.push_back(a);
        }

        // Double
        if (digit * 2 <= 9) {
            a[i] = (digit * 2) + '0';
            neighbors.push_back(a);
        }
        
        a[i]=ch;
    }
    
    return neighbors;
}

pair<int, vector<string>> solve(string &a, string &b) {
    unordered_set<string> visited;
    unordered_map<string, string> parent;
    queue<pis> q;
    q.emplace(1, a);
    visited.insert(a);
    parent[a]=a;
    while(!q.empty()) {
        auto [numCnt, num]=q.front();
        q.pop();
        if(num==b) {
            vector<string> path;
            while(parent[num]!=num) {
                path.push_back(num);
                num=parent[num];
            }
            path.push_back(num);
            return {numCnt, path};
        }
        //go thorugh all the neighbours of num
        for(string neighbour : getAllNeighbours(num)) {
            if(!visited.count(neighbour)) {
                q.emplace(numCnt+1, neighbour);
                visited.insert(neighbour);
                parent[neighbour]=num;
            }
        }
    }
    return {-1,{}};
}

int main()
{
    string a="123", b="345";
    auto p = solve(a,b);
    if(p.first!=-1) {
        cout<<"Cnt of minimum operations: "<<p.first<<endl;
        cout<<"Path: ";
        auto v=p.second;
        reverse(v.begin(), v.end());
        for(auto k : v)
          cout<<k<<"->";
    }

    return 0;
}
/*
Digit Transformation Problem – Given a start and end number, return the minimum operations 
and path to convert start to end. You can only:
Double a digit (≤ 9)
Increment a digit (≤ 9)
Decrement a digit (> 0)

*/
/*
🔢 Digit Transformation Problem
Problem Statement:
You are given two non-negative integers, start and end. Your goal is to transform start into end using 
the minimum number of operations. At each step, you may perform the following operations on any digit 
(individually) in the current number:

Double a digit (only if the result is ≤ 9)

e.g., 3 → 6, 4 → 8, but not 5 → 10

Increment a digit (only if the result is ≤ 9)

e.g., 2 → 3, 9 cannot be incremented

Decrement a digit (only if the result is > 0)

e.g., 5 → 4, 0 cannot be decremented

You can apply these operations to any digit at any position in the number. The length of the 
number must remain the same throughout the transformation (i.e., no adding/removing digits).

Constraints:
start and end are integers with the same number of digits

All digits are in the range 0 to 9

Leading zeros are allowed and must be preserved

Operations must transform one digit at a time

Output:
Return:

The minimum number of operations to transform start to end

The path of transformations (each as a string or integer)

Example 1:
Input:
start = 123
end = 345

Output:
Minimum operations: 5
Path: 123 → 223 → 323 → 343 → 344 → 345


Example 2:
Input:
start = 009
end = 000

Output:
Minimum operations: 1  
Path: 009 → 000


*/
