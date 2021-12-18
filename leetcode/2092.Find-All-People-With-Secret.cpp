/**
 * @file 2092.Find-All-People-With-Secret.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-18
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/*
You are given an integer n indicating there are n people numbered from 0 to n - 1. You are also given a 0-indexed 2D integer array meetings where meetings[i] = [xi, yi, timei] indicates that person xi and person yi have a meeting at timei. A person may attend multiple meetings at the same time. Finally, you are given an integer firstPerson.

Person 0 has a secret and initially shares the secret with a person firstPerson at time 0. This secret is then shared every time a meeting takes place with a person that has the secret. More formally, for every meeting, if a person xi has the secret at timei, then they will share the secret with person yi, and vice versa.

The secrets are shared instantaneously. That is, a person may receive the secret and share it with people in other meetings within the same time frame.

Return a list of all the people that have the secret after all the meetings have taken place. You may return the answer in any order.

 

Example 1:

Input: n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], firstPerson = 1
Output: [0,1,2,3,5]
Explanation:
At time 0, person 0 shares the secret with person 1.
At time 5, person 1 shares the secret with person 2.
At time 8, person 2 shares the secret with person 3.
At time 10, person 1 shares the secret with person 5.​​​​
Thus, people 0, 1, 2, 3, and 5 know the secret after all the meetings.
Example 2:

Input: n = 4, meetings = [[3,1,3],[1,2,2],[0,3,3]], firstPerson = 3
Output: [0,1,3]
Explanation:
At time 0, person 0 shares the secret with person 3.
At time 2, neither person 1 nor person 2 know the secret.
At time 3, person 3 shares the secret with person 0 and person 1.
Thus, people 0, 1, and 3 know the secret after all the meetings.
Example 3:

Input: n = 5, meetings = [[3,4,2],[1,2,1],[2,3,1]], firstPerson = 1
Output: [0,1,2,3,4]
Explanation:
At time 0, person 0 shares the secret with person 1.
At time 1, person 1 shares the secret with person 2, and person 2 shares the secret with person 3.
Note that person 2 can share the secret at the same time as receiving it.
At time 2, person 3 shares the secret with person 4.
Thus, people 0, 1, 2, 3, and 4 know the secret after all the meetings.
Example 4:

Input: n = 6, meetings = [[0,2,1],[1,3,1],[4,5,1]], firstPerson = 1
Output: [0,1,2,3]
Explanation:
At time 0, person 0 shares the secret with person 1.
At time 1, person 0 shares the secret with person 2, and person 1 shares the secret with person 3.
Thus, people 0, 1, 2, and 3 know the secret after all the meetings.
 

Constraints:

2 <= n <= 105
1 <= meetings.length <= 105
meetings[i].length == 3
0 <= xi, yi <= n - 1
xi != yi
1 <= timei <= 105
1 <= firstPerson <= n - 1
*/

//O(nlogn) because of sorting. 

class Solution {
public:
    class Union{
        public:
        vector<int> parent;
        Union(int n){
            parent = vector<int> (n);
            for(int i =0; i<n; i++)
                parent[i] = i;
        }
        int association(int i){
            if(parent[i] == i) return i;
            else
                return parent[i] = association(parent[i]);
        }
        void connect(int i, int j){
            int pi = association(i), pj = association(j);
            if(pi == pj) return ;
            else if(pi > pj)
                parent[pi] = parent[i] = pj;
            else
                parent[pj] = parent[j] = pi;
        }
        bool validate(int i, int j){
            return association(i) == association(j);
        }
        void seperation(int i){ parent[i] = i; }
    };
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int first) {
        sort(meetings.begin(), meetings.end(), [](auto & a, auto & b){return a[2]<b[2];});
        for(auto i: meetings)
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        Union un(n);
        un.connect(0, first);
        vector<int> people;
        for(int i = 0, lim = meetings.size(); i<lim; ){
            int time = meetings[i][2];
            for(i = i; i<lim and meetings[i][2] == time; i++){
                un.connect(meetings[i][0], meetings[i][1]);
                people.push_back(meetings[i][0]), people.push_back(meetings[i][1]);
            }
            for(auto i : people)
                if(un.validate(0, i) == 0)
                    un.seperation(i);
            people = vector<int> ();
        }
        for(int i =0; i<n; i++)
            if(un.parent[i] == 0)
                people.push_back(i);
        return people;
    }
};