#include<bits/stdc++.h>

using namespace std;

class Tree{
    public:
    int data;
    //bool pos = false;
    Tree * left = NULL;
    Tree * right = NULL;

    Tree(int data){
        this->data = data;
        //this->pos = pos;
        //this->left = this->right = NULL;
    }
};

void inserting(Tree * &root, int data){
    //cout<<"Inserted!"<<endl;
    Tree * current = root;
    if(root == NULL){
        root = new Tree(data);
        if(root) cout<<data<<" inserted!"<<endl;
    }
    else{
        while(current->left != NULL || current->right != NULL){
            if(data > current->data) {
                if(current->right != NULL) current = current->right;
                else break;
            }

            if(data <= current->data){
                if (current->left != NULL) current = current->left;
                else break;
            }
        }
        Tree * var = new Tree(data);
        if(data > current->data) {current->right = var; cout<<data<<" inserted!"<<endl;}
        else {current->left = var; cout<<data<<" inserted!"<<endl;}
    }
}

void printingpreorder(Tree * root){
    
    if(root == NULL) return;

    cout<<root->data<<" ";

    //left sub tree.
    printingpreorder(root->left);

    //right sub tree.
    printingpreorder(root->right);

}

void printinginorder(Tree *root){
    if(!root) return;

    printinginorder(root->left);

    cout<<root->data<<" ";

    printinginorder(root->right);
}

void printingpostorder(Tree * root){
    if(!root) return;

    printingpostorder(root->left);
    printingpostorder(root->right);

    cout<<root->data<<" ";
}

void deleting(Tree * &root){
    if(!root) return;

    deleting(root->left);
    deleting(root->right);

    cout<<"Deleting "<<root->data<<endl;
    delete root;

}

void bfs(Tree * node1, Tree * node2){
    if(node1 == node2 == NULL) return;
    else if(node1 == NULL && node2 != NULL) cout<<node2->data<<" ";
    else if(node1 != NULL && node2 == NULL) cout<<node1->data<<" ";
    else{
        cout<<node1->data<<" "<<node2->data<<" ";
        bfs(node1->left, node1->right);
        bfs(node2->left, node2->right);
    }
}

void calling(Tree * root){
    cout<<root<<" ";
    bfs(root->left, root->right);
}