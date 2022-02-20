#include"SortingAlgorithms.cpp"
using namespace std;

int main() {
	vector<int> arr = {4,3,2,7,5,0,10,23,1,2};
	//selection_sorter(arr);
	//cout<<endl;
	//bubble_sort(arr);
    //cout<<endl;
    vector<int> arr2 = arr;
    //bubble_recursive(arr2, arr.size());
    //printing(arr2);
    arr2 =arr;
    //insertion_sort(arr);
    //insertion_recursion(arr2, arr2.size(), 1);
    //printing(arr2);
    arr2 = arr;
    mergesort(arr2, 0, arr2.size()-1);
    printing(arr2);
	return 0;
}