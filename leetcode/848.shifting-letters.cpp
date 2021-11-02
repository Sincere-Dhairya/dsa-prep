/*
 * @lc app=leetcode id=848 lang=cpp
 *
 * [848] Shifting Letters
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        vector<long> savesum(n, 0);
        
        long sum = 0;// = accumulate(shifts.begin(), shifts.end(), 0);
        //savesum[0] = sum;
        for(int i : shifts) sum += i;
        savesum[0] = sum;

        for(int i = 1; i<n; i++){
            sum -= shifts[i-1];
            //cout<<sum<<endl;
            savesum[i] = sum; 
        }

        for(int i = 0; i <n; i++){
            long mod = savesum[i]%26;
            long ans = s[i] + mod;
            if(ans>122) ans -= 26;
            //cout<<ans<<" "<<char(ans)<<endl;
            s[i] = char(ans);
        }
        return s;
    }
};
// @lc code=end
//"zzzzz"\n[200,200,200,200,2000]
//"mkgfzkkuxownxvfvxasy"\n[505870226,437526072,266740649,224336793,532917782,311122363,567754492,595798950,81520022,684110326,137742843,275267355,856903962,148291585,919054234,467541837,622939912,116899933,983296461,536563513]