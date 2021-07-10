#include<bits/stdc++.h>

using namespace std;
int f1(){
    return 1;
}/*
int main()
{
    vector <int> prices = {2,4,1};//{900,510,174,329,873,382,279,855,396,810,322,192,442,775,445,861,303,975,478,543,87,875,283,740,376,156,521,462,987,683,462,792,491,641,359,423,795,459,503,443,935,940,120,579,945,916,509,513,964,666,812,244,565,896,174,546,837,383,961,0,486,221,770,595,65,222,576,224,566,916,249,70,101,155,2,879,972,390,420,267,221,879,719,329,845,831,836,617,534,979,761,590,346,866,947,838,96,430,137,370,870,261,923,388,405,438,163,250,625,552,158,916,711,384,361,382,862,321,607,493,850,22,802,261,254,484,221,535,449,143,43,982,631,844,343,280,214,595,151,646,522,463,890,759,237,796,231,617,298,178,264,489,655,645,188,180,443,772,503,376,471,741,660,710,877,206,807,230,743,168,336,10,675,152,223,828,183,323,914,305,612,922,608,670,803,744,539,978,899,309,696,579,209,884,821,690,245,165,945,262,90,732,746,190,160,559,463,414,339,900,198,285,514,421,221,408,237,597,35,802,898,217,97,78,839,609,762,387,542,678,641,381,762,130,115,424,162,258,785,958,607,499,534,643,935,866,104,123,463,749,473,669,363,11};//{7,1,5,3,6,4};
    // int MIN = *min_element(prices.begin(), prices.end());
    // // cout<<MAX<<"  "<<MIN<<endl;
    // if(MIN == prices[prices.size()-1]){
    //     return 0;
    // }

    // int MAX;
    // int max_ind, min_ind;
    // for ( int i = 0; i<prices.size(); i++){
    //     if(prices[i] == MIN) {min_ind = i;}
    // }
    // MAX = MIN;
    // for (int i = min_ind; i< prices.size(); i++){
    //     if(MAX < prices[i]) {
    //         MAX = prices[i];
    //         max_ind = i;
    //     }
    // }

    // //cout<<max_ind<<"  "<<min_ind<<endl;
    // if(min_ind < max_ind) cout<<MAX-MIN;
    // else cout<<0;
    // return 0;
    /*int ans = 0, n = prices.size();
    for(int i = 0; i<n-1; i++){
        int diff = 0;
        for(int j = i+1; j<n; j++ ){
            diff = max(diff, prices[j] - prices[i]);

        }

        ans = max(ans, diff);
    }
    cout<<ans<<endl;

    return ans;*/
/*
    int i = 0, j = prices.size()-1, diff = 0;
    for(i, j; i<j; i++, j--){
        diff = max(diff, prices[j] - prices[i]);
    }
    //cout<<diff<<endl;
    return diff;

    int MIN = *min_element(prices.begin(), prices.end());
    int n = prices.size(), MAX = prices[n-1], diff= 0;
    for(int i = n-2; i>=0; i--){
        if(prices[i]>MAX){
            MAX = prices[i];
            diff = max(diff, 0);
        }
        else{
            diff = max(diff, MAX-prices[i]);
        }

    }
    cout<<diff<<endl;
    return diff;

}*/