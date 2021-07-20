#include<bits/stdc++.h>

using namespace std;

//Brute Force approach!
/*
int main(){
    vector<int> chocolate = { 3, 3, 3 };
    vector<string> query= {"1-3-3", "2-2-3"};

    vector<int> ans;
    map<int, int> calc;
    for(int i =0; i< query.size(); i++){
        int j = (int)query[i][0]-49, n =(int)query[i][2]-49, element = (int)query[i][4]-48;
        cout<<j<<" "<<n<<" "<<element<<endl;

        calc.insert({element, 0});
        for(j; j<=n; j++){
            if(chocolate[j] == element) ++calc[element];
        }

        cout<<"the no of "<<element<<" in the interval is: "<<calc[element]<<endl;
        ans.push_back(calc[element]);
        calc[element] = 0;
    }

    return 0;
}
*/

int main(){
    vector<int> arr = {1, 2, 3};
    vector<string> queries = {"1-3-3", "2-2-1"};
    map<int, vector<int>> collection;

    for(int i =0; i<arr.size(); i++){
        collection[arr[i]].push_back(i+1);
    }

    vector<int> ans;

    for(int i = 0; i<queries.size(); i++){
        int low = (int)queries[i][0]-48, high = (int)queries[i][2]-48, element = (int)queries[i][4]-48;
        cout<<low<<" "<<high<<" "<<element<<endl;
        int up = upper_bound(collection[element].begin(), collection[element].end(), high) - collection[element].begin();
        int lw = lower_bound(collection[element].begin(), collection[element].end(), low) - collection[element].begin();
        cout<<up-lw<<endl;
        ans.push_back(up-lw);
    }
}