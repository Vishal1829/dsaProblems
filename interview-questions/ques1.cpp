#include <vector>
#include <algorithm>

using namespace std;

int getMinMovement(vector<char>& products) {
    vector<int> pos; // Stores positions of 'P's
    for (int i = 0; i < products.size(); ++i) {
        if (products[i] == 'P') {
            pos.push_back(i);
        }
    }
    int m = pos.size(); // Total number of 'P's
    if (m == 0) return 0; // No 'P's, no moves needed
    
    int max_in_window = 1; // At least one 'P' in any window
    int left = 0;
    for (int right = 0; right < m; ++right) {
        // Ensure the window [left..right] has 'P's that can be grouped
        while (pos[right] - pos[left] > m - 1) {
            left++; // Shrink the window from the left
        }
        // Update the maximum number of 'P's in a valid window
        max_in_window = max(max_in_window, right - left + 1);
    }
    // Minimum moves = total 'P's - maximum 'P's in a valid window
    return m - max_in_window;
}

/*
Question 1: Minimum movement
```
In Amazon's warehouse we ship multiple products at same time. 
These products are kept on a shelf and can look like this → P _ _ P _ P P P
For these products to be shipped we have a constraint - these products needs to be together i.e. there is no empty space between them.

Now, you can take any Product (P) and place it at any blank space (). This will cost you one movement. 
We want to find the minimum movement required to group these products together so that it can be shipped.

Input - 
P  _ P _ P P P

Output -
1


public int getMinMovement(char[] products) {
    
}

Solution Explanation:
0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21  22
P _ P _ P P P _ _ _ _  _  P  P  P  _  P  _  P  _  _   _  P
11-P
 0 1 2 3 4 5  6  7  8  9  10
{0,2,4,5,6,12,13,14,16,18,22}=post
window size=11
expand the window from left to right, so initialize right as 1, left as 0
also if we have m P's total = window size so it means distance between
first and last P must be <=m-1(0 based index)10

also this we are iterating on values of pos array
2-0<=10 (expand right++)(left=0, right=1)
4-0<=10 (left=0, right=2)
5-0<=10 (left=0, right=3)
6-0<=10 (left=0, right=4)
12-0<=10(false so shrink the window left++) (left=0, right=5)
12-2<=10(expand window right++) (left=1, right=5)
13-2<=10(false so shrink the window left++) (left=1, right=6)
13-4<=10(expand window right++) (left=2, right=6)
14-4<=10 (left=2, right=7)
16-4<=10(false so shrink the window left++) (left=2, right=8)
16-5<=10(false so shrink the window left++) (left=3, right=8)
16-6<=10(expand window right++) (left=4, right=8)
18-6<=10(false so shrink the window left++) (left=4, right=9)
18-12<=10(expand window right++) (left=5, right=9)
22-12<=10 (left=5, right=10)

also so between any pos[i] and pos[j] the number of P we can calculate
is i-j+1 becoz this signifies that the pos array we have it contains the
positions of P in original array now in this pos array if i have 2 index
i and j and also pos[i] means that at ith position in original array
i have a P and same goes for j also now the no. of elemnts in pos array
between i and j inclusive is i-j+1 and also since in our pos array all 
positions of array are ordered the way it is present in original array
and so if no. of elements b/w i to j is i-j+1 it means that in 
pos array we have this many elements b/w i and j and it mans we have this many P.

and we want the max no. of p's in a window of 11(m-1) and our answer 
which is minimum moves will be window size which is m - maxP's we got in 
this window size 11.


original testcase ex:
The Positions Array
First, let's look at the positions of all 'P's in the original array P _ P _ P P P:

Index 0: 'P'

Index 2: 'P'

Index 4: 'P'

Index 5: 'P'

Index 6: 'P'

So our positions array is [0, 2, 4, 5, 6]. This is crucial - it's an ordered list of where all the 'P's are located.

Understanding the Window [2, 4, 5, 6]
When we talk about the window [2, 4, 5, 6], we're looking at a subset of these positions. Here's how we know there are exactly 4 'P's in this window:

The window includes position 2: That's the 'P' at index 2

The window includes position 4: That's the 'P' at index 4

The window includes position 5: That's the 'P' at index 5

The window includes position 6: That's the 'P' at index 6

That's 4 distinct positions where 'P's are located, hence 4 'P's in this window.

Why Not Count Between 2 and 6 in Original Array?
This is where the confusion might come from. We're not counting 'P's between indices 2 and 6 in the original array. Instead, we're looking at the positions array [0, 2, 4, 5, 6] and selecting a continuous segment (window) from this array.

Visualizing the Window Selection
Let me show how we slide through the positions array:

Start with left pointer at 0, right pointer moving:

Window [0]: size 1

Window [0,2]: size 2

...

Window [0,2,4,5,6]: size 5 (distance 6-0=6 > 4 → invalid)

Move left pointer to 1:

Window [2]: size 1

Window [2,4]: size 2

Window [2,4,5]: size 3

Window [2,4,5,6]: size 4 (distance 6-2=4 ≤ 4 → valid)

This is our best window with 4 'P's

Key Points
We're working with the positions array [0,2,4,5,6], not the original shelf

A "window" is a continuous segment of this positions array

The size of the window (right-left+1) tells us how many 'P's are in it

We're not counting 'P's in the original array between two indices

Final Calculation
For window [2,4,5,6] in positions array:

Window size = 4 (positions 2,4,5,6)

Therefore, 4 'P's are in this window

Total 'P's = 5

Moves needed = 5 - 4 = 1

---------------------------------------------------------------------------------------------------------------------

Breakdown of Time Complexity
Collecting Positions of 'P's:

We iterate through the entire array once to record the indices of all 'P's.

This takes O(n) time.

Sliding Window on Positions Array:

Let m be the number of 'P's (length of the positions array).

The sliding window passes through the positions array once, with both left and right pointers moving from start to end.

Each position is processed exactly once (either included or excluded from the window).

This is O(m) time.

Overall Complexity:

Since m ≤ n, the total time is O(n) + O(m) = O(n).

Why Not O(n²)?
The sliding window doesn't use nested loops over all elements.

The while loop inside the for loop might seem like O(n²), but:

The left pointer only moves forward and never backward.

Each element is processed at most twice (once by the right pointer, once by the left).

This makes it O(2n) = O(n) (amortized constant time per element).

Edge Cases
No 'P's: Returns immediately (O(1)).

All 'P's: Window covers entire array (O(n)).

Space Complexity
O(m) for storing positions (worst case: all 'P's → O(n)).

Summary
Time: O(n) (linear in shelf size).

Space: O(m) (proportional to number of 'P's).

This is optimal since we must examine each element at least once to solve the problem.

*/