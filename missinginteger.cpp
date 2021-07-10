#include<bits/stdc++.h>


using namespace std;
/*
int main()
{
    vector<int> arr = {1, 2, 3, 5, 6, 8, 7, 10, 11, 9};

    int n = arr.size() + 1;
    int sum = n*(n+1)/2;
    // Sum of n+1 integers method.
    //cout<<sum<<endl<<sum1;
    for(int i = 0; i<n-1; i++){
        sum -= arr[i];
    }

    cout<<sum<<endl;

    //marking the integers as negative method.
    int i = 0;
    while(i<n-1){
        if ( arr[abs(arr[i])]-1 >= (n-1));
        else arr[abs(arr[i])-1] = arr[abs(arr[i])-1] * (-1);

        ++i;
    }

    for ( i = 0; i<n-1; i++){
        if ( arr[i] > 0) break;
    }
    cout<<arr[i]-1<<endl;
}*/

int A[2];
int *findTwoElement(int *arr, int n) {
    // code here
    int repeat = 0, miss;
    for(int i =0; i<n; i++){
        //cout<<arr[i]<<endl;
        repeat = repeat ^ abs(arr[i]);  
        cout<<repeat<<endl;     
        if((abs(arr[i])-1) <n){
            arr[abs(arr[i])-1] = (-1)*abs(arr[abs(arr[i])-1]);
        }
    }
cout<<"--------------------"<<repeat<<"------------"<<endl;

    
    for(int i =0; i<n; i++){
        //cout<<arr[i]<<endl;
        if(arr[i] > 0){
            miss = i+1;
        }
    }
    repeat ^= miss;
cout<<"--------------------"<<repeat<<"------------"<<endl;

    for(int i =1; i<=n; i++){
        repeat = repeat ^ i;
        cout<<repeat<<endl;
    }
    A[0]=repeat;
    A[1]= miss;

    return A;
}
int main()
{   
    int arr[] = {2, 1, 3, 3, 5}, n = 5;

    int *ptr = NULL;
   // ptr = malloc(sizeof(arr));
    ptr = findTwoElement(arr, 2);

//     for ( int i = 0; i < n; i++ ) {
//       printf( "*(ptr + %d) : %d\n", i, *(ptr + i));
//    }
    cout<<ptr[0]<<endl<<ptr[1];
}