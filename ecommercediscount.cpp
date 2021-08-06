#include<bits/stdc++.h>

using namespace std;

int main()
{
	// Write your code here
	int n;
	cin>>n;
	vector<int> fibo;
	fibo.push_back(1);
	fibo.push_back(1);
	int len = 2;
	
	while(n>(fibo[len-1] + fibo[len-2])){
		fibo.push_back(fibo[len-2]+fibo[len-1]);
		++len;
	}
	
	int count =0;
	int i = 1, j = fibo.size()-1;
	
	while(i<j){
		int sum = fibo[i] + fibo[j];
		if(sum > n) --j;
		if(sum < n) ++i;
		if(sum == n){
			++count;
			break;
		}
	}
	
	for(int i = 1; i<fibo.size()-2; i++){
		int diff = n-fibo[i];
		int j = i+1, k = fibo.size()-1;
		
		while(j<k){
			int sum = fibo[j] + fibo[k];
			if(sum > diff) --k;
			if(sum < diff) ++j;
			if(sum == diff){
				++count;
				break;
			}
		}
	}
	cout<<count;
	return count;
}