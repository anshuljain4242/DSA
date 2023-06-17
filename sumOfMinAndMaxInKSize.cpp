#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int solve(int arr[], int n, int k){
    deque<int> maxi;
    deque<int> mini;
    int sum = 0;
    for(int i=0; i<n; i++){
        
        //checking that if your max or min element(index) is the one you want to remove from the window
        if(!maxi.empty() && maxi.front() == i-k)
            maxi.pop_front();
        if(!mini.empty() && mini.front() == i-k)
            mini.pop_front();

        //maintaining the decreasing order or maxi deque
        while(!maxi.empty() && arr[maxi.back()] < arr[i]){
            maxi.pop_back();
        }  
        //maintaining the increasing order or mini deque 
        while(!mini.empty() && arr[mini.back()] > arr[i]){
            mini.pop_back();
        }

        maxi.push_back(i);
        mini.push_back(i);
        
        //calculation of sum
        if(i >= k-1){
            sum += arr[maxi.front()] + arr[mini.front()];     
        }
    }
    return sum;
}

int main(){
    int arr[] = {2,5,-1,7,-3,-1,-2};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    vector<int> ans;
    cout << solve(arr,n,k) << endl;
    
    cout<<endl;

    return 0;

}