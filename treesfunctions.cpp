#include<bits/stdc++.h>

using namespace std;

class Tree{
    public:
    int data;
    //bool pos = false;
    Tree * left = NULL;
    Tree * right = NULL;
    int height;
    int diameter = 0;

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
        root->height = 0;
        root->diameter = 0;
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
        var->height = current->height +1;
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

    queue<Tree *> q;

void bfs( Tree * root){
    if(!root) return;
    q.push(root);

    while(!q.empty()){
        Tree * temp = q.front();
        q.pop();
        cout<<temp->data<<" ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }

}

int max_height = 0;

void heightcalc(Tree * root, int h=0){
    if(!root) return;

    max_height = max(max_height, h);
    heightcalc(root->left, h+1);
    heightcalc(root->right, h+1);
}


int max_imum = 0;

void height2(Tree * root){
    if(!root) return;

    max_imum = max(max_imum, root->height);
    height2(root->left);
    height2(root->right);   
}

int diametercalc(Tree * root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return root->height;

    int temp = diametercalc(root->left) + diametercalc(root->right);
    root->diameter = temp;
}