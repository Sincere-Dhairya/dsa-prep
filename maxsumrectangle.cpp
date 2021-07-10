#include<bits/stdc++.h>

using namespace std;

int arraysum(vector<int> arr, int k)
{
    int summax = INT_MIN, n = arr.size();
    for(int i =0; i<n; i++){
        if(arr[i] == k) {
            cout<<"1. exit with "<<k<<endl;
            return k;
        }
        if(arr[i] < k){
            int itsum = arr[i];
            summax = max(summax, itsum);
            for(int j = i+1;j<n; j++){
                itsum += arr[j];
                if(itsum == k) {
                    cout<<"2. exit with "<<k<<endl;
                    return k;
                }
                else if(itsum < k) summax = max(summax, itsum);

            }
        }
    }
    cout<<"max sum less than "<<k<<" in this array is: "<<summax<<endl;
    return summax;
}

int main()
{
    vector<vector<int>> matrix = {{2,2,-1}};//{{5,-4,-3,4},{-3,-4,4,5},{5,1,5,-4}};
    int k = 0;
    int rows = matrix.size(), cols = matrix[0].size();

    vector<int> a(cols);
    int minorsum = -k, majorsum = -k;

    for(int i = 0; i<rows; i++){
        vector<int> a = matrix[i];
        cout<<"iteration with matrix starting with : "<<matrix[i][0]<<endl;
        int iterationsum = arraysum(a, k);
        if (iterationsum == k) {
            cout<<"3. exit with "<<k<<endl;
            return k;
        }
        for(int j = i+1; j<rows; j++){
            cout<<"Adding array starting with : "<<matrix[j][0]<<endl;
            for(int x = 0; x<cols; x++){
                a[x] += matrix[j][x];
            }
            iterationsum = max(iterationsum, arraysum(a, k));
            if(iterationsum == k) {
                cout<<"4. exit with "<<k<<endl;
                return k;
            }
        }
        majorsum = max(majorsum, iterationsum);
        
    }
    cout<<"Majorsum is: "<<majorsum<<endl;
}