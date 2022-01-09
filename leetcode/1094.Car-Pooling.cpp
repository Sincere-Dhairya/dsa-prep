/**
 * @file 1094. Car Pooling
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-06
 * @link https://leetcode.com/problems/car-pooling/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
There is a car with capacity empty seats. The vehicle only drives east (i.e., it cannot turn around and drive west).

You are given the integer capacity and an array trips where trip[i] = [numPassengersi, fromi, toi] indicates that the ith trip has numPassengersi passengers and the locations to pick them up and drop them off are fromi and toi respectively. The locations are given as the number of kilometers due east from the car's initial location.

Return true if it is possible to pick up and drop off all passengers for all the given trips, or false otherwise.

 

Example 1:

Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false
Example 2:

Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true
 

Constraints:

1 <= trips.length <= 1000
trips[i].length == 3
1 <= numPassengersi <= 100
0 <= fromi < toi <= 1000
1 <= capacity <= 10^5
*/

//Naive approach TC - O(N^2 LogN)
class Solution {
public:
    struct Compare{
        bool operator()(pair<int, int>& a, pair<int, int>& b){
            return (a.first > b.first)?1: (a.first == b.first and a.second >= b.second)? 1:0;
        }
    };
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), [](auto &a, auto &b){ return a[1]<b[1]?1:(a[1] == b[1] and a[2]<b[2])? 1: (a[1] == b[1] and a[2] == b[2] and a[0]<=b[0])? 1: 0; });
        for(auto i: trips){
            cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
        }
        int passengers = 0, i = 0, d = 0, n = trips.end()-trips.begin();
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        while(i < n){
            while(pq.size() and pq.top().first == d){
                passengers -= pq.top().second;
                pq.pop();
            }
            while(i < n and trips[i][1] == d){
                passengers += trips[i][0];
                pq.push({trips[i][2], trips[i][0]});
                ++i;
            }
            if(passengers > capacity){
                return false;
            }
            ++d;
        }
        return true;
    }
};

//Optimized approach O(N) SC - 1
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> points(1001, 0);
        for(auto i: trips){
            points[i[1]] += i[0],
            points[i[2]] -= i[0];
        }
        int passengers = 0;
        bool flag = 1;
        for(auto i: points){
            passengers += i;
            if(passengers > capacity){
                flag = 0;
                break;
            }
        }
        return flag;
    }
};
/*
[[3,3,7],[1,1,5],[1,1,2],[2,1,5],[3,5,6]]
6
*/