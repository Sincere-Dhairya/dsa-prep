/**
 * @file 705. Design HashSet
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-04-21
 * @link https://leetcode.com/problems/design-hashset/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

void add(key) Inserts the value key into the HashSet.
bool contains(key) Returns whether the value key exists in the HashSet or not.
void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
 

Example 1:

Input
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
Output
[null, null, null, true, false, null, true, null, false]

Explanation
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // return True
myHashSet.contains(3); // return False, (not found)
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // return True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // return False, (already removed)
 

Constraints:

0 <= key <= 106
At most 104 calls will be made to add, remove, and contains.
*/

//TC is as mentioned.
class MyHashSet {
public:
    vector<int> arr[1000];
    MyHashSet() { //O(1)
    }
        
    void remove(int key) { // tc o(n) sc o(n)
        vector<int> temp;
        int ind = key%1000;
        for(int i = 0; i<arr[ind].size(); ++i){
            if(arr[ind][i] != key){
                temp.push_back(arr[ind][i]);
            }
        }
        arr[ind] = temp;
        return;
    }
    
    bool contains(int key) { // o(n)
        int ind = key%1000;
        for(int i = 0; i<arr[ind].size(); ++i){
            if(arr[ind][i] == key){
                return true;
            }
        }
        return false;
    }
    
    void add(int key) { // O(n)
        if(contains(key)){ // o(n)
            return ;
        }
        int ind = key%1000;
        arr[ind].push_back(key); // O(1)
        return;
    }
};