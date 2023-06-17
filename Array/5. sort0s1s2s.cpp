#include<iostream>
using namespace std;

/*
Brute force - using sorting algorithm(merge sort)
TC - O(nlogn)
SC - O(n)

Better - using 3 variables, as we sure shot know that there are only 3 nos in the array
TC - O(2n) -> Double iteration
SC - O(1)

Optimal - Dutch National Flag Algorithm(3 Pointers) -> Single iteration
TC - O(n)
SC - O(1)
*/


void sort012(int *arr, int n)
{
//    int count0 = 0, count1 = 0, count2 = 0, i;

//    for(int i=0; i<n; i++)
//    {
//     if(arr[i] == 0)
//         count0++;
//     else if(arr[i] == 1)
//         count1++;
//     else if(arr[i] == 2)
//         count2++;        
//    }
//     for(i=0; i<count0; i++)
//         arr[i] = 0;

//     for(i = count0; i<count0+count1; i++)
//         arr[i] = 1;

//     for(i = count0+count1; i<n; i++)
//         arr[i]  =2; 

    int low=0, mid=0, high=n-1;

    while(mid <= high)
    {
        if(arr[mid] == 0)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1)
        {
            mid++;
        }
        else if(arr[mid] == 2)
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
   
}

int main()
{
    int arr[7] = {0,1,2,1,2,1,2};
    int n= 7;
    sort012(arr,n);

    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

}