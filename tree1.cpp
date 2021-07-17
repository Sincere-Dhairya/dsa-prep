#include<bits/stdc++.h>
#include"treesfunctions.cpp"

using namespace std;

int main(){
    Tree * root = nullptr;
    vector<int> arr = {9, 9, 5, 7, 11, 4, 1, 22, 13, 2, 22, 8, 0, 7};
    for(int i =0; i<arr.size(); i++){
        inserting(root, arr[i]);
    }

    printingpreorder(root);
    cout<<endl;
    printinginorder(root);
    cout<<endl;
    printingpostorder(root);
    cout<<endl;
    calling(root);
    deleting(root);
    return 0;
}