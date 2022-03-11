/**
 * @file Questions on Catalan Numbers
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-03-08
 * @link  @endlink
 * @copyright Copyright (c) 2022
 * 
 */

/**
 * 1. No. of BST's out of given N nodes.
 * 2. No. of Unlabelled Trees. -> No. of BST's * N!
 * 3. N Parenthesis.
 * 
 */

/* N Parenthesis. */
int nParenthesis(int n){
    if(n<3){
        return n;
    }
    int records[n+1] = {0};
    records[0] = 1, records[1] = 1;

    for(int i = 2; i<=n; i++){
        for(int j = 0; j<i; ++j){
            records[i] += records[j]*records[i-j-1];
        }
    }
    return records[n];
}