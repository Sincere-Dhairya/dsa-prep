/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 */

// @lc code=start
class Solution {
public:
    void create_subset(vector<vector<int>>& arr, int start, vector<int> nums, vector<int> smallset){
        for(int i = start+1; i<nums.size(); i++){
            smallset.push_back(nums[i]);
            arr.push_back(smallset);
            create_subset(arr, i, nums, smallset);
            smallset.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>sbstarr;
        sbstarr.push_back({});

        for(int i = 0; i<nums.size(); i++){
            vector<int> smallset;
            smallset.push_back(nums[i]);
            sbstarr.push_back(smallset);
            create_subset(sbstarr, i, nums, smallset);
        }
        return sbstarr;
    }
};
// @lc code=end

