#include<bits/stdc++.h>

using namespace std;

map<string, vector<string>> graph;
map<string, bool> statuslist;

bool checkbyone(string s1, string s2){
    if(s1 == s2) return false;
    int count = 0;

    int n1= s1.length(), n2 = s2.length();
    if(n1 != n2) return false;

    for(int i =0; i<n1; i++){
        if(s1[i] != s2[i]) ++count;
        if(count ==2) return false;
    }
    return true;
}

void addedge(string s1, string s2){
    graph[s1].push_back(s2);
    //graph[s2].push_back(s1);
}

void makinggraph(vector<string> arr){
    int n = arr.size();
    for(int i =0; i<n ; i++){
        statuslist[arr[i]] = false;
        for(int j = 0;j<n; j++){
            if(checkbyone(arr[i], arr[j])){
                addedge(arr[i], arr[j]);
            }
        }
    }
}

void printing(){
    for(auto itr : graph){
        cout<<itr.first<<" -> ";
        int n = itr.second.size();
        for(int i =0 ;i <n; i++){
            cout<<itr.second[i]<<", ";
        }
        cout<<endl;
    }
}

void bfs(string start, string target){
    queue<string> traversal;
    traversal.push(start);
    statuslist[start] = true;
    int count = 1;
    while(!traversal.empty()){
        string vertex = traversal.front();
        statuslist[vertex] = true;
        for(int i =0; i<graph[vertex].size(); i++){
            string temp = graph[vertex][i];
            if(!statuslist[temp]){
                statuslist[temp] = true;
                traversal.push(temp);
                if(temp == target) {
                    break;
                }
            }
        }
        traversal.pop();
        ++count;
        string end = traversal.back();
        if(end == target) break;
    }
    cout<<count<<endl;

}

int main(){
    vector<string> dictionary = {"toon", "poon", "plee", "same", "poie", "plea", "plie", "poin"};
    string start = "toon", target = "plea";
    makinggraph(dictionary);
    printing();
    bfs(start, target);
    return 0;
}