#include<bits/stdc++.h>

using namespace std;

bool checking(string s){
    if(s.front() == '0') return false;
    
    int temp = stoi(s);
    if(temp>26) return false;
    else return true;
}

int main(){
	map <string, int> list;
    string s = "27";
    int ans = 0;
    
    if(s.front() == '0') {
		ans = 0;
		cout<<ans;
		return 0;
	}

    else{
        string temp = "";
        temp += s.front();
        list.insert({temp, 1});
    }
    
    int n = s.length();
    
    if(n>1){
        string firstwo = s.substr(0, 2);
        int num = stoi(firstwo);
        if(num>26) {
			if(num%10 == 0) list[firstwo] = 0;
			else list[firstwo] = 1;
		}
		else{
			if(num%10 == 0) list[firstwo] = 1;
			else list[firstwo] = 2;
		}
    }
    for(int i = 3; i<=n; i++){
        string temp1 = s.substr(0, i-2);
        string temp2 = s.substr(i-2, 2);
        string temp3 = s.substr(0, i-1);
        string temp4 = s.substr(i-1, 1);
        
        bool check1 = checking(temp2);
        bool check2 = checking(temp4);
        //cout<<temp2<<" "<<check1<<endl;
		//cout<<temp4<<" "<<check2<<endl;

        string inst = s.substr(0, i);
        list[inst] = 0;
        if(check1) list[inst] += list[temp1];
        if(check2) list[inst] += list[temp3];
		//cout<<inst<<" list value: "<<list[inst]<<endl;
    }
    cout<<list[s]<<endl;
    return list[s];
}