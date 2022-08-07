/**
 * @file Maximum cells attacked by Rook or Bishop in given Chessboard
 * @author @dvbuiilds
 * @brief 
 * @version 0.1
 * @date 2022-08-07
 * @link https://www.geeksforgeeks.org/maximum-cells-attacked-by-rook-or-bishop-in-given-chessboard/ @endlink
 * @copyright Copyright (c) 2022
 * @tags game-theory arrays
 */
/*
Given three integers N, R, and C representing an N*N chessboard and the position (R, C) where the rook and the bishop is placed. The task is to find out who can attack the most number of cells (except the cell they are in) and how many.

Note: 

A rook can move only horizontally along the row or vertically along the column and any number of cells at a time
A bishop can move diagonally any number of cells at a time.
Examples:

Input: N = 3, R = 2, C = 1
Output: Rook, 4
Explanation: Rook can attack 2 cells in the row and 2 cells along the column. So 2+2 = 4.
Bishop can attack only 2 cells (1, 2) and (3, 2).

Input: N=1, R=1, C=1
Output: Both, 0
*/

#include<iostream>
using namespace std;

int main(){
    int N=1, R=1, C=1;

    // Rook runs like elephant.
    int upRook = R-1, downRook = N-R, leftRook = C-1, rightRook = N-C, totalRook = upRook+downRook+leftRook+rightRook;
    // Bishop runs like Temple.
    int leftUpDiag = min(upRook, leftRook), leftDownDiag = min(downRook, leftRook),
    rightUpDiag = min(rightRook, upRook), rightDownDiag = min(rightRook, downRook),
    totalBishop = leftUpDiag+leftDownDiag+rightUpDiag+rightDownDiag;
    
    if((totalBishop ^ totalRook) == 0){
        printf("None of the Bishop and Rook won the game!");
        return 0;
    }
    else if(totalBishop> totalRook){
        printf("Bishop wins! The Bishop can attack %d cells.", totalBishop);
        return 0;
    }
    printf("Rook wins! The Rook can attack %d cells.", totalRook);
    return 0;
}