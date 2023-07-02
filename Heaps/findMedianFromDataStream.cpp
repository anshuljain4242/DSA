#include <iostream>
#include <queue>
using namespace std;


/*
The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value, and the 
median is the mean of the two middle values.

For example, for arr = [2,3,4], the median is 3.
For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
Implement the MedianFinder class:

MedianFinder() initializes the MedianFinder object.
void addNum(int num) adds the integer num from the data stream to the data structure.
double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.

*/

class MedianFinder {
public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int> > minHeap;
    int size;
    MedianFinder() {
        size = 0;
    }
    
    void addNum(int num) {
        if(size == 0)
        {
            maxHeap.push(num);
            size++;
        }
        // push num to right side so as to maintain the diff
        else if(maxHeap.size() > minHeap.size())
        {
            if(num < maxHeap.top())
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(num);
            }
            else
                minHeap.push(num);
        }
        // both are of same size
        else{
            
            if(num > minHeap.top())
            {
                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(num);
            }
            else
                maxHeap.push(num);
        }
    }
    
    double findMedian() {
        if(maxHeap.size() > minHeap.size())
            return maxHeap.top();   
        else
            return (maxHeap.top() + minHeap.top())/2.0;   
    }
};