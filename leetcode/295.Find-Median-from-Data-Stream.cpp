/**
 * @file 295. Find Median from Data Stream
 * @author Dhairya Varshney
 * @brief 
 * @version 0.1
 * @date 2022-01-19
 * @link https://leetcode.com/problems/find-median-from-data-stream/ @endlink
 * @copyright Copyright (c) 2022
 * 
 */
/*
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.
 

Example 1:

Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
 

Constraints:

-10^5 <= num <= 10^5
There will be at least one element in the data structure before calling findMedian.
At most 5 * 104 calls will be made to addNum and findMedian.
 

Follow up:

If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
*/

/*
Test Cases
["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"]
[[],[1],[2],[],[3],[]]
["MedianFinder","addNum","addNum","findMedian","addNum","findMedian","addNum","addNum","findMedian","addNum","findMedian"]
[[],[87],[95],[],[71],[],[130],[1],[],[100],[]]
["MedianFinder","addNum","addNum","findMedian"]
[[],[0],[0],[]]
*/

//Gave TLE. Both Operations in O(N) worst case.
class MedianFinder {
public:
    ListNode * head, * tail;
    MedianFinder() {
        head = tail = nullptr;
    }
    
    void addNum(int num) {
        ListNode * newnode = new ListNode(num);
        if(!head){
            head = tail = newnode;
            return;
        }
        if(num <= head->val){
            newnode->next = head;
            head = newnode;
        }
        else if(num >= tail->val){
            tail->next = newnode;
            tail = newnode;
        }
        else{
            ListNode* trav = head;
            while(trav != NULL && num > trav->next->val){
                trav = trav->next;
            }
            newnode->next = trav->next;
            trav->next = newnode;
        }
    }
    
    void printing(){
        ListNode*trav = head;
        while(trav){
            cout<<trav->val<<" ";
            trav = trav->next;
        }
    }
    
    double findMedian() {
        printing();
        cout<<endl;
        if(head == tail || head->next == tail){
            return (double)(head->val+tail->val)/(double)2;
        }
        ListNode * rabbit = head, *turtle = head;
        double median = 0;
        while(rabbit && turtle && rabbit->next && rabbit->next->next){
            rabbit = rabbit->next->next,
            turtle = turtle->next;
        }
        if(rabbit->next){
            median = (double)(turtle->val + turtle->next->val)/(double)(2);
        }
        else{
            median = turtle->val;
        }
        return median;
    }
};

//Optimized Solution. Addnum funct - O(Logn), Delete Num - O(1)
class MedianFinder {
public:
    priority_queue<int> firstq;
    priority_queue<int, vector<int>, greater<int> > secq;
    MedianFinder() {
        firstq = priority_queue<int>();
        secq = priority_queue<int, vector<int>, greater<int> >();
    }
    
    void addNum(int num) {
        if(firstq.empty() || num < firstq.top()){
            firstq.push(num);
        }
        else{
            secq.push(num);
        }
        
        if(firstq.size() > secq.size()+1){
            secq.push(firstq.top()), firstq.pop();
        }
        else if(secq.size() > firstq.size()+1){
            firstq.push(secq.top()), secq.pop();
        }
    }
    
    double findMedian() {
        if(firstq.size() == secq.size()){
            return firstq.size() == 0? 0:(double)(firstq.top() + secq.top())/2;
        }
        else{
            return firstq.size()>secq.size()?firstq.top():secq.top();
        }
    }
};


