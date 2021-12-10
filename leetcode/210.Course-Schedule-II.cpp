/**
 * @file 210.Course-Schedule-II.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-10
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*
There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: [0,1]
Explanation: There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1].
Example 2:

Input: numCourses = 4, prerequisites = [[1,0],[2,0],[3,1],[3,2]]
Output: [0,2,1,3]
Explanation: There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0.
So one correct course order is [0,1,2,3]. Another correct ordering is [0,2,1,3].
Example 3:

Input: numCourses = 1, prerequisites = []
Output: [0]
 

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= numCourses * (numCourses - 1)
prerequisites[i].length == 2
0 <= ai, bi < numCourses
ai != bi
All the pairs [ai, bi] are distinct.
*/
//BFS TC: O(V+E) SC: O(V+E)
class Solution {
    typedef unordered_map<int, vector<int>> Graph;
    Graph make_graph(int n, vector<vector<int>> prerequisites, vector<int>&indegrees){
        Graph g;
        for(auto i: prerequisites){
            g[i[1]].push_back(i[0]);
            ++indegrees[i[0]];
        }
        return g;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 0){
            vector<int> ans;
            for(int i = 0; i<numCourses; i++)
                ans.push_back(i);
            return ans;
        }
        vector<int> indegrees(numCourses, 0);
        Graph g = make_graph(numCourses, prerequisites, indegrees);
        vector<int> ans;
        queue<int> q;
        bool flag = false;
        for(int i = 0; i<numCourses; i++)
            if((!indegrees[i]) and g.count(i))
                q.push(i), flag = true;
        if(!flag)
            return ans;
        while(q.size()){
            int node = q.front();
            q.pop(), ans.push_back(node);
            for(auto adj : g[node]){
                if(--indegrees[adj] == 0)
                    q.push(adj);
            }
        }
        for(int i : indegrees)
            if(i)
                return {};
        for(int i = 0; i<numCourses; i++)
            if(g.count(i) == 0)
                ans.push_back(i);
        return ans;
    }
};

//DFS O(V+E)
class Solution {
    typedef unordered_map<int, vector<int>> Graph;
    Graph make_graph(int n, vector<vector<int>> prerequisites, vector<int>&indegrees){
        Graph g;
        for(auto i: prerequisites){
            g[i[1]].push_back(i[0]);
            ++indegrees[i[0]];
        }
        return g;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 0){
            vector<int> ans;
            for(int i = 0; i<numCourses; i++)
                ans.push_back(i);
            return ans;
        }
        vector<int> indegrees(numCourses, 0);
        Graph g = make_graph(numCourses, prerequisites, indegrees);
        vector<int> ans;
        
        for(int i= 0;i<numCourses; i++){
            int j = 0;
            for(j=j; j<numCourses; j++)
                if(!indegrees[j])
                    break;
            if(j == numCourses)
                return {};
            ans.push_back(j), --indegrees[j];
            for(auto adj:g[j])
                --indegrees[adj];
        }
        return ans;
    }
};