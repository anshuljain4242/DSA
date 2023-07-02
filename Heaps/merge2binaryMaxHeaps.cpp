#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    
    void heapify(vector<int>& c, int size, int i)
{
    int largest = i;
    int leftChild = 2*i+1;
    int rightChild = 2*i+2;

    if(leftChild < size && c[largest] < c[leftChild])
        largest = leftChild;
    if(rightChild < size && c[largest] < c[rightChild])
        largest = rightChild;

    if(largest != i){
        swap(c[largest], c[i]);
        heapify(c, size, largest);
    }
                
}
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        
        // Step1 : merge the 2 arrays into one 
        vector<int> c;
        for(auto i:a)
            c.push_back(i);
        for(auto i:b)
            c.push_back(i);  
            
        int size = c.size();
        for(int i=size/2 - 1; i>=0; i--)
        {
            heapify(c,c.size(),i);
        }
        
        return c;
    }
};