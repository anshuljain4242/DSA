#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<int> firstNegative(vector<int> arr, int n, int k){
    list<int> negative;
    vector<int> ans;
    int i=0,j=0;
    int FN;

    while(j<n){
        
        if(arr[j]<0){
            FN = arr[j];
            negative.push_back(FN);
        }
        
        if(j-i+1 < k)
            j++;
        else if(j-i+1 == k){
            if(negative.size() == 0){
                ans.push_back(0);
            }
            else{
                ans.push_back(negative.front());
                if(arr[i] == negative.front()){
                    negative.pop_front();
                }
                
            }
            
            i++;
            j++;
        }    
    }
    return ans;
}

int main(){
    
    vector<int> arr;
    int a;
    int n = 8;
    vector<int> ans;
    for(int i=0;i<n;i++){
        cin>>a;
        arr.push_back(a);
    }
    int k=2;
    
    ans = firstNegative(arr,n,k);

    for(int i=0;i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}