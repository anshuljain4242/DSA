#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int kthSmallest(int arr[], int l, int r, int k)
{

    priority_queue<int> pq;

    // Step1 - push first k elements in maxheap
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    // Step 2 - compare the rest of the elements with pq.top(). if small then pop and push
    int i = k;
    while (i <= r)
    {
        if (arr[i] < pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
        i++;
    }
    // Step 3 - pq.top() will be the kth smallest element
    return pq.top();
}