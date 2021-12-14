/**
 * @file 2106. Maximum Fruits Harvested After at Most K Steps
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-14
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*
Fruits are available at some positions on an infinite x-axis. You are given a 2D integer array fruits where fruits[i] = [positioni, amounti] depicts amounti fruits at the position positioni. fruits is already sorted by positioni in ascending order, and each positioni is unique.

You are also given an integer startPos and an integer k. Initially, you are at the position startPos. From any position, you can either walk to the left or right. It takes one step to move one unit on the x-axis, and you can walk at most k steps in total. For every position you reach, you harvest all the fruits at that position, and the fruits will disappear from that position.

Return the maximum total number of fruits you can harvest.

 

Example 1:


Input: fruits = [[2,8],[6,3],[8,6]], startPos = 5, k = 4
Output: 9
Explanation: 
The optimal way is to:
- Move right to position 6 and harvest 3 fruits
- Move right to position 8 and harvest 6 fruits
You moved 3 steps and harvested 3 + 6 = 9 fruits in total.
Example 2:


Input: fruits = [[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]], startPos = 5, k = 4
Output: 14
Explanation: 
You can move at most k = 4 steps, so you cannot reach position 0 nor 10.
The optimal way is to:
- Harvest the 7 fruits at the starting position 5
- Move left to position 4 and harvest 1 fruit
- Move right to position 6 and harvest 2 fruits
- Move right to position 7 and harvest 4 fruits
You moved 1 + 3 = 4 steps and harvested 7 + 1 + 2 + 4 = 14 fruits in total.
Example 3:


Input: fruits = [[0,3],[6,4],[8,5]], startPos = 3, k = 2
Output: 0
Explanation:
You can move at most k = 2 steps and cannot reach any position with fruits.
 

Constraints:

1 <= fruits.length <= 105
fruits[i].length == 2
0 <= startPos, positioni <= 2 * 105
positioni-1 < positioni for any i > 0 (0-indexed)
1 <= amounti <= 104
0 <= k <= 2 * 105
*/

// Recursive Approach gave TLE because of TC= 2^N. SC = 2^N.
class Solution {
public:
    int harvester(vector<vector<int>> fruits, int start, int k, int n){
        //cout<<"entering "<<start<<" "<<k<<endl;
        if(k < 0) return 0;
        if(start < 0 or start >= n)
            return 0;
        int sum = fruits[start][1], sum1 = 0, sum2= 0;
        fruits[start][1] = 0;
        if(start-1 >= 0)
            sum1 = harvester(fruits, start-1, k-(fruits[start][0]-fruits[start-1][0]), n);
        if(start+1 < n)
            sum2 = harvester(fruits, start +1, k-(fruits[start+1][0]-fruits[start][0]), n);
        sum += max(sum1, sum2);
        //cout<<"k: "<<k<<" start: "<<start<<" sum: "<<sum<<endl;
        return sum; 
    }
    int maxTotalFruits(vector<vector<int>> fruits, int startPos, int k) {
        vector<int> locs;
        for(auto i : fruits)
            locs.push_back(i[0]);
        int ind = lower_bound(locs.begin(), locs.end(), startPos) - locs.begin(), sum = 0, n = fruits.size();
        //cout<<ind<<" "<<sum<<" "<<n<<endl;
        sum = max(harvester(fruits, ind, k-(fruits[ind][0]-startPos), n), harvester(fruits, ind-1, k-(startPos-fruits[ind-1][0]), n));
        return sum;
    }
};