/**
 * @file 846. Hand of Straights
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-08-20
 * @link https://leetcode.com/problems/hand-of-straights/ @endlink
 * @copyright Copyright (c) 2022
 * @tags maps sorting greedy
 */
/*Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

 

Example 1:

Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
Output: true
Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
Example 2:

Input: hand = [1,2,3,4,5], groupSize = 4
Output: false
Explanation: Alice's hand can not be rearranged into groups of 4.

 

Constraints:

1 <= hand.length <= 10^4
0 <= hand[i] <= 10^9
1 <= groupSize <= hand.length
*/  
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int, int> available;
        sort(hand.begin(), hand.end());
        
        for(int& i: hand){
            ++available[i];
        }
        
        for(int i = 0; i<hand.size(); ++i){
            if(!available[hand[i]])
                continue;
            if(available[hand[i]] < 0) return 0;
            bool flag = 0;
            for(int j = 1; j<groupSize; ++j){
                available[hand[i]+j] -= available[hand[i]];
                if( available[hand[i]+j]<0){
                    return 0;
                }
            }
            available[hand[i]] = 0;
        }
        return 1;
    }
};  