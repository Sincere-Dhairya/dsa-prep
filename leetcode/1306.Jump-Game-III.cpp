/**
 * @brief 
 * 
 */
/*
Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.

Notice that you can not jump outside of the array at any time.

 

Example 1:

Input: arr = [4,2,3,0,3,1,2], start = 5
Output: true
Explanation: 
All possible ways to reach at index 3 with value 0 are: 
index 5 -> index 4 -> index 1 -> index 3 
index 5 -> index 6 -> index 4 -> index 1 -> index 3 
Example 2:

Input: arr = [4,2,3,0,3,1,2], start = 0
Output: true 
Explanation: 
One possible way to reach at index 3 with value 0 is: 
index 0 -> index 4 -> index 1 -> index 3
Example 3:

Input: arr = [3,0,2,1,2], start = 2
Output: false
Explanation: There is no way to reach at index 1 with value 0.
 

Constraints:

1 <= arr.length <= 5 * 104
0 <= arr[i] < arr.length
0 <= start < arr.length
*/

//Backtracking - recursion by taking help of visited array.
class Solution {
public:
    bool verifypath(vector<int> & arr, int i, int n, vector<bool> & status, int pos){
        if(i < 0 || i >= n || status[i]) return false;
        if(arr[i] == 0) return true;
        
        status[i] = 1;
        
        if(i < pos){
            if(verifypath(arr, i+arr[i], n, status, pos))
                return true;
            else if(verifypath(arr, i-arr[i], n, status, pos))
                return true;
        }
        else{
            if(verifypath(arr, i-arr[i], n, status, pos))
                return true;
            else if(verifypath(arr, i+arr[i], n, status, pos))
                return true;
        }
        return false; 
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size(), pos = find(arr.begin(), arr.end(), 0)-arr.begin();
        vector<bool> status(n, 0);
        
        return verifypath(arr, start, n, status, pos);
    }
};

/*
[6,4,2,3,3,1,2,0,5,7]
5
*/

//Backtracking without visited array
class Solution {
public:
    bool verifypath(vector<int> & arr, int i, int n, int pos){
        if(i < 0 || i >= n || arr[i]<0) return false;
        if(arr[i] == 0) return true;
        
        arr[i] *=-1;
        
        if(i < pos){
            if(verifypath(arr, i+arr[i], n, pos))
                return true;
            else if(verifypath(arr, i-arr[i], n, pos))
                return true;
        }
        else{
            if(verifypath(arr, i-arr[i], n, pos))
                return true;
            else if(verifypath(arr, i+arr[i], n, pos))
                return true;
        }
        return false;
    }
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size(), pos = find(arr.begin(), arr.end(), 0)-arr.begin();
        return verifypath(arr, start, n, pos);
    }
};

/*
[6,4,2,3,3,1,2,0,5,7]
5
*/