/**
 * @file 1291. Sequential Digits
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-23
 * @link https://leetcode.com/problems/sequential-digits/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

 

Example 1:

Input: low = 100, high = 300
Output: [123,234]
Example 2:

Input: low = 1000, high = 13000
Output: [1234,2345,3456,4567,5678,6789,12345]
 

Constraints:

10 <= low <= high <= 10^9   
*/

//NlogN approach. 
class Solution {
public:
    int nummaker(int digits, int start){
        int num = 0, ten = 10;
        while(digits--){
            num *= ten;
            num += start;
            ++start;
            if(start+digits-1 >= 10){
                break;
            }
        }
        return num;
    }
    vector<int> sequentialDigits(int low, int high) {
        int ldigit = 0, hdigit = 0, llow = low, hhigh = high, lfirst, hfirst;
        while(llow){
            ++ldigit;
            if(llow/10 == 0){
                lfirst = llow;
            }
            llow/=10;
        }
        while(hhigh){
            ++hdigit;
            if(hhigh/10 == 0){
                hfirst = hhigh;
            }
            hhigh /= 10;
        }
        vector<int> numbers;
        for(int digits = ldigit; digits<=hdigit; digits++){
            cout<<digits<<" ";
            for(int start = (digits==ldigit?lfirst:1); start+digits-1<10; start++){
                int num = nummaker(digits, start);
                if(num <= high and num>=low){
                    numbers.push_back(num);
                }
                
            }
        }
        return numbers;
    }
};

//OP approach
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> numbers = {
            12,23,34,45,56,67,78,89,
            123,234,345,456,567,678,789,
            1234,2345,3456,4567,5678,6789,
            12345,23456,34567,45678,56789,
            123456,234567,345678,456789,
            1234567,2345678,3456789,
            12345678,23456789,
            123456789
        };
        int indl = lower_bound(numbers.begin(), numbers.end(), low)-numbers.begin(),
        indh = upper_bound(numbers.begin(), numbers.end(), high)-numbers.begin();
        vector<int> ans (numbers.begin()+indl, numbers.begin()+indh);
        return ans;
    }
};


/** Test Cases
250000
1000000000
250607
180000000
100000000
1000000000
2756
345689120
86435
46546875
123
1234
100
150
10010010
12345678
*/