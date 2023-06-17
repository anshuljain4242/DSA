#include<iostream>
#include<deque>
#include<vector>

using namespace std;

vector<int> slidingMaximum(vector<int>& nums, int k) {
    deque<int> dq;
    vector<int> ans;


    for(int i=0;i<nums.size();i++){
        //checking that if your maximum element is the one you want to remove from the window
        if(!dq.empty() && dq.front() == i-k){
            dq.pop_front();
        }
        //to maintain the decreasing order of the deque
        while(!dq.empty() && nums[dq.back()] < nums[i])
            dq.pop_back();

        //pushing i in deque
        dq.push_back(i);

        // if reached window size, then push the first element of the deque(would be maximum), to the ans.
        if(i >= k-1)
            ans.push_back(nums[dq.front()]);
      
    }
    return ans;
}

int main(){
    vector<int> A;
    vector<int> ans;
    int a;
    int n;
    cout<<"Enter n- ";
    cin>>n;
    int B = 3;
    for(int i=0;i<n;i++){
        cin>>a;
        A.push_back(a);
    }
    ans = slidingMaximum(A,B);
    for(int i=0;i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}