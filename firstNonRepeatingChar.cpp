#include<iostream>
#include<queue>
#include<map>
#include<string>
using namespace std;

string FirstNonRepeating(string s){
    map<char,int> mp;
    queue<int> q;
    string ans = "";


    for(int i=0; i<s.length(); i++){
        mp[s[i]]++;
        q.push(s[i]);

        while(!q.empty()){
            if(mp[q.front()] > 1){
                q.pop();
            }
            else{
                ans.push_back(q.front());
                break;
            }
        }
        if(q.empty()){
            ans.push_back('#');
        }

    }
    return ans;
}

int main(){
    string s = "aabbcc";
    string ans = FirstNonRepeating(s);
    cout<<ans;
    return 0;
}