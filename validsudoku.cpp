#include<bits/stdc++.h>

using namespace std;

bool checkingrows(vector<vector<char>> board){
    int n = board.size();
    //bool check = false;
    cout<<"checkingrows"<<endl;
    for(int i =0 ;i<n; i++){
        map<char, int> list;
        for(int j = 0; j<n; j++){
            if(board[i][j] != '.'){
                if(!list.count(board[i][j])) ++list[board[i][j]];
                else return false;
            }
        }
    }
    cout<<"passed1"<<endl;
    return true;
}

bool checkingcols(vector<vector<char>> board){
    int n = board.size();
    //bool check = false;
    cout<<"checkingcols"<<endl;
    for(int i =0 ;i<n; i++){
        map<char, int> list;
        for(int j = 0; j<n; j++){
            if(board[j][i] != '.'){
                if(!list.count(board[j][i])) ++list[board[j][i]];
                else return false;
            }
        }
    }
    cout<<"pass2"<<endl;
    return true;
}

bool checksqaures(vector<vector<char>> board){
    for(int i = 0; i<9; i++){
        int j;
        j = i;
        j /= 3;
        j *= 3;
        int k = j+3;
        map<char, int> list;
        cout<<i<<endl;
        while(j<k){
            cout<<"j is: "<<j<<endl;
            int c = (i%3)*3;
            int d = c+3;
            for(c; c<d; c++){
                cout<<c<<' ';
                if(board[j][c] != '.'){
                    if(!list.count(board[j][c])) ++list[board[j][c]];
                    else return false;
                }
            }
            cout<<endl;
            ++j;
        }
        cout<<endl;
    }
    return true;
}

bool isValidSudoku(vector<vector<char>> board) {
    bool var1 = checkingrows(board);
    bool var2 = checkingcols(board);
    bool var3 = checksqaures(board);
    if(checkingrows(board) && checkingcols(board) && checksqaures(board)) return true;
    else return false;
}

int main(){
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'},
                                  {'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','1','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'}};
    if(isValidSudoku) cout<<true;
    else cout<<false;
    return 0;
}