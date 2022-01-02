/**
 * @file 1010. Pairs of Songs With Total Durations Divisible by 60
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-02
 * @link https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/
 * @copyright Copyright (c) 2022
 * 
 */
/*
You are given a list of songs where the ith song has a duration of time[i] seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by 60. Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.

 

Example 1:

Input: time = [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60
Example 2:

Input: time = [60,60,60]
Output: 3
Explanation: All three pairs have a total duration of 120, which is divisible by 60.
 

Constraints:

1 <= time.length <= 6 * 104
1 <= time[i] <= 500
*/

//Naive approach O(N^2)
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.end()- time.begin(), count = 0;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++)
                if((time[i] + time[j])%60 == 0)
                    ++count;
        }
        return count;
    }
};


//Optimised solution of O(N)
/**we identify that if x is the given number which gives t = x%60 then, we would need a number 
 * y which gives u = y%60 such that t+u = 60.
 * We create a seperate array of size 60 that keeps count of numbers that give that index number
 * on % operation. at the same time, we keep on adding 1 to the arr[x%60] to symbolize that 
 * there is one more number that gives this remainder and suppose arr[x%60] = n, then we have 
 * n cases for a number that gives complement as the remainder and we have to consider all n cases
 * to calculate the answer. hence we add.
 * */
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> rems(60, 0);
        int count = 0;
        for(int t : time){
            count += rems[(600-t)%60],
            rems[(t)%60]  += 1;
        }
        return count;
    }
};