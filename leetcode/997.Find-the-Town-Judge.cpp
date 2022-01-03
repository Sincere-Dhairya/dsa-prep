/**
 * @file 997. Find the Town Judge
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-03
 * @link https://leetcode.com/problems/find-the-town-judge/
 * @copyright Copyright (c) 2022
 * 
 */
/*
In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.

If the town judge exists, then:

The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.

Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

 

Example 1:

Input: n = 2, trust = [[1,2]]
Output: 2
Example 2:

Input: n = 3, trust = [[1,3],[2,3]]
Output: 3
Example 3:

Input: n = 3, trust = [[1,3],[2,3],[3,1]]
Output: -1
 

Constraints:

1 <= n <= 1000
0 <= trust.length <= 10^4
trust[i].length == 2
All the pairs of trust are unique.
ai != bi
1 <= ai, bi <= n
*/
/* Test Cases
2
[[1,2]]
3
[[1,3],[2,3]]
5
[[1,3],[2,3]]
3
[[1,3],[2,3],[3,1]]
4
[[1,3],[1,2],[1,4],[3,2],[3,4],[4,1],[4,2],[4,3]]
3
[[1,2],[2,3]]
*/

//O(N^2) approach using DFS for graphs
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, vector<int>> graph;
        int judge = 0;
        for(auto i: trust){
            graph[i[0]].push_back(i[1]);
        }
        bool found = 0;
        for(int i = 1; i<=n; i++){
            if(graph.count(i) == 0){
                if(found){
                    judge = -1;
                    break;
                }
                judge = i, found = 1;
            }
        }
        if(judge == -1)
            return -1;
        for(auto i: graph){
            found = 0;
            for(int b : i.second){
                if(b == judge){
                    found = 1;
                    break;
                }
            }
            if(!found){
                judge = -1;
                break;
            }
        }
        if(judge){
            return judge;
        }
        else return -1;
    }
};

//Optimized solution O(N) TC: O(N)
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> belief(n+1, 0);
        for(auto i: trust){
            --belief[i[0]],
            ++belief[i[1]];
        }
        int total_trust = n-1, judge = -1;
        for(int i = 1; i<=n; i++){
            if(belief[i] == total_trust){
                judge = i;
                break;
            }
        }
        return judge;
    }
};