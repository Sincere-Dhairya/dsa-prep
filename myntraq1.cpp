/* we are given an array of signed integers. for every +ve number we see, 
it means influence the right and for any left number we encounter, 
it means influence the left. When a positive and negative number encounter each other in a sequence,
it can be the case that the -ve no succeeds +ve no. then we the one with the less magnitude 
will be popped and the algorithm will continue to work till the 2 numbers are of same sign or 
we have reached the end. or the sequence is reveresed that is the -ve comes before the +ve.
Do this for the whole array and return the remaining array.
*/

#include<bits/stdc++.h>

using namespace std;

class node{
    public:
    int data;
    node * left;
    node * right;
    node(int);
};

node :: node(int d){
    data = d;
    left = right = nullptr;
}

void array_operation(node * &head, vector<int> arr){
    int n = arr.size();
    for(int i =1 ;i<n; i++){
        if(arr[i]<0){
            while(head != NULL && head->data > 0 && arr[i] <0){
                if(abs(arr[i]) >= head->data){
                    if(abs(arr[i]) == head->data) ++i;
                    auto temp = head;
                    head = head->left;
                    delete temp;
                }
                else{
                    ++i;
                }
                //if(!head) break;
            }
            if(i<n){
                node * temp = new node(arr[i]);
                temp->left = head;
                head->right = temp;
                head = temp;
            }
        }
        else{
            node * temp = new node(arr[i]);
            temp->left = head;
            if(head == NULL) head = temp;
            else{
                head->right = temp;
                head = temp;
            }
        }
        //node * temp = new node(arr[i]);

    }
}
void printinglist(node * head){
    while(head != NULL) {
        cout<<head->data<<", ";
        head= head->left;
    }
}
int main(){
    vector<int> arr = { 50, 1, 2, -3, -5, 10, -20, 30, -50};
    int n = arr.size();
    node * head = new node(arr.front());
    //cout<<(-2)/(1)<<endl;
    array_operation(head, arr);
    //vector<int> ans;
    if(!head) cout<<"[]";
    printinglist(head);
}