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

    bfs(root);
    cout<<endl;

    cout<<"the height of the tree is: ";
    heightcalc(root, 0);
    cout<<max_height<<endl;
    
    cout<<"height 2 is: ";
    height2(root);
    cout<<max_imum<<endl;

    int height1 = diametercalc(root);
    finding_max_dia(root);

    cout<<"the max dia is: "<<max_dia<<endl; 
    cout<<"the height is: "<<height1-1<<endl;
    find_common_ancestor(root, 5, 40);

    k_smallest = 8;
    findkthsmallest(root);

    pushing_ancestors(q1, root, 5);
    pushing_ancestors(q2, root, 8);
    cout<<q1.front()<<" "<<q2.front()<<endl;
    finding_ancestor_from_queues(q1, q2);
    queue<int> temp;

    cout<<lca(root, 7, 22)<<endl;
    deleting(root);
    return 0;
}