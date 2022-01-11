/**
 * @file 207.Course-Schedule.cpp
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
Return true if you can finish all courses. Otherwise, return false.

 

Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.
Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 

Constraints:

1 <= numCourses <= 105
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.
*/

//BFS Approach : O(V+E) TC. O(V+E) SC
class Solution {
    typedef unordered_map < int, vector < int > > Graph;
    Graph make_graph(int n, vector<vector<int>> prerequisites, vector<int> &indegrees){
        Graph graph;
        for(auto i : prerequisites){
            graph[i[1]].push_back(i[0]);
            ++indegrees[i[0]];
        }
        return graph;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 0) return true;
        vector<int> indegrees(numCourses, 0);
        Graph g = make_graph(numCourses, prerequisites, indegrees);
        queue<int> q;
        bool flag = false;
        for(int i = 0; i<numCourses; i++){      //o(n)
            if((!indegrees[i]) and g.count(i))
                q.push(i), flag = true;
        }
        if(flag == false)
            return flag;
        while(q.size()){        //o(v+e)
            auto pre = q.front();
            q.pop();
            for(auto adj : g[pre]){
                if(--indegrees[adj] == 0)
                    q.push(adj);
            }
        }
        for(int i = 0; i<numCourses; i++)
            if(indegrees[i]){
                flag = false;
                break;
            }
        return flag;
    }
};
/*
8
[[2,1],[4,1],[7,1],[3,2],[5,4],[6,7],[6,4],[5,6]]
*/

//DFS
class Solution {
    typedef unordered_map < int, vector < int > > Graph;
    Graph make_graph(int n, vector<vector<int>> prerequisites, vector<int> &indegrees){
        Graph graph;
        for(auto i : prerequisites){
            graph[i[1]].push_back(i[0]);
            ++indegrees[i[0]];
        }
        return graph;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegrees(numCourses, 0);
        Graph g = make_graph(numCourses, prerequisites, indegrees);
        int count = 0;
        for(int i = 0; i<numCourses; i++){
            int j = 0;
            for(; j<numCourses; j++)
                if(!indegrees[j])
                    break;
            if(j == numCourses)
                return false;
            --indegrees[j];
            for(int adj : g[j])
                --indegrees[adj];
        }
        return true;
    }
};

//When tries using 2D vectors, the result were faster.
class Solution {
public:
    bool topo_sort(vector<vector<int> > &graph, vector<int>& indegrees, int n){
        queue<int> q;
        for(int i = 0; i<n; i++){
            if(!indegrees[i]){
                q.push(i);
            }
        }
        
        while(q.size()){
            int node = q.front();
            q.pop();
            for(auto adj : graph[node]){
                if(--indegrees[adj] == 0){
                    q.push(adj);
                }
            }
        }
        
        for(auto i: indegrees){
            if(i){
                return false;
            }
        }
        return true;
    }
    bool canFinish(int n, vector<vector<int>>& P) {
        vector<vector<int> > graph(n);
        vector<int> indegrees(n, 0);
        for(int i =0; i<P.size(); i++){
            graph[P[i][1]].push_back(P[i][0]);
            ++indegrees[P[i][0]];
        }
        return topo_sort(graph, indegrees, n);
    }
};