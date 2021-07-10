#include<bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> arr = {1, 2, 2, 9, 9, 3, 5};

    //Brute Force Method
    int m = arr[0];
    int flag = 0;

    map<int, int> map1;

    for(int i =0; i<arr.size(); i++){
        cout<<arr[i]<<endl;
        m = max(m, arr[i]);
        ++map1[arr[i]];
    }

    for (map<int, int>::iterator itr = map1.begin(); itr != map1.end(); itr++){
        cout<<itr->first<<"  "<<itr->second<<endl;
    }
    cout<<m<<" "<<map1[m]<<endl;
    if (map1[m] > 1){
        cout<<"No Peak Element."<<endl;
    }
    else{
        cout<<"The Peak Element is: "<<m<<endl;
    }
    map<int,int>::iterator itr;
    itr = map1.begin();
    for (map<int, int>::iterator itr = map1.begin(); itr != map1.end(); itr++){
        cout<<itr->first<<"  "<<itr->second<<endl;
    }
}

    //double pointer approach.
/*
checck if ith or jth element =  temp, if yes, count++;
if its for the first time to count ki value 1 kardo.
*/
/*
    int temp = INT_MIN, count = 0;
    int i =0, j = arr.size()-1;

    while(i<j){
        
        if(arr[i] > temp && arr[i] > arr[j]){
            count = 1;
            temp = arr[i];
            ++i;
        }

        else if ( arr[j] > temp && arr[j] > arr[i]){
            count = 1;
            temp = arr[j];
            --j;
        }
        
        else if(arr[i] == arr[j] && arr[i] > temp){
            temp = arr[i];
            ++count;
            ++i; --j;
        }

        else if(arr[i] == temp){
            ++count;
            ++i;
        }

        else if(arr[j] == temp){
            ++count;
            --j;
        }
        else{
            ++i;
        }

    }
    if (count == 1){
        cout<<" the peak is : "<<temp;
    }
    else cout<<"No Peak!."<<endl;

}
*/