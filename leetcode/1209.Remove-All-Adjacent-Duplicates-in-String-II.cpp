/**
 * @file 1209.Remove-All-Adjacent-Duplicates-in-String-II.cpp
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2021-12-06
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*
You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

We repeatedly make k duplicate removals on s until we no longer can.

Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.

 

Example 1:

Input: s = "abcd", k = 2
Output: "abcd"
Explanation: There's nothing to delete.
Example 2:

Input: s = "deeedbbcccbdaa", k = 3
Output: "aa"
Explanation: 
First delete "eee" and "ccc", get "ddbbbdaa"
Then delete "bbb", get "dddaa"
Finally delete "ddd", get "aa"
Example 3:

Input: s = "pbbcggttciiippooaais", k = 2
Output: "ps"
 

Constraints:

1 <= s.length <= 105
2 <= k <= 104
s only contains lower case English letters.
*/
class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<int, char>> stack = {{0, '-'}};
        for(int i = 0; i<s.size(); i++){
            if(s[i] != stack.back().second)
                stack.push_back({1,s[i]});
            else if(++stack.back().first == k)
                stack.pop_back();
        }
        string ans = "";
        for(auto i: stack)
            ans.append(i.first, i.second);
        return ans;
    }
};