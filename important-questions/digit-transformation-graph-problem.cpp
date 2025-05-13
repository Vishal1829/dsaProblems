#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <string>
using namespace std;

vector<string> getNeighbors(const string& num) {
    vector<string> neighbors;
    for (int i = 0; i < num.size(); ++i) {
        string temp = num;
        int digit = temp[i] - '0';

        // Increment
        if (digit < 9) {
            temp[i] = (digit + 1) + '0';
            neighbors.push_back(temp);
        }

        // Decrement
        if (digit > 0) {
            temp[i] = (digit - 1) + '0';
            neighbors.push_back(temp);
        }

        // Double
        if (digit * 2 <= 9) {
            temp[i] = (digit * 2) + '0';
            neighbors.push_back(temp);
        }
    }
    return neighbors;
}

pair<int, vector<string>> digitTransform(string start, string end) {
    if (start == end)
        return {0, {start}};

    queue<pair<string, vector<string>>> q;
    unordered_set<string> visited;

    q.push({start, {start}});
    visited.insert(start);

    while (!q.empty()) {
        auto [curr, path] = q.front();
        q.pop();

        for (const string& neighbor : getNeighbors(curr)) {
            if (visited.count(neighbor)) continue;

            vector<string> newPath = path;
            newPath.push_back(neighbor);

            if (neighbor == end)
                return {newPath.size() - 1, newPath};

            q.push({neighbor, newPath});
            visited.insert(neighbor);
        }
    }

    return {-1, {}}; // No path found
}

int main() {
    string start = "123";
    string end = "345";

    auto [steps, path] = digitTransform(start, end);
    
    if (steps == -1) {
        cout << "No transformation path exists.\n";
    } else {
        cout << "Minimum operations: " << steps << "\nPath: ";
        for (const string& s : path) {
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}
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
