/**
 * @file AVL-Trees
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-08-08
 * @link https://www.geeksforgeeks.org/avl-tree-set-1-insertion/ @endlink
 * @copyright Copyright (c) 2022
 * @tags avl-trees binary-search-trees
 */

#include<iostream>
#include<vector>
using namespace std;

class TreeNode{
    public:
    int val, height;
    TreeNode* left, *right;
    TreeNode(){
        left = nullptr, right = nullptr;
    }
    TreeNode(int v){
        val = v, height = 0;
        left = nullptr, right = nullptr;
    }
};

void inorderTravesal(TreeNode* root){
    if(!root) return ;
    
    inorderTravesal(root->left);
    cout << root->val << " ";
    inorderTravesal(root->right);
    
    return;
}

void preorderTravesal(TreeNode* root){
    if(!root) return ;
    
    cout << root->val << " ";
    inorderTravesal(root->left);
    inorderTravesal(root->right);
    
    return;
}

int getHeight(TreeNode* &node){
    if(!node) return 0;
    if(!node->left && !node->right){
        return node->height = 1;
    }
    
    return node->height = 1+max(getHeight(node->left), getHeight(node->right));
}

int getBalance(TreeNode* &node){
    return getHeight(node->left) - getHeight(node->right);
}

TreeNode* rightRotation(TreeNode* &node){
    TreeNode* newRoot = node->left;
    node->left = newRoot->right;
    newRoot->right = node;
    
    newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right));
    return newRoot;
}

TreeNode* leftRotation(TreeNode* &node){
    TreeNode* newRoot = node->right;
    node->right = newRoot->left;
    newRoot->right = node;
    
    newRoot->height = max(getHeight(newRoot->left), getHeight(newRoot->right));
    return newRoot;
}

void insertion(TreeNode* &root, TreeNode* newNode){
    if(root == NULL){
        root = newNode;
        // cout << "NewNode inserted!" <<endl;
        return ;
    }
    
    if(root->val > newNode->val){
        if(root->left){
            insertion(root->left, newNode);
            return ;
        }
        root->left = newNode;
        // cout << "NewNode inserted!" <<endl;
    }
    else{
        if(root->right){
            insertion(root->right, newNode);
            return ;
        }
        root->right = newNode;
        // cout << "NewNode inserted!" <<endl;
    }
    
    preorderTravesal(root);
    cout << endl;
    
    int balance = getBalance(root);
    
    if(balance > 1){
        if(root->left->val > newNode->val){
            root = rightRotation(root);
        }
        else if(root->left->val < newNode->val){
            root->left = leftRotation(root->left);
            root = rightRotation(root);
        }
    }
    else if(balance < -1){
        if(root->right->val < newNode->val){
            root = leftRotation(root);
        }
        else if(root->right->val > newNode->val){
            root->right = rightRotation(root->right);
            root = leftRotation(root);
        }
    }
    preorderTravesal(root);
    cout << endl;
    return ;
}

TreeNode* findInorderNode(TreeNode* root){
    if(root->left == NULL) return root;
    return findInorderNode(root->left);
}

TreeNode* deletion(TreeNode* root, int val){
    if(root->val > val){
        root->left = deletion(root->left, val);
    }
    else if(root->val < val){
        root->right = deletion(root->right, val);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            return NULL;
        }
        
        if(root->left == NULL){
            return root->right;
        }
        if(root->right == NULL){
            return root->left;
        }
        
        TreeNode* minNode = findInorderNode(root->right);
        int valToBeDelNext = minNode->val;
        root->val = minNode->val;
        
        root->right = deletion(root->right, root->val);
    }
    return root;
}

int main(){
    vector<int> arr = {20,10,30,5,15,25,32,2,7,13,17,12,14,16,18};
    TreeNode* root = nullptr;
    
    for(int i: arr){
        TreeNode* newNode = new TreeNode(i);
        insertion(root, newNode);
    }
    
    inorderTravesal(root);
    
    // deletion(root, 15);
    // cout << endl;
    // inorderTravesal(root);
    
    // deletion(root, 10);
    // cout << endl;
    // inorderTravesal(root);
    
    // deletion(root, 20);
    // cout << endl;
    // inorderTravesal(root);
    
    return 0;
}