/*
1217. Minimum Cost to Move Chips to The Same Position
We have n chips, where the position of the ith chip is position[i].

We need to move all the chips to the same position. In one step, we can change the position of the ith chip from position[i] to:

position[i] + 2 or position[i] - 2 with cost = 0.
position[i] + 1 or position[i] - 1 with cost = 1.
Return the minimum cost needed to move all the chips to the same position.

 

Example 1:


Input: position = [1,2,3]
Output: 1
Explanation: First step: Move the chip at position 3 to position 1 with cost = 0.
Second step: Move the chip at position 2 to position 1 with cost = 1.
Total cost is 1.
Example 2:


Input: position = [2,2,2,3,3]
Output: 2
Explanation: We can move the two chips at position  3 to position 2. Each move has cost = 1. The total cost = 2.
Example 3:

Input: position = [1,1000000000]
Output: 1
 

Constraints:

1 <= position.length <= 100
1 <= position[i] <= 10^9
*/

class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int nums[2] = {0, 0};
        for(int i : position)
            ++nums[i%2];
        return min(nums[0], nums[1]);
    }
};

/*
Explaination
We will first bring together all the coins at even position together at some even position
and all the coins at odd position at some odd position.
Such action will take 0 cost as jumping 2 steps at a time has 0 cost.
Then we will consider that the odds and evens are adjacent to each other and odd number and even number are always adjacent.
Then the lowest height of the two groups of coins is our answer.
so min(odds, evens)
*/