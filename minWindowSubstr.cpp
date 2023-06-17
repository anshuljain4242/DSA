/*
Given two strings s and t of lengths m and n respectively, return the minimum window 
substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
*/

#include<iostream>
#include<map>
#include <string>
using namespace std;

string minWindow(string s, string t){

    if(s.length() == 0 || s.length() < t.length())
        return "";
    map<char,int> mp;
    for(int i=0; i<t.length(); i++){
        mp[t[i]]++;
    }

    int count = mp.size();
    int minLen = INT_MAX;
    string ans;
    int i=0, j=0;

    while(j < s.length())
    {   
        if(mp.find(s[j]) == mp.end()){
            j++;
            continue;
        }
        else if(mp.find(s[j]) != mp.end()){
            mp[s[j]]--;
            if(mp[s[j]]==0)
                count--;
        }
        
        if(count == 0){
            if(minLen > j-i+1)
                ans = s.substr(i,j-i+1);
                minLen = min(minLen, j-i+1);

            while(count == 0){
                if(mp.find(s[i]) == mp.end())
                    i++;
                else{
                    if(mp[s[i]] == 0){
                        minLen = min(minLen, j-i+1);
                    }
                    mp[s[i]]++;
                    if(mp[s[i]] > 0)
                        count++;
                    i++;
                }
                if(count == 0){
                    if(minLen > j-i+1){
                        ans = s.substr(i,j-i+1);
                        minLen = j-i+1;
                    }
                } 
            }
        }
        j++;   
    }    
    return ans;
}

int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string ans = minWindow(s,t);
    cout<<ans<<endl;
    return 0;
}