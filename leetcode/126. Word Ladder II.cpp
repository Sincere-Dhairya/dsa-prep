/**
 * @file 126. Word Ladder II
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-08-15
 * @link https://leetcode.com/problems/word-ladder-ii/ @endlink
 * @copyright Copyright (c) 2022
 * @tags dfs bfs graphs 
 */
/*
A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
Explanation: There are 2 shortest transformation sequences:
"hit" -> "hot" -> "dot" -> "dog" -> "cog"
"hit" -> "hot" -> "lot" -> "log" -> "cog"
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: []
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 5
endWord.length == beginWord.length
1 <= wordList.length <= 500
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
*/

// TC: O(NxN).
class Solution {
public:
    // O(N)
    inline bool diffByOneChar(string& a, string& b){
        int count =0;
        for(int i=0; i<a.size(); ++i){
            if(a[i] != b[i]) ++count;
        }
        return count == 1;
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return {}; // O(N)
        
        wordList.insert(wordList.begin(), beginWord); // O(N)
        for(int i=1; i<wordList.size(); ++i){ // O(N)
            if(wordList[i] == beginWord){
                wordList[i] = wordList.back();
                wordList.pop_back();
                break;
            }
        }
        
        unordered_map<string, int> indices;
        for(int i=0; i<wordList.size(); ++i){ // O(N)
            indices[wordList[i]] = i;
        }
        
        vector<vector<int>> adjList(wordList.size());
        for(int i=0; i<wordList.size(); ++i){ // O(NxN)
            for(int j=0; j<wordList.size(); ++j){
                if(i==j) continue;
                if(diffByOneChar(wordList[i], wordList[j])){
                    adjList[i].emplace_back(j);
                }
            }
        }
        
        queue<int> q;
        q.push(indices[beginWord]);
        int level = 1, minDepth = 1e8;
        
        vector<int> visited(wordList.size(), 1e8);
        visited[indices[beginWord]] = 0;

        while(q.size()){ // O(N)
            int n = q.size();
            for(int i=0; i<n; ++i){
                int curr = q.front();
                q.pop();
                for(int child: adjList[curr]){
                    if(visited[child] > level){
                        visited[child] = level;
                        if(wordList[child] == endWord){
                            minDepth = min(minDepth, level);
                        }
                        q.push(child);
                    }
                }
            }
            ++level;
        }
        
        level = minDepth;
        queue<vector<string>> q2;
        q2.push({endWord});
        while(level){ // O(NxN)
            int n = q2.size();
            for(int i=0; i<n; ++i){
                vector<string> path = q2.front();
                q2.pop();
                string back = path.back();
                int curr = indices[back];
                for(int child: adjList[curr]){
                    if(visited[child] == level-1){
                        path.emplace_back(wordList[child]);
                        q2.push(path);
                        path.pop_back();
                    }
                }
            }
            --level;
        }
        
        vector<vector<string>> ans;
        while(q2.size()){ // O(NxN)
            vector<string> s = q2.front();
            reverse(s.begin(), s.end());
            ans.emplace_back(s);
            q2.pop();
        }
        
        return ans;
    }
};