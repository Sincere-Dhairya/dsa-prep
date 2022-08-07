/**
 * @file Find winner of the Game where Array elements are reduced in each turn
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-08-07
 * @link https://www.geeksforgeeks.org/find-winner-of-the-game-where-array-elements-are-reduced-in-each-turn/ @endlink
 * @copyright Copyright (c) 2022
 * @tags arrays game-theory
 */
/*
Given a circular array arr[] of size N containing positive integers only, Player A and B are playing a game, turn by turn, the game will start with player A at index 0 and then player B at the next index.

In every turn a player can deduct some value from arr[i] and decrease the value of an element arr[i] to X ( 0 to arr[i]-1 ).
Then, other player turn will come and he/she will do the same with the next element in right circular order.
If a player cannot decrease the value of the element then he/she loses. Find if A and B play optimally, who will win?

Note: In each turn, a player moves to a new position than his/her previous position.

Examples:

Input: arr[] = {1, 2, 4, 3}
Output: B
Explanation: A have to deduct 1 from 1, 
Now it’s B turn, B deduct whatever from 2, 
Again, A deduct whatever from index 3, 
Again, B deduct whatever from index 4, 
Now, it’s A turn, and A is on index 0, and index 0th element is 0. 
So, A will lose, B win.

Input: arr[] = {5}
Output: A
Explanation: A will decrease the value of arr[i]( 5 ) to 0. 
So, for B the number become 0 and B will lose, A win.
*/

#include<iostream>
#include<vector>
using namespace std;

// True means A wins, False means B wins.
bool getWinner(vector<int>& arr){
    if(int(arr.size())%2) return 1;

    int minPoints = 1e9, minPointInd = 0;
    for(int i=0; i<arr.size(); ++i){
        if(minPoints > arr[i]){
            minPointInd = i;
            minPoints = arr[i];
        }
    }
    if(minPointInd%2) return 1;
    return 0;
}

int main(){
    vector<int> arr = {2,3,4,5,6,7,8,9,0,9,3,1};
    bool winner = getWinner(arr);
    if(winner){
        printf("A won the game!");
    }
    else{
        printf("B won the game!");
    }
    return 0;
}