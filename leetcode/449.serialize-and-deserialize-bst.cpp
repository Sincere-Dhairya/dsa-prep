/*
 * @lc app=leetcode id=449 lang=cpp
 *
 * [449] Serialize and Deserialize BST
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<bits/stdc++.h>
using namespace std;

typedef TreeNode tn;

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        queue<tn*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            tn * temp = q.front();
            for(int i =0 ;i<n; i++){
                tn * node = q.front();
                q.pop();
                if(!node){
                    //ans += "NULL ";
                    continue;
                }
                else ans += to_string(node->val) + " ";
                q.push(node->left);
                q.push(node->right);
            }
        }
        return ans;
    }

    void pushingdata(tn * &root, tn * node){
        if(root == NULL) {
            root = node;
            return;
        }

        if(node->val > root->val){
            if(root->right == NULL) root->right = node;
            else pushingdata(root->right, node);
        }
        if(node->val < root->val){
            if(root->left == NULL) root->left = node;
            else pushingdata(root->left, node);
        }
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        string part = "";
        vector<int> treedata;
        //cout<<data<<endl;
        for(int i = 0; i<data.size(); i++){
            if(data[i] == ' '){
                int d = stoi(part);
                //cout<<d<<" ";
                treedata.push_back(d);
                part = "";
                //cout<<"-"<<treedata.back()<<"-"<<endl;
                //++i;
                continue;
            }
            part += data[i];
        }
        tn * root = nullptr;
        if(treedata.size()){
            root = new tn(treedata.front());
            for(int i = 1; i<treedata.size(); i++){
                tn * newnode = new tn(treedata[i]);
                pushingdata(root, newnode);
            }
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
// @lc code=end

