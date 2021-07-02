//distinct substring

#include<bits/stdc++.h>

using namespace std;

int main()
{
    string sample = "abcbadbbaac";
    int k = 4, n = sample.length();

    map<char, int> window;

    vector< pair<string, int>> collect;

    for(int i = 0; i< k; i++){
        ++window[sample[i]];
    }

    map<char,int>::iterator itr = window.begin();
    while(itr != window.end()){
        printf("%c: %i  ", itr->first, itr->second);
        ++itr;
    }
    cout<<window.size()<<endl;
    
    collect.push_back(make_pair(sample.substr(0, k), window.size()));
    int i = 0, j = k, storing = window.size();
    while(j != n){


        ++window[sample[j]];
        --window[sample[i]];
        if(!window[sample[i]]) window.erase(sample[i]);
        ++i;
        ++j;
        int map_size = window.size();
        collect.push_back(make_pair(sample.substr(i, k), map_size));

        itr = window.begin();
        while(itr != window.end()){
            printf("%c: %i  ", itr->first, itr->second);
            ++itr;
        }

        storing = max(storing, map_size);
        cout<<window.size()<<endl;

        cout<<endl;
    }

    for(i = 0; i<n; i++){
        if(collect[i].second == storing){
            cout<<collect[i].first<<": "<<collect[i].second<<endl;
            break;
        }
    }

    // itr = window.begin();
    // while(itr != window.end()){
    //     printf("%c", itr->first);
    //     ++itr;
    // }
}