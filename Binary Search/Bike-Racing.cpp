/**
 * @file Bike-Racing
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-07-05
 * @link https://www.geeksforgeeks.org/bike-racing/ @endlink
 * @copyright Copyright (c) 2022
 * @tags binary search
 */
/*
A bike race is being organised with N bikers. The initial speed and the acceleration of the bikers are given in arrays H[] and A[] respectively. A biker whose speed is L or more is considered to be a fast biker. The total speed on the track for every hour is calculated by adding the speed of each fast biker in that hour. When the total speed on the track is M km/hour or more, the safety alarm turns on. The task is to find the minimum number of hours after which the safety alarm will turn on.

Examples:

Input: N = 3, M = 400, L = 120, H = {20, 50, 20}, A = {20, 70, 90}
Output: 3
Explanation: Speeds of all the Bikers after every hour starting from 0
Biker1 = [20  40  60  80 100] 
Biker2 = [50 120 190 260 330]
Biker3 = [20 110 200 290 380]
Initial Speed on track  = 0 
because none of the biker’s speed is fast enough.
Speed on track after 1st Hour= 120
Speed on track after 2nd Hour= 190+200=390
Speed on track after 3rd Hour= 260+290=550
The Alarm will start at 3rd Hour.

Input: N = 2, M = 60, L = 120, H = {50, 30}, A = {20, 40}
Output: 2
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

bool validTime(vector<int>& speeds, vector<int>& acc, int& M, int& midHour){
    int sumOfTime = 0;
    for(int i=0; i<speeds.size(); ++i){
        sumOfTime += (speeds[i] + acc[i]*midHour);
    }
    if(sumOfTime >= M) return 1;
    return 0;
}

int minHoursForSafetyAlarm(vector<int>& speeds, vector<int>& acc, int M, int L, int N){
    int maxHours = 0;
    for(int i = 0; i<N; ++i){
        int time = ceil((float)(L-speeds[i])/(float)(acc[i]));
        cout<<time<<endl;
        maxHours = max(maxHours, time);
    }
    int minHours = 0, minTime = INT_MAX;

    while(maxHours >= minHours){
        int midHour = (maxHours + minHours)/2;
        if(validTime(speeds, acc, M, midHour)){
            maxHours = midHour-1;
            minTime = min(minTime, midHour);
        }
        else{
            minHours = midHour +1;
        }
    }

    return minTime;
}

int main(){
    vector<int> speeds = {20,50,20}, acc = {20, 70, 90};
    int L = 120, M = 400, N =3;

    cout<<minHoursForSafetyAlarm(speeds, acc, M, L, N);

    return 0;
}