#include<iostream>
#include<vector>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left, *right;
    TreeNode(){
        // val = 0;
        left = nullptr, right = nullptr;
    }
    TreeNode(int v){
        val = v;
        left = nullptr, right = nullptr;
    }
};

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
    
    return ;
}

void inorderTravesal(TreeNode* root){
    if(!root) return ;
    
    inorderTravesal(root->left);
    cout << root->val << " ";
    inorderTravesal(root->right);
    
    return;
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
        // Leaf Node.
        if(root->left == NULL && root->right == NULL){
            return NULL;
        }
        
        // For Node having only one child.
        if(root->left == NULL){
            return root->right;
        }
        if(root->right == NULL){
            return root->left;
        }
        
        // For node having 2 children.
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
    
    deletion(root, 15);
    cout << endl;
    inorderTravesal(root);
    
    deletion(root, 10);
    cout << endl;
    inorderTravesal(root);
    
    deletion(root, 20);
    cout << endl;
    inorderTravesal(root);
    
    return 0;
}