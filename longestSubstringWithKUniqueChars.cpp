/*
Input:
S = "aabacbebebe", K = 3
Output: 7
*/

#include<iostream>
#include<map>
using namespace std;

int longestKSubstr(string s, int k) {
    map<char,int> mp;
    int maxLen=INT_MIN;
    //j will acquire the next char and i will release the early char.
    int j=0, i=0;

    while(j < s.length()){
    
        mp[s[j]]++;
        
        if(mp.size()>k){
            while(mp.size()>k){
                mp[s[i]]--;
                if(mp[s[i]]==0)
                    mp.erase(s[i]);
                i++;    
            }
            j++;
        }    
        else if(mp.size() == k){
            maxLen = max(maxLen, j-i+1);
            j++;
        }
        else if(mp.size()<k){
            j++;
        }
    }
    if(mp.size()!=k)
        return -1;
    return maxLen;
}
 
int main(){
    string s = "aabcbcdbcs";
    int k = 2;
    int ans = longestKSubstr(s,k);
    cout<<ans;

    return 0;
}