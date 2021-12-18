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

//O(N) approach with Prefix sum
class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int start, int k) {
        int msize = 200002, n = fruits.size();
        vector<int> harvest(msize, 0), leftpf(msize, 0), rightpf(msize, 0);
        
        for(auto i: fruits)
            harvest[i.front()] = i.back();
        
        leftpf[start] = rightpf[start] = harvest[start];
        
        //left prefix sum
        for(int i = start-1; i>=0; i--)
            leftpf[i] = leftpf[i+1] + harvest[i];//, cout<<leftpf[i]<<" ";
        
        //right prefix sum
        for(int i = start+1; i<msize; i++)
            rightpf[i] = rightpf[i-1] + harvest[i];//, cout<<rightpf[i]<<" ";
        int ans = harvest[start], leftlimit = min(k, start), rightlimit = min(k, msize - start-1);
        
        //left traversal
        for(int i = 1; i<= leftlimit; i++){
            int rsteps = k - 2*i;
            if(rsteps >= 0){
                rsteps = min( rsteps, msize-start);
                if(rsteps + start < msize)
                    ans = max(ans, leftpf[start-i] + rightpf[rsteps+start] - harvest[start]);
            }
            else
                ans = max(ans, leftpf[start-i]);
        }

        //right traversal
        for(int i = 1; i<= rightlimit; i++){
            int lsteps = k - 2*i;
            if(lsteps >= 0){
                lsteps = min(lsteps, start);
                ans = max(ans, rightpf[start+i] + leftpf[start-lsteps] - harvest[start]);
            }
            else
                ans = max(ans, rightpf[start+i]);
        }
        
        return ans;
    }
};
/*
[[0,15],[1,2],[2,7],[3,65],[4,14],[5,49],[6,5],[7,27],[8,71],[9,6],[10,62],[11,15],[12,24],[13,51],[14,22],[15,79],[17,98],[18,46],[19,91],[21,42],[22,31],[23,29],[24,95],[25,96],[27,94],[28,28],[30,62],[31,63],[32,94],[33,27],[34,60],[35,97],[36,1],[37,57],[39,8],[40,92],[41,86],[42,37],[43,48],[44,3],[45,70],[46,64],[47,9],[49,100],[50,33],[51,70],[52,18],[54,37],[55,100],[56,61],[57,33],[58,10],[59,27],[60,37],[61,77],[62,59],[64,30],[65,7],[66,57],[67,5],[68,57],[69,13],[70,15],[71,95],[72,19],[73,50],[74,33],[75,20],[76,72],[77,95],[78,9],[79,18],[80,85],[82,95],[84,85],[86,14],[87,26],[88,68],[91,61],[92,24],[93,32],[94,29],[95,77],[97,100],[99,59],[100,67]]
50
125

[[200000,10000]]
200000
200000

[[0,9],[4,1],[5,7],[6,2],[7,4],[10,9]]
10
40

[[200000,10000]]
0
0

[[0,10000]]
200000
200000
*/