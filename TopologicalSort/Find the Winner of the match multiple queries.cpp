/**
 * @file Find the winner of the match | Multiple Queries
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-16
 * @link https://www.geeksforgeeks.org/find-the-winner-of-the-match-multiple-queries/ @endlink
 * @copyright Copyright (c) 2022
 * @tags topological-sort
 */
/*
Given an array of pairs arr of size N which represents a game situation where the first player wins against the second player. Given multiple queries, each query contains two numbers, the task is to determine which one of them will win if they compete with each other.
NOTE: 
 

If A wins over B and B wins over C, then A will always win over C.
If A wins over B and A wins over C, if there is a match against B and C and if we couldn’t determine the winner then the player with smaller number wins
Examples: 
 

Input : arr[] = {{0, 1}, {0, 2}, {0, 3}, {1, 5}, {2, 5}, {3, 4}, {4, 5}, {6, 0}} 
query[] = {{3, 5}, {1, 2}} 
Output : 3
1 
Explanation : 3 wins over 4 and 4 wins over 5. So, 3 is the winner in the first match. 
We can’t determine the winner between 1 and 2. So, the player with a smaller number is the winner i.e., 1
Input : arr[] = {{0, 1}, {0, 2}, {0, 3}, {1, 5}, {2, 5}, {3, 4}, {4, 5}, {6, 0}} 
query[] = {{0, 5}, {0, 6}} 
Output : 0
6
*/

// TC: O(N), SC: O(E + 2N). E is maxNumber of child elements the Queue during the overall execution of the program.

#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<int> findWinners(vector<vector<int>>& winningSequence, int& N, vector<vector<int>>& Queries){
    vector<int> topSorted;

    vector<vector<int>> graph(N+1);
    vector<int> indegrees(N+1);

    for(int i=0; i<winningSequence.size(); ++i){
        graph[winningSequence[i][0]].emplace_back(winningSequence[i][1]);
        ++indegrees[winningSequence[i][1]];
    }

    priority_queue<int, vector<int>, greater<int>> ordered_queue;

    for(int i=1; i<=N; ++i){
        if(!indegrees[i]) ordered_queue.push(i);
    }

    while(ordered_queue.size()){
        int current_node = ordered_queue.top();
        ordered_queue.pop();

        for(int child: graph[current_node]){
            if(--indegrees[child] == 0){
                ordered_queue.push(child);
            }
        }

        topSorted.emplace_back(current_node);
    }

    vector<int> res(Queries.size());
    for(int i = 0; i<Queries.size(); ++i){
        int winner = 0;
        for(int j : topSorted){
            if( j == Queries[i][0]){
                winner = Queries[i][0];
                break;
            }
            else if(j == Queries[i][1]){
                winner = Queries[i][1];
                break;
            }
        }
        res[i] = winner;
    }

    return res;
}
int main(){
    vector<vector<int>> winningSequence = {
        {0, 1}, {0, 2}, {0, 3}, {1, 5}, {2, 5}, {3, 4}, {4, 5}, {6, 0}
    },
    Queries = {
        {0,5}, {0,6}
    };

    int N = 6;

    vector<int> res = findWinners(winningSequence, N, Queries);

    for(int i: res) cout<< i << " ";

    return 0;
}