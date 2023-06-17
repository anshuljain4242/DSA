#include <iostream>
#include <map>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    // Optimal : TC -> O(n), SC -> O(n)

    map<char,int> m;
    int l=0, r=0;
    int maxLen = 0;

    while(r<s.length())
    {
        
        if(m.find(s[r]) != m.end())
        {
            l = max(l,m[s[r]] + 1);
        }
        m[s[r]] = r;
        maxLen = max(maxLen, r-l+1);
        r++;
    }
    return maxLen;


    // Better : TC -> O(2N), SC -> O(N)
    /*
    map<char, int> mp;
    int maxLen = 0;
    int i = 0, j = 0;
    while (j < s.length())
    {
        mp[s[j]]++;
        if(mp.size() < j-i+1){
            while(mp.size() < j-i+1){
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
        else if(mp.size() == j-i+1){
            maxLen = max(maxLen,j-i+1);
            j++;
        }
        
    }
    return maxLen;
    */
    
}

int main()
{
    string s = "abcabcbb";
    int ans = lengthOfLongestSubstring(s);
    cout << ans;
    return 0;
}