/**
 * @file 189. Rotate Array
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-30
 * @link https://leetcode.com/problems/rotate-array/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Given an array, rotate the array to the right by k steps, where k is non-negative.

 

Example 1:

Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]
Example 2:

Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]
 

Constraints:

1 <= nums.length <= 105
-231 <= nums[i] <= 231 - 1
0 <= k <= 105
 

Follow up:

Try to come up with as many solutions as you can. There are at least three different ways to solve this problem.
Could you do it in-place with O(1) extra space?
*/
/*Test Cases:
[1,2,3,4,5,6,7]
3
[477181,661861,837383,492412,935349,84343,723642,678340,123214,484282,473991,823195,247179,206529,724472,412154,590105,808986,800645,235405,952307,620444,491813,406073,973100,847153,143198,395544,616975,219674,735709,19659,240163,642316,121616,845895,919656,535031,535159,897657,48036,585753,566416,667007,970911,310419,258013,887399,567257,961026,111997,265452,462298,572804,201605,560897,770141,866103,162344,359167,614160,658059,326275,805308,794579,719789,583649,485891,989631,549951,517823,955342,246748,973149,438154,762754,75742,671191,750264,866855,556036,358442,815399,580831,803092,130761,868664,701546,344771,840137,861171,914529,738805,595480,896469,237253,634451,738557,667220,492495,22486,209170,552646,260546,999905,267414,152955,153968,468870,98812,492105,601338,457869,963092,616337,789339,775355,378087,573144,675684,415724,817653,476612,784651,605854,678208,100151,151761,73885,799996,356011,142916,579028,567643,911773,225420,158913,383726,566779,665976,100573,550746,296682,70839]
54944

*/

//Using Queue -> O(N) time and O(N) Space.
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        queue<int> q;
        int n = nums.end()-nums.begin();
        for(int i = n-1; i>=0; i--){
            q.push(nums[i]);
        }
        while(k--){
            q.push(q.front());
            q.pop();
        }
        int i = n-1;
        while(q.size()){
            nums[i--] = q.front();
            q.pop();
        }
    }
};

//Gave TLE
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.end()-nums.begin();
        while(k--){
            int num=nums.back();
            nums.erase(nums.begin()+(n-1));
            auto it = nums.emplace(nums.begin(), num);
        }
    }
};

// Time (O(n+2k)) Space O(k).
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.end()-nums.begin(), i=n-1, k1 = k;
        k %= n, k1 = k;
        stack<int>s;
        while(k1--){
            s.push(nums[i--]);
        }
        for(int i = n-k-1; i>=0; i--){
            nums[i+k] = nums[i];
        }
        i = 0;
        while(s.size()){
            nums[i++] = s.top();
            s.pop();
        }
    }
};

//OP Approach
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.end()-nums.begin(),i,j;
        k %= n;
        i=0, j=k-1;
        reverse(nums.begin(), nums.end());
        while(i<j){
            swap(nums[i], nums[j]),
            ++i, --j;
        }
        i = k, j = n-1;
        while(i<j){
            swap(nums[i], nums[j]),
            ++i, --j;
        }
    }
};