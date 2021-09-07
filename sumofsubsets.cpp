/*print the subsets out of a given array of integers that have sum = the given number*/
#include<bits/stdc++.h>

using namespace std;

vector<bool> partofsub(10, 0);
void printingsubsets(vector<int> arr){
    for(int i = 0; i<partofsub.size(); i++){
        if(partofsub[i]) cout<<arr[i]<<" ";
    }
    cout<<endl;
}

void findingsubsets(int asum, int i, int remsum, vector<int> arr){
    for(int j = i+1; j<arr.size(); j++){
        if(asum + arr[j] < remsum - arr[j]){
            asum += arr[j], remsum -= arr[j];
            findingsubsets(asum, j, remsum, arr);
        }
        else if(asum + arr[j] == remsum - arr[j]){
            printingsubsets(arr);
            return;
        }
    }
}

int main(){
    int givensum = 30;
    vector<int> arr = {5,10,12,13,15,18};
    int arrsum = accumulate(arr.begin(), arr.end(), 0);
    cout<<arrsum;

    for(int i =0; i<arr.size(); i++){
        if(arr[i] <= arrsum-arr[i]){
            findingsubsets(arr[i], i, arrsum-arr[i], arr);
        }
    }
}