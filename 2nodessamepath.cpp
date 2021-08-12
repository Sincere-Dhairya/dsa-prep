#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int data;
    node * left;
    node * center;
    node * right;
    node(int data){
        this->data = data;
        this->center = nullptr;
        this->left = nullptr;
        this->right = nullptr;
    }
};
bool find1 = false, find2 = false;

bool pathchecker(node * root, int k1, int k2){
    if(!root) return false;
    
    if(find1 && find2) return true;

    if (find1) {
        if(root->data == k2){
            find2 = true;
            return true;
        }
    }

    if(find2) {
        if(root->data == k1) {
            find1 = true;
            return true;
        }
    }
    if(root->data == k1) find1 = true;
    if(root->data == k2) find2 = true;

    bool var1 = pathchecker(root->left, k1, k2);
    bool var2 = pathchecker(root->center, k1, k2);
    bool var3 = pathchecker(root->right, k1, k2);

    if(var1 || var2 || var3) return true;
    find1 = find2 = false;
    return false;
}

int main(){
    node * node1 = new node(1);
    node * node2 = new node(2);
    node * node3 = new node(3);
    node * node4 = new node(4);
    node * node5 = new node(5);
    node * node6 = new node(6);
    node * node7 = new node(7);

    node1->left = node2;
    node1->center = node3;
    node1->right = node4;
    node2->left = node5;
    node3->center = node6;
    node4->right = node7;
    auto check = pathchecker(node1, 4, 7);
    cout<<check<<endl;

}