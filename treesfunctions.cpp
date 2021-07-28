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
int length = 0;
void printingpreorder(Tree * root){
    
    if(root == NULL) return;

    cout<<root->data<<" ";
    ++length;
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

    //cout<<"Deleting "<<root->data<<endl;
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

int diametercalc(Tree * &root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right == NULL) return 1;

    int l = diametercalc(root->left), r = diametercalc(root->right);
    int len = max(l, r);
    root->diameter = l+r;
    return len+1;

}

int max_dia = 0;

void finding_max_dia(Tree * root){
    if(root == NULL) return;
    max_dia = max(max_dia, root->diameter);

    finding_max_dia(root->left);
    finding_max_dia(root->right);
}

Tree * tocken = nullptr, *parent = nullptr;
bool flag = false;

void finding_key(Tree * &root, int key){
    if(!root) return;

    Tree * temp = root;
    if( !flag){
        if(temp->data == key) {
            tocken = temp;
            flag = true;
            cout<<tocken->data<<" found!"<<endl;
        }
        else{
            finding_key(temp->left, key);
            finding_key(temp->right, key);
        }
    }
    return;
}

void find_parent(Tree * &root){
    if(!root) return;

    if(flag){
        
        if (root->left == tocken || root->right == tocken){
            parent = root;
            flag= 0;
            return;
        }
        else {
            find_parent(root->left);
            find_parent(root->right);
        }
    }
}

Tree * next_child = nullptr;

void inorder(Tree * root = tocken->right){
    if (root == NULL) return;

    inorder(root->left);
    inorder(root->right);
}

Tree * save_inorder = nullptr;

void inorder_next(Tree * & root){
    if(root == NULL) return;
    cout<<"current-> "<<root->data<<endl;

    if(root->left != NULL) inorder_next(root->left);
    else {
        save_inorder == root;
        return;
    }
    //inorder_next(root->right);
}

void deletingelement(){
    if (tocken->left == NULL && tocken -> right == NULL){
        delete tocken;
        //delete parent;
    }

    else if(tocken->left != NULL || tocken->right != NULL){
        if(tocken->left != NULL && tocken ->right != NULL){
            inorder_next(tocken->right);
            if(parent->right == tocken){
                parent->right = save_inorder;
                
            }
        }
        else{

        }
    }
}

bool find_the_element(Tree * root, int k){
    bool var;
    if(!root) {
        var = false;
        return var;
    }

    if(k > root->data) {
        var = find_the_element(root->right, k);
    }
    else if(k < root->data){
        var = find_the_element(root->left, k);
    }

    else{
        var = true;
    }
    return var;
}

void find_common_ancestor(Tree * root, int k1, int k2){

    bool var = find_the_element(root, k1);
    if(!var){
        cout<<"number dont exist in tree!\n";
        return;
    }

    var = find_the_element(root, k2);
    if(!var){
        cout<<"number dont exist in tree!\n";
        return;
    }

    if (root== NULL) cout<<"No common ancestor exists!"<<endl;

    if(k1<root->data && k2<root->data) {
        find_common_ancestor(root->left, k1, k2);
    }

    else if(k1> root->data && k2> root->data) {
        find_common_ancestor(root->right, k1, k2);
    }

    else {
        cout<<" the closest ancestor is: "<<root->data<<endl;
        return;
    }
}
static int k_smallest;


void findkthsmallest(Tree *root){
    if(!root) return;

    findkthsmallest(root->left);

    --k_smallest;
    if(!k_smallest) cout<<root->data<<endl;

    if (k_smallest){
        findkthsmallest(root->right);
    }
}
queue<int> q1;
queue<int> q2;

void pushing_ancestors(queue<int> &q1, Tree * root, int k){
    if(!root) return;

    if(k>root->data){
        q1.push(root->data);
        cout<<root->data<<" is pushed!\n";
        pushing_ancestors(q1, root->right, k);
    }
    else if(k< root->data){
        q1.push(root->data);
        cout<<root->data<<" is pushed!\n";
        pushing_ancestors(q1, root->left, k);
    }

    else {
        q1.push(root->data);
        return;
    }
}

void finding_ancestor_from_queues(queue<int> q1, queue<int> q2){
    int top1 = q1.front(), top2 = q2.front(), saving = INT_MIN;

    while(!(q1.empty() || q2.empty()) && (q1.front() == q2.front())){
        saving = q1.front();
        cout<<saving<<endl;
        q1.pop();
        q2.pop();
    }

    if(saving == INT_MIN) cout<<"No common ancestor exits!"<<endl;
    else cout<<saving<<" is the common ancestor!\n";
}

bool findpath(Tree * root, vector<int> & path, int k){
    if(root == NULL) return false;

    path.push_back(root->data);

    if(k == root->data) return true;

    if( findpath(root->left, path, k) || findpath(root->right, path, k)) return true;

    path.pop_back();
    return false;
}

int lca (Tree * root, int k1, int k2){
    vector<int> path1, path2;

    if(!findpath(root, path1, k1) || !findpath(root, path2, k2)) return -1;

    int n1 = path1.size(), n2 = path2.size(), i;

    for(i = 0; i<n1 && i<n2; i++){
        if(path1[i] != path2[i]) break;
    }

    return path1[i-1];
}