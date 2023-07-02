#include <iostream>
#include<queue>
using namespace std;

class heap
{
public:
    int arr[100];
    int size = 0;

    void insert(int val)
    {
        size = size + 1;
        int idx = size;
        arr[idx] = val;

        while (idx > 1)
        {
            int parent = idx / 2;
            if (arr[idx] > arr[parent])
            {
                swap(arr[idx], arr[parent]);
                idx = parent;
            }
            else
                return;
        }
    }

    void deletion()
    {
        if(size == 0){
            cout <<"Nothing to delete!" << endl;
            return;
        }
            
        arr[1] = arr[size];
        size--;

        // take root node to its correct position
        int i = 1;
        while(i < size)
        {
            int leftidx = 2*i;
            int rightidx = 2*i+1;
            if(arr[i] < arr[leftidx] && leftidx < size)
            {
                swap(arr[i], arr[leftidx]);
                i = leftidx;
            }    
            else if(arr[i] < arr[rightidx] && rightidx < size)  
            {
                swap(arr[i], arr[rightidx]);
                i = rightidx;
            }  
            else    
                return;
        }

    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int size, int i)
{
    int largest = i;
    int leftChild = 2*i;
    int rightChild = 2*i+1;

    if(leftChild <= size && arr[largest] < arr[leftChild])
        largest = leftChild;
    if(rightChild <= size && arr[largest] < arr[rightChild])
        largest = rightChild;

    if(largest != i){
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }
                
}

void heapsort(int arr[], int n)
{
    int size = n;
    while(size > 1)
    {
        swap(arr[1], arr[size]);
        size--;

        heapify(arr, size, 1);
    }
}

int main()
{
    heap h;
    // h.insert(5);
    // h.insert(10);
    // h.insert(3);
    // h.insert(9);
    // h.insert(14);
    // h.deletion();
    // h.print();

    int arr[6] = {-1, 5, 10, 3, 9 ,14};
    int n = 5;
    // create heap
    for(int i = n/2; i>0; i--)
    {
        heapify(arr,n,i);
    }
    cout<<"Heap array - " << endl;
    for(int i=1; i<=n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapsort(arr,n);
    cout<<"Sorted heap array - " << endl;
    for(int i=1; i<=n; i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<"Using priority queue here - "<<endl; 

    // maxheap
    priority_queue<int> pq;
    pq.push(5);
    pq.push(7);
    pq.push(2);
    pq.push(1);
    pq.push(6);

    cout<<"Element at top of maxheap - "<<pq.top()<<endl;
    pq.pop();
    cout<<"Element at top of maxheap - "<<pq.top()<<endl;

    // minheap
    priority_queue<int, vector<int>, greater<int> > minheap;
    minheap.push(5);
    minheap.push(7);
    minheap.push(2);
    minheap.push(1);
    minheap.push(6);

    cout<<"Element at top of minheap - "<<minheap.top()<<endl;
    minheap.pop();
    cout<<"Element at top of minheap - "<<minheap.top()<<endl;
}   