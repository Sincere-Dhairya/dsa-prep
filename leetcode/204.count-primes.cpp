/*
 * @lc app=leetcode id=204 lang=cpp
 *
 * [204] Count Primes
 */

// @lc code=start
#define x 5000000
class Solution {
public:
    int primesieve(int n){
        if(n<=2) return 0;

        int primes[n];
        for(int i = 0 ; i< n; i++) primes[i] = 1;

        for(int i = 2; i*i <= n; i++){
            if(primes[i] == 0) continue; 
            for(int j = i*i; j<n ; j+= i){
                primes[j] = 0;
            }
        }

        primes[0] = primes[1] = 0;
        int count = 0;
        for(int i = 0; i<n; i++){
            if(primes[i]) {
                //cout<<i<<" ";
                ++count;
            }
        }
        return count;
    }

    // int primesieve(int n){
    //     if(n<=2) return 0;
    //     int primes[x];
    //     for(int i = 0; i< x; i++){
    //         primes[i] = 1;
    //     }

    //     for(int i = 2; i<x; i+=2){
    //         primes[i] = 0;
    //     }

    //     for(int i = 3; i*i<n; i++){
    //         if(primes[i] == 0) continue;
    //         for(int j = i*i; j<n; j+=i) primes[j] = 0;
    //     }

    //     primes[0] = primes[1] = 0;
    //     primes[2] =1;
    //     int count = 0;
    //     for(int i = 0; i<n; i++){
    //         if(primes[i]) ++count;
    //     }
        
    //     return count;
    // }
    int countPrimes(int n) {
        int count = primesieve(n);
        return count;
    }
};
// @lc code=end

