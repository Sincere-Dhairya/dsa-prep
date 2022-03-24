/**
 * @file 881. Boats to Save People
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-03-24
 * @link https://leetcode.com/problems/boats-to-save-people/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.

 

Example 1:

Input: people = [1,2], limit = 3
Output: 1
Explanation: 1 boat (1, 2)
Example 2:

Input: people = [3,2,2,1], limit = 3
Output: 3
Explanation: 3 boats (1, 2), (2) and (3)
Example 3:

Input: people = [3,5,3,4], limit = 5
Output: 4
Explanation: 4 boats (3), (3), (4), (5)
 

Constraints:

1 <= people.length <= 5 * 10^4
1 <= people[i] <= limit <= 3 * 10^4
*/

// TC: O(NlogN)
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end()); // nlogn 
        int n = people.size(), i = 0, j = n-1, count=0;
        while(i<j){ 
            while(i<j and limit==people[j]){ // n
                ++count, --j;
            }
            while(i<j and limit == people[j]){  // m
                ++count, ++i;
            }
            if(people[i]+people[j]<=limit){
                ++i;
            }
            ++count, --j;
        }
        if(i==j){
            ++count;
        }
        return count;
    }
};

/* test cases
[1,3,5,2,2,2,1,7,4,3,8,5,2,1,1,1,4,4,4,7]
20
[2]
2
[1]
2
[1,3,5,2,2,2,1,7,4,3,8,5,2,1,1,1,4,4,4,7]
8
[1,2]
3
[3,2,2,1]
3
[3,5,3,4]
5
*/