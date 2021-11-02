/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool differbyone(string s1, string s2){
        if(s1.size() != s2.size()) return false;
        int count = 0;

        for(int i = 0; i<s1.size(); i++){
            if(s1[i] != s2[i]) ++count;
            if(count == 2) return false;
        }
        return true;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if(find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;
        map<string, vector<string>> graph;
        map<string, int> minheight;
        map<string, bool> status;
        int n = wordList.size();
        for(int i =0; i<n; i++){
            for(int j = 0; j<n; j++){
                if (i == j) continue;
                if(differbyone(wordList[i], wordList[j])) graph[wordList[i]].push_back(wordList[j]);
            }
            //minheight[wordList[i]] = 1;
            status[wordList[i]] = 0;
        }

        for(int i = 0; i<n; i++){
            if(differbyone(beginWord, wordList[i])) graph[beginWord].push_back(wordList[i]);
        }

        queue<string> q;
        q.push(beginWord);
        minheight[beginWord] = 1;
        string parent = beginWord;
        status[parent] = 1;
        //int n = 1;
        while(q.empty() == 0){
            //string child = q.front();
            int n = q.size();
            for(int j = 0; j<n; j++){
                string parent = q.front();
                q.pop();
                for(int i = 0; i<graph[parent].size(); i++){
                    string child = graph[parent][i];
                    if(status[child]){
                        minheight[child] = min(minheight[child], minheight[parent]+1);
                    }
                    else{
                        status[child] = 1;
                        minheight[child] = minheight[parent] + 1;
                        q.push(child);
                    }
                }
            }
        }
        return minheight[endWord];
    }
};

/*
"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]
"hit"\n"cog"\n["hot","dot","dog","lot","log"]

*/
// @lc code=end

