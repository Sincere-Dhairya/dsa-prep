#include<bits/stdc++.h>

using namespace std;

void left(int i, int j, vector<string> A, vector<vector<bool>>& visited);
void right(int i, int j, vector<string> A, vector<vector<bool>>& visited);
void down(int i, int j, vector<string> A, vector<vector<bool>>& visited);
void up(int i, int j, vector<string> A, vector<vector<bool>>& visited);

void right(int i, int j, vector<string> A, vector<vector<bool>>& visited){
    //visited[i][j] = 1;
    int n = A[i].size(), m = A.size();
    for(int k = j; k<n && A[i][k] == 'X'; k++){
        if(A[i][k] == 'X' && visited[i][k] == 0) {
            //cout<<"\ninside right\n"<<i<< " "<<k<<endl;
            visited[i][k] = 1;
            if(i != m-1 && A[i+1][k] == 'X' && visited[i+1][k] == 0)
                down(i+1, k, A,visited);
            if((i != 0) && (A[i-1][k] == 'X') && (visited[i-1][k] == 0)){
                //cout<<"..."<<endl;
                up(i-1, k, A, visited);
            }
        }
        //if(A[k][j] != 'X') return;
    }
}

//pass left of j index in leftfunction.
void left(int i, int j, vector<string> A, vector<vector<bool>>& visited){
    //visited[i][j] = 1;
    int n = A[i].size(), m = A.size();
    for(int k = j; k>=0 && A[i][k] == 'X'; k--){
        //cout<<"\ninside left\n";
        if(A[i][k] == 'X' && visited[i][k] == 0) {
            visited[i][k] = 1;
            if(i != m-1 && A[i+1][k] == 'X' && visited[i+1][k] == 0)
                down(i+1, k, A, visited);
            if(i != 0 && A[i-1][k] == 'X' && visited[i-1][k] == 0)
                up(i-1, k, A, visited);
        }
        //if(A[k][j] != 'X') return;
    }
}

void down(int i, int j, vector<string> A, vector<vector<bool>>& visited){
    int n = A[i].size(), m = A.size();
    for(int k = i; k<m && A[k][j] == 'X'; k++){
        if(A[k][j] == 'X' && visited[k][j] == 0){
            //cout<<"\ninside down\n";
            visited[k][j] = 1;
            if(j != n-1 && A[k][j+1] == 'X' && visited[k][j+1] == 0)
                right(k, j+1, A, visited);
            if(j != 0 && A[k][j-1] == 'X' && visited[k][j-1] == 0)
                left(k, j-1, A, visited);
        }
        //if(A[k][j] != 'X') return;
    }
}

void up(int i, int j, vector<string> A, vector<vector<bool>>& visited){
    int n = A[i].size(), m = A.size();
    //cout<<"\nwe are in up"<<endl;
    for(int k = i; k>=0 && A[k][j] == 'X'; k--){
        //cout<<"we are in for"<<endl;
        if(A[k][j] == 'X' && visited[k][j] == 0){
            //cout<<"\nentered up "<<k<<" "<<j<<endl;
            visited[k][j] = 1;
            if(j != n-1 && A[k][j+1] == 'X' && visited[k][j+1] == 0)
                right(k, j+1, A, visited);
            if(j != 0 && A[k][j-1] == 'X' && visited[k][j-1] == 0)
                left(k, j-1, A, visited);
        }
        //if(A[k][j] != 'X') return;
    }
}

int black(vector<string> &A) {
    int row = A.size(), col = A[0].size(), count = 0;
    vector<vector<bool>> visited(row, vector<bool> (col, false));

    for(int i = 0; i<row; i++){
        for(int j =0; j<col; j++){
            //cout<<i<<" "<<j<<" "<<A[i][j];
            if(A[i][j] == 'X' && visited[i][j] == 0){
                //cout<<" entered ";
                visited[i][j] = 1;
                if(j != col-1 && A[i][j+1] == 'X' && visited[i][j+1] == 0) right(i, j+1, A, visited);
                if(i != row-1 && A[i+1][j] == 'X' && visited[i+1][j] == 0) down(i+1, j, A, visited);
                ++count;
            }
            //cout<<endl;
        }
    }
    return count;
}

int main(){
    vector < string > pattern = {"XOOOOOXXOX", "OOXXXXOOXX", "XXOXXOOXXO", "OXOXXXXXXO", "XOXXOXOXXX", "OOOOOOOXOO", "XOXXXOOXOX", "XXXOXOXXXO"};
    int ans = black(pattern);
    cout<<ans;
    return ans;
}

//5 9 8 6 2 1 
/*
9 8 6 5 2 1
^

q1 -> [5] 9 8 6 2 1
savemax = save the maximum element after popping one by one.
savemin = similarly.
5, 9, 8, 6, 2, 1
q2 -> 

"XOOOOOXXOX", 
"OOXXXXOOXX", 
"XXOXXOOXXO", 
"OXOXXXXXXO", 
"XOXXOXOXXX", 
"OOOOOOOXOO", 
"XOXXXOOXOX", 
"XXXOXOXXXO"
*/