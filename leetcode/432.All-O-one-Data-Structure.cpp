/**
 * @file 432. All O`one Data Structure
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
/*
Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

Implement the AllOne class:

AllOne() Initializes the object of the data structure.
inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".
 

Example 1:

Input
["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
[[], ["hello"], ["hello"], [], [], ["leet"], [], []]
Output
[null, null, null, "hello", "hello", null, "hello", "leet"]

Explanation
AllOne allOne = new AllOne();
allOne.inc("hello");
allOne.inc("hello");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "hello"
allOne.inc("leet");
allOne.getMaxKey(); // return "hello"
allOne.getMinKey(); // return "leet"
 

Constraints:

1 <= key.length <= 10
key consists of lowercase English letters.
It is guaranteed that for each call to dec, key is existing in the data structure.
At most 5 * 104 calls will be made to inc, dec, getMaxKey, and getMinKey.
*/

class AllOne {
public:
    class Node{
        public:
        string key;
        int count;
        Node * left, *right;
        Node(string k){
            key = k, count = 0, left = nullptr, right = nullptr;
        }
    };
    unordered_map<string, Node *> list;
    Node * start, *end;
    AllOne() {
        start = new Node("-s"), end = new Node("-e");
        start->right = end, end->left = start;
    }
    
    void inc(string key) {
        if(list.count(key)){
            ++list[key]->count;
            while(list[key]->left != start and list[key]->count > list[key]->left->count){ //o n
                Node * temp = list[key]->left;
                list[key]->left = temp->left;
                temp->right = list[key]->right;
                temp->right->left = temp;
                temp->left->right = list[key];
                list[key]->right = temp;
                temp->left = list[key];
            }
        }
        else{
            Node * newnode = new Node(key);
            newnode->left = end->left, newnode->right = end;
            end->left->right = newnode, end->left = newnode, newnode->count = 1;
            list[key] = newnode;
        }
    }
    
    void dec(string key) {
        if(--list[key]->count == 0){
            Node * temp = list[key];
            list.erase(key);
            temp->left->right = temp->right;
            temp->right->left = temp->left;
            delete temp;
        }
        else
            while(list[key]->right != end and list[key]->count < list[key]->right->count){ // o n
                Node * temp = list[key]->right;
                list[key]->right = temp->right;
                temp->left = list[key]->left;
                temp->left->right = temp;
                temp->right->left = list[key];
                list[key]->left = temp;
                temp->right = list[key];
            }
    }
    
    string getMaxKey() { // o 1
        if(start->right == end)
            return "";
        return start->right->key;
    }
    
    string getMinKey() { // o 1
        if(end->left == start)
            return "";
        return end->left->key;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */

/*Test Cases
["AllOne","inc","inc","inc","inc","inc","inc","dec","getMaxKey","getMinKey","inc","getMaxKey","getMinKey"]
[[],["hello"],["hello"],["nam"],["nam"],["nam"],["khoo"],["khoo"],[],[],["leet"],[],[]]
["AllOne","inc","inc","inc","inc","inc","inc","dec","dec","dec","dec","getMaxKey","getMinKey","inc","getMaxKey","getMinKey"]
[[],["hello"],["hello"],["nam"],["nam"],["nam"],["khoo"],["khoo"],["nam"],["nam"],["nam"],[],[],["leet"],[],[]]
*/