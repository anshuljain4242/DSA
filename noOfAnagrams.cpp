#include<iostream>
#include<map>
using namespace std;

int searchAnagrams(string pat, string txt){
    map<char, int> mp;
    for(int i=0; i<pat.length();i++){
        mp[pat[i]]++;
    }
    int count = mp.size();
    int ans = 0, i=0, j=0, k=pat.length();

    while(j<txt.length()){
        if(mp.find(txt[j]) != mp.end()) // txt[j] is present in map
        {
            mp[txt[j]]--;
            if(mp[txt[j]] == 0){
                count--;
            }
        }
        if(j-i+1 < k)
            j++;
        else if(j-i+1 == k){
            if(count == 0)
                ans++;
            
            if(mp.find(txt[i]) != mp.end()){
                mp[txt[i]]++;
                if(mp[txt[i]] == 1)
                    count++;
            }  
            i++;
            j++;  

        }
    }    
        return ans;    
    }

int main(){

    string pat = "for";
    string txt = "forxxorfxdofr";
    int count = searchAnagrams(pat,txt);
    cout<<"Number of anagrams - "<<count;
    return 0;
}