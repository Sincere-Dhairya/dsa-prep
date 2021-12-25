/**
 * @file 146. LRU Cache
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-12-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

class LRUCache {
public:
    class Node{
        public:
        int key, val;
        Node * left, * right;
        Node(int k, int v){
            key = k, val = v, left = NULL, right = NULL;
        }
        Node(){
            left = right = NULL;
        }
    };
    Node * head = new Node;
    Node * tail = new Node;
    int cap;
    unordered_map<int, Node*> list;
    
    LRUCache(int capacity) {
        cap = capacity, head->right = tail, tail->left = head;
    }
    
    void insertion(Node * newnode){
        head->right->left = newnode, newnode->right = head->right;
        head->right = newnode, newnode->left = head;
    }
    
    void deletion(Node * node){
        node->left->right = node->right;
        node->right->left = node->left;
        //delete node;
    }
//    void printing(){
//        for(auto i : list)
//            cout<<i.first<<" "<<i.second->val<<endl;
//        cout<<endl;
//    }
    int get(int key) {
        //printing();
        if(list.count(key)){
            Node * temp = list[key];
            int v = temp->val;
            list.erase(key);
            deletion(temp);
            insertion(temp);
            list[key] = head->right;
            return v;
        }
        else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        Node * newnode = new Node(key, value);
        if(list.count(key)){
            Node * temp = list[key];
            list.erase(key);
            deletion(temp);
        }
        if(list.size() >= cap){
            list.erase(tail->left->key);
            deletion(tail->left);
        }
        insertion(newnode);
        list[key] = head->right;
        //printing();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */