#include<bits/stdc++.h>

using namespace std;

int difference(vector<int> arr, vector<int> a)
{
    int mindiff, n1 = a.front(), n2 = a.back();
    if(a.back() - a.front() == 1){
        mindiff = abs(arr[a[0]] - arr[a[1]]);
        if (!mindiff) mindiff = -1;        
    }
    else{
        mindiff = -1;
        sort(arr.begin()+a[0], arr.begin()+a[1]+1);
        
        for(int i =n1; i<n2; i++){
            int tempdiff = abs(arr[i+1]-arr[i]);
            cout<<"tempdiff is : "<<tempdiff<<endl;
            if (!tempdiff) tempdiff = -1;
            
            //below portion is not being executed.
            if(mindiff == -1){
                if(tempdiff != -1) mindiff = tempdiff;
            }
            else{
                if(tempdiff != -1) mindiff = min(mindiff, tempdiff);
            }
            cout<<"Mindiff is: "<<mindiff<<endl;
        }
        /*for(int i = n1; i <= n2-1; i++){
            int diff = abs(arr[i]-arr[i+1]);
            
            if(!diff) diff=-1;
            
            //cout<<"diff for now is "<<diff<<endl;
            for(int j = i+1; j<=n2; j++){
                int tempdiff = abs(arr[i] - arr[j]);
                if (!tempdiff) tempdiff = -1;
                else {
                    diff = min(diff, tempdiff);
                }
                
            }
            if(mindiff == -1){
                if (diff != -1) mindiff = diff;
            }
            else {
                if (diff != -1) mindiff = min(mindiff, diff);
            }
        }
        //cout<<mindiff<<endl;*/
    }
    return mindiff;
}
int main()
{
    vector<int> nums = {1,3,4,8};
    vector<vector<int>> queries = {{0,1},{1, 2},{2,3},{0,3}};
    int ql= queries.size();
        
    vector<int> arr;
    for(int i =0; i<ql; i++){
        //cout<<endl<<i+1<<" iteration in main"<<endl;
        arr.push_back(difference(nums, queries[i]));
    }
    //cout<<"Final Return";
    for(int i  = 0; i < ql; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}