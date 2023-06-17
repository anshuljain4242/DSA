#include<iostream>
#include<map>
#include<vector>
using namespace std;

int longestSubarrayWithSumK(vector<int> a, long long k) {
    // map<long long, int> mp;
    // long long sum = 0;
    // int maxlen = 0;
    
    // for(int i=0; i<a.size(); i++){
    //     sum += a[i];
    //     if(sum == k){
    //         maxlen = max(maxlen, i+1);
    //     }
    //     if(mp.find(sum-k) != mp.end()){
    //         maxlen = max(maxlen,i-mp[sum-k]);
    //     }
    //     // if the sum was not already there in the map, then only add it.
    //     if(mp.find(sum) == mp.end()){ 
    //         mp[sum] = i; 
    //     }
        
    // }
    // return maxlen; 

    long long sum = a[0];
    int maxlen = 0;
    int i=0, j=0; 

    while(j<a.size()){
        if(i<=j && sum > k){
            sum = sum-a[i];
            i++;    
        }
        if(sum == k){
            maxlen = max(maxlen, j-i+1);
        }
        j++;
        if(j<a.size())
            sum += a[j];
    
    }
    return maxlen;
}

int main(){
    vector<int> a;
    int ans;
    int num;
    long long n;
    cout<<"Enter n- ";
    cin>>n;
    long long k;
    cout<<"Enter sum- ";
    cin>>k;
    for(int i=0;i<n;i++){
        cin>>num;
        a.push_back(num);
    }
    ans = longestSubarrayWithSumK(a,k);
    cout<<"Longest subarray with sum K is- "<<ans;
    return 0;
}