#include<iostream>
#include<vector>

using namespace std;

// int f(int n, vector<int>& dp){
//     if(n <= 1)
//         return n;

//     if(dp[n] != -1)
//         return dp[n];

//     return dp[n] = f(n-1, dp) + f(n-2, dp);        
// }

// int main(){
//     int n;
//     cin>>n;
//     vector<int> dp(n+1,-1);
//     cout << f(n,dp) << endl;
//     return 0;
// }

int main(){
    int n;
    cin >> n;

    int prev2 = 0;
    int prev1 = 1;

    for(int i=2; i<=n; i++){
        int curr = prev2 + prev1;
        prev2 = prev1;
        prev1 = curr;
    }

    cout<<"nth fibonacci number is : "<< prev1 <<endl;
    return 0;
}
