/**
 * @file Buying a Laptop
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-08-08
 * @link https://leetcode.com/discuss/interview-question/370770/postman-hackerearth-software-engineering-intern-bengaluru-india @endlink
 * @copyright Copyright (c) 2022
 * @tags segment-tree
 */
/*
You want to buy a laptop. Each laptop has two parameters: Rating & Price. Your task is to buy a laptop with the highest rating within a given price range. Given Q tasks, each query consisting of price range required, you have to print the highest rated laptop that can be bought within that price range.

Input format:

The first line contains N denoting the number of inputs.
The following N lines contain P & R denoting price and range of a laptop.
Next line contains Q denoting the number of queries.
The following Q lines contain two integers X & Y denoting the price range (inclusive).
Output format:
For each task Q, print the highest rating that can be bought within the range.
If you cannot get any laptop within the range, print -1.

Constraints:
1 <= N <= 10^6
1 <= Q <= 10^6
1 <= R, P <= 10^9
1 <= X, Y <= 10^9

Sample Input:
5
1000 300
1100 400
1300 200
1700 500
2000 600
3
1000 1400
1700 1900
0 2000

Sample Output:
400
500
600
*/

#include <iostream>
#include<vector>

using namespace std;

// class
class TreeNode{
    public:
    int startPrice, endPrice, maxRatings;
    TreeNode* left, *right;
    TreeNode(){}
    TreeNode(int sp, int ep, int maxR){
        startPrice = sp,
        endPrice = ep,
        maxRatings = maxR;
        left = nullptr, right = nullptr;
    }
};

void inorder(TreeNode* root){
    if(!root) return;
    inorder(root->left);
    inorder(root->right);
    cout << root->startPrice<<" "<<root->endPrice<<" "<<root->maxRatings << endl;
}

// class ke methods. build. 
TreeNode* buildTree(vector<vector<int>>& arr, int startInd, int endInd){
    // base case.
    if(startInd == endInd){  
        TreeNode* root = new TreeNode(startInd, endInd, arr[startInd][1]);
        return root;
    }
    
    int mid = (startInd +endInd) /2;
    TreeNode* root = new TreeNode(startInd, endInd, 0);
    root->left = buildTree(arr, startInd, mid),
    root->right = buildTree(arr, mid+1, endInd);
    
    root->maxRatings = max(root->left->maxRatings, root->right->maxRatings);
    return root;
}

// Function for searchQuery.
int queryRatings(vector<vector<int>>& arr, TreeNode* root, int leftBound, int rightBound){
    if(leftBound > rightBound) return 0;
    if(arr[root->startPrice][0] >= leftBound && arr[root->endPrice][0] <= rightBound){ 
        return root->maxRatings;
    }

    int mid = (root->startPrice+root->endPrice)/2;
    if(rightBound <= arr[mid][0]){
        return queryRatings(arr, root->left, leftBound, rightBound);
    }
    else if(leftBound >= arr[mid+1][0]){
        return queryRatings(arr, root->right, leftBound, rightBound);
    }
    else{
        return max(
            queryRatings(arr, root->left, leftBound, arr[mid][0]) ,
            queryRatings(arr, root->right, arr[mid+1][0], rightBound)
        );
    }
    return 0;
}

// a function to construct the tree. and call the queries afterwards.
int main() {
	vector<vector<int>> arr = {
	    {1000,300}, {1100, 400}, {1300, 200}, {1700,500}, {2000, 600}
	}, query = {
	    {1000, 1400}, {1700, 1900}, {0,2000}
	};
	
	int k = 0;
	TreeNode* root = buildTree(arr, 0, arr.size()-1);
	inorder(root);

	vector<int> response(query.size());
    for(int i = 0; i<query.size(); ++i){
        response[i] = queryRatings(arr, root, query[i][0], query[i][1]);
    }
	
	for(int i: response){
	    cout << i << " ";
	}
	cout <<endl;
	return 0;
}