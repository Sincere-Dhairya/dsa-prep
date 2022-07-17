/**
 * @file Find alphabetical order such that words can be considered sorted
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-17
 * @link https://www.geeksforgeeks.org/find-alphabetical-order-such-that-words-can-be-considered-sorted/ @endlink
 * @copyright Copyright (c) 2022
 * @tags topological-sorting
 */
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

string orderedAlphabets(vector<string>& words){
    const int A = 26;
    vector<vector<int>> graph(A);
    vector<int> indegrees(A);

    for(int i= 0; i<words.size()-1; ++i){
        string prev = words[i], next = words[i+1];

        int j = 0;
        while(j < min(prev.length(), next.length())){
            if(prev[j] != next[j]){
                break;
            }
            ++j;
        }

        if(j < min(prev.length(), next.length())){
            graph[prev[j]-'a'].emplace_back(next[j]-'a');
            ++indegrees[next[j]-'a'];
            continue;
        }

        if(prev.length() > next.length()){
            return "";
        }
    }

    stack<int> s;
    for(int i =0; i<A; ++i){
        if(indegrees[i] == 0){
            s.push(i);
        }
    }

    string ans ="";
    vector<int> visited(A, 0);

    while(s.size()){
        int curr = s.top();
        s.pop();
        visited[curr] =1;
        for(int child: graph[curr]){
            if(visited[child]){
                continue;
            }

            if(--indegrees[child] == 0){
                s.push(child);
            }
        }

        ans.push_back(char(curr+'a'));
    }

    for(int i: visited){
        if(!i) return "";
    }

    return ans;
}

int main(){
    vector<string> words = { "efgh", "abcd" };//{"geeks", "gamers", "coders", "everyoneelse"};
    cout << orderedAlphabets( words) << endl;
    return 5;
}