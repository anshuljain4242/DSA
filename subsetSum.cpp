#include<iostream>
#include<vector>
using namespace std;
// Sum of all the subsets of an array
void getSum(int idx, int sum, vector<int>& ds, vector<int>& arr, int N)
    {
        if(idx == N){
            ds.push_back(sum);
            return;
        }
        
        getSum(idx+1, sum+arr[idx], ds, arr, N);
        getSum(idx+1, sum, ds, arr, N);
    }
vector<int> subsetSums(vector<int> arr, int N)
{
        vector<int> ds;
        int sum = 0;
        getSum(0,sum,ds,arr,N);
        sort(ds.begin(),ds.end());
        return ds;      
}

int main(){
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(4);
    int N = 4;
    
    vector<int> ans;
    ans = subsetSums(arr,N);
    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}