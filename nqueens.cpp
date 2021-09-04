#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> chessboard(4, vector<int> (4, 0));
vector<int> qc(4, 0), leftd(8, 0), rightd(8,0);
void printingchess();

bool validposition(int row, int q, int n){
    if(row == n){
        printingchess();
        cout<<endl;
        return false;
    }

    for(int i =0; i<n; i++){
        if( qc[i] || leftd[n+row-i] || rightd[row+i] ) continue;
        else{
            chessboard[row][i] = 
            qc[i] = 
            leftd[n+row-i] = 
            rightd[row+i] = q;

            if(validposition(row+1, q+1, n)) return true;
            else{
                chessboard[row][i] = 
                qc[i] =
                leftd[n+row-i] = 
                rightd[row+i] = 0;
            }
        }
    }
    return false;
}

void printingchess(){
    for(int i =0; i<4; i++){
        for(int j = 0; j<4; j++)
            cout<<chessboard[i][j]<<" ";
        cout<<endl;
    }
}

int main(){  
    //this is for first queen's position.
    //row = 0, queen's rank = 1
    int n =4;
    //cin>>n;
    // for(int i = 0; i<n; i++){
    //     validposition(i, 1, n);
    // }
    validposition(0, 1, n);
    return 0;
}