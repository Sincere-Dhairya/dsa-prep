//Reshape the Matrix

#include<bits/stdc++.h>

using namespace std;

int main(){
    vector<vector <int> > mat= {{1,2},{3,4},{5,6}};
    int r =1, c=6;

    int row = mat.size(), col = mat[0].size();
    //if(row*col == r*c) return mat;

    vector<vector<int>> arr(r,vector <int>(c));

    vector<int> temp;

    for(int i = 0; i<row; i++){
        for(int j =0; j<col; j++){
            temp.push_back(mat[i][j]);
            cout<<"Pushed: "<<mat[i][j]<<endl; 
        }
    }
    int k =0 ;
    for(int i = 0; i < r; i++){
        for(int j =0; j<c; j++){
            arr[i][j] = temp[k];
            ++k;
        }
        
    }

    for(int i = 0; i < r; i++){
        for(int j =0; j<c; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

}