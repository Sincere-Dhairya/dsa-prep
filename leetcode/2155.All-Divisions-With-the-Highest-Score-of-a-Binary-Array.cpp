/**
 * @file 2155. All Divisions With the Highest Score of a Binary Array
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-30
 * @link https://leetcode.com/contest/weekly-contest-278/problems/all-divisions-with-the-highest-score-of-a-binary-array/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given a 0-indexed binary array nums of length n. nums can be divided at index i (where 0 <= i <= n) into two arrays (possibly empty) numsleft and numsright:

numsleft has all the elements of nums between index 0 and i - 1 (inclusive), while numsright has all the elements of nums between index i and n - 1 (inclusive).
If i == 0, numsleft is empty, while numsright has all the elements of nums.
If i == n, numsleft has all the elements of nums, while numsright is empty.
The division score of an index i is the sum of the number of 0's in numsleft and the number of 1's in numsright.

Return all distinct indices that have the highest possible division score. You may return the answer in any order.

 

Example 1:

Input: nums = [0,0,1,0]
Output: [2,4]
Explanation: Division at index
- 0: numsleft is []. numsright is [0,0,1,0]. The score is 0 + 1 = 1.
- 1: numsleft is [0]. numsright is [0,1,0]. The score is 1 + 1 = 2.
- 2: numsleft is [0,0]. numsright is [1,0]. The score is 2 + 1 = 3.
- 3: numsleft is [0,0,1]. numsright is [0]. The score is 2 + 0 = 2.
- 4: numsleft is [0,0,1,0]. numsright is []. The score is 3 + 0 = 3.
Indices 2 and 4 both have the highest possible division score 3.
Note the answer [4,2] would also be accepted.
Example 2:

Input: nums = [0,0,0]
Output: [3]
Explanation: Division at index
- 0: numsleft is []. numsright is [0,0,0]. The score is 0 + 0 = 0.
- 1: numsleft is [0]. numsright is [0,0]. The score is 1 + 0 = 1.
- 2: numsleft is [0,0]. numsright is [0]. The score is 2 + 0 = 2.
- 3: numsleft is [0,0,0]. numsright is []. The score is 3 + 0 = 3.
Only index 3 has the highest possible division score 3.
Example 3:

Input: nums = [1,1]
Output: [0]
Explanation: Division at index
- 0: numsleft is []. numsright is [1,1]. The score is 0 + 2 = 2.
- 1: numsleft is [1]. numsright is [1]. The score is 0 + 1 = 1.
- 2: numsleft is [1,1]. numsright is []. The score is 0 + 0 = 0.
Only index 0 has the highest possible division score 2.
 

Constraints:

n == nums.length
1 <= n <= 105
nums[i] is either 0 or 1.
*/

//O(NlogN) Approach
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>> indexpair;
        int zeroes = 0, ones = accumulate(nums.begin(), nums.end(), 0), n = nums.end()-nums.begin();
        for(int i = 0; i<= n; i++){
            if(i){
                if(nums[i-1] == 0){
                    ++zeroes;
                }
                else{
                    --ones;
                }
            }
            indexpair.push({ones+zeroes, i});
        }
        int sum = indexpair.top().first, ind = indexpair.top().second;
        vector<int> indices;
        while(indexpair.size() and indexpair.top().first == sum){
            indices.push_back(indexpair.top().second);
            indexpair.pop();
        }
        return indices;
    }
};

//O(N) Prefix Sum
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.end()-nums.begin(), l=1, r=n-1;
        vector<int> left(n+1,0), right(n+1,0);
        
        for(int i=0, j=n-1; i<n && j>=0; i++,j--){
            if(nums[i]==0){
                left[i+1] = 1;
            }
            left[i+1] += left[i];
            
            if(nums[j]){
                right[j] = 1;
            }
            right[j] += right[j+1];
        }
        
        vector<int> indices = {0};
        int sum = 0;
        for(int i= 0;i<=n; i++){
            int total = left[i]+right[i];
            if(sum < total){
                indices.clear();
                indices.push_back(i);
                sum = total;
            }
            else if(sum == total){
                indices.push_back(i);
            }
        }
        return indices;
    }
};

