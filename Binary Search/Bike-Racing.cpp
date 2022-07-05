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