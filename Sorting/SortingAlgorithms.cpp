#include<bits/stdc++.h>

using namespace std;

#include <bits/stdc++.h>
using namespace std;

/**Selection sort is the basic sorting algorithm and one of the worst sorting algorithm
 * where we find the element smaller than the ith element in the i+1 ... n elements, and swap
 * it with the ith element. The TC is O(N^2) in all cases.
 * Best Case: The array is sorted. TC - O(N^2)
 * Worst Case: The array is sorted in descending order - O(N^2)
**/
void selection_sorter(vector<int> arr){
	int n = arr.size();
	for(int i = 0; i<n; i++){
		for(int j = i+1; j<n; j++){
			if(arr[i]>arr[j]){
				swap(arr[i], arr[j]);
			}
		}
	}
	for(int i : arr){
		cout<<i<<" ";
	}
	return;
}

/**Bubble Sort is another sorting algorithm where we observe the consective pair elements 
 * and compare the. if the premier one is greater then we swap it and move ahead.
 * at the end of one round of comparing and swapping whenever we have to, the
 * greatest element in the array gets to the end. 
 * In the second iteration, the 2nd largest element reaches the 2nd last position.
 * This takes place N times.
 * Best Case: Sorted array - O(N^2)
 * Worst Case : Descending Order -  O(N^2)
 **/ 
void bubble_sort(vector<int> arr){
	int n = arr.size(), swaps = 0;
	for(int c=0; c<n; c++){
		for(int i = 0; i<n-1; i++){
			if(arr[i] > arr[i+1]){
				swap(arr[i], arr[i+1]);
				++swaps;
			}
		}
	}
	for(int i : arr){
		cout<<i<<" ";
	}
	//cout<<swaps<<endl;
}

void bubble_recursive(vector<int> & arr, int n){
    if(n==1){
        return;
    }
    for(int i = 0; i<n-1; i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i], arr[i+1]);
        }
    }

    bubble_recursive(arr, n-1);
}

/**Insertion Sort is another array sorting algorithm where we keep the sorted and unsorted part
 * in the array as seperate. The 1st part is sorted and the remaining part is unsorted.
 * As we traverse throught the unsorted part, the element is swapped one by one with its previous 
 * elements to reach the right place in sorted array. By this way, we sort the array.
 **/
void insertion_sort(vector<int> arr){
    int n = arr.size();
    for(int i =1; i<n; i++){
        int j = i;
        while(j>0 and arr[j]<arr[j-1]){
            swap(arr[j], arr[j-1]);
            --j;
        }
    }

    for(int i: arr){
        cout<<i<<" ";
    }
}

void insertion_recursion(vector<int> &arr, int n, int i){
    if(i == n){
        return;
    }

    for(int j = i; j>0 and arr[j]<arr[j-1]; j--){
        swap(arr[j], arr[j-1]);
    }
    insertion_recursion(arr, n, i+1);
}

/**Merge Sort is a sorting algorithm based on Divide and Conquer approach, where we virtually 
 * divide the given array into halves until only one element is left in the array. After that,
 * we start mergibng the already divided fragments into a sorted array.
 * Internally, we take the help of an extra array(extra space) that makes this algorithm 
 * have a higher space complexity than the ordinary sorting algorithms.
**/
void final_merging(vector<int> & arr, int start, int mid, int end);
void merge_sort(vector<int> &arr, int start, int end){
    if(start>end){
        int  mid = (start+end)/2;
        merge_sort(arr, start, mid-1);
        merge_sort(arr, mid, end);
        final_merging(arr, start, mid, end);
    }
}

void final_merging(vector<int>& arr, int start, int mid, int end){
    vector<int> temp;
    int i = start, j = mid;
    while(i<mid and j<=end){
        temp.push_back(arr[i]<arr[j]?arr[i++]:arr[j++]);
    }
    while(i<mid){
        temp.push_back(arr[i++]);
    }
    while(j<=end){
        temp.push_back(arr[j++]);
    }
    for(i = end; i>=start; i--){
        arr[i] = temp.back(), temp.pop_back();
    }
}

void printing(vector<int> arr){
    for(auto i: arr){
        cout<<i<<" ";
    }
    cout<<endl;
}
