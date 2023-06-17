#include<iostream>
#include<vector>
using namespace std;

// Brute force : TC -> O(n^2)
int inversionCount(int arr[10], int n)
{
    int count=0;
    for(int i=0; i<n; i++){
        int j=i+1;
        while(j<n){
            if((arr[i] <= arr[j]) && (i<j)){
                j++;
            }
            else{
                swap(arr[i],arr[j]);
                count++;
            }
        }
    }
    return count;
}
//  Optimal
long long merge(long long *arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid+1;
    long long cnt = 0;
    while(left <= mid && right <= high)
    {
        if(arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        // right is smaller
        else{
            temp.push_back(arr[right]);
            cnt += mid - left + 1;
            right++;
        }
    }

    while(left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while(right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // changing the array, it not allowed -> maintain a copy of the array
    for(int i = low; i <= high; i++)
    {
        arr[i] = temp[i-low];
    }   
    return cnt; 
}

long long mergeSort(long long *arr, int low, int high)
{
    long long cnt = 0;
    if(low >= high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid+1, high);
    cnt += merge(arr, low, mid, high); 
    return cnt;   
}

long long getInversions(long long *arr, int n)
{
    return mergeSort(arr, 0, n-1);
}

int main(){
    long long arr[5] = {2,5,1,3,4};
    int n = 5; 
    // cout<<inversionCount(arr,n);
    cout << getInversions(arr, 5);
}