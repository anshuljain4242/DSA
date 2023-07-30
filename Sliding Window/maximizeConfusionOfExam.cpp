#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int maxConsecutiveAnswers(string answerKey, int k) {
    int maxFreq = 0;
    int i = 0;
    unordered_map<char,int> TFcount;

    for(int j=0; j<answerKey.length(); j++){
        char curr = answerKey[j];
        TFcount[curr]++;

        maxFreq = max(maxFreq, TFcount[curr]);

        if(j - i + 1 > maxFreq + k){
            TFcount[answerKey[i]]--;
            i++;
        }
    }
    return answerKey.length() - i;
}

// Without map

int solve(string a, int k,char c){
    int i=0;
    int j=0;
    int cnt=0;
    int n=a.size();
    int ans=0;
    while(j<n){
        if(a[j]==c)
        cnt++;
        while(i<n&&cnt>k){
            if(a[i]==c)
            cnt--;
            i++;
        }  
        ans=max(j-i+1,ans);
        j++;
    }
    return ans;
}
int maxConsecutiveAnswerss(string a, int k) {
    
    int ans1=solve(a,k,'T');
    int ans2=solve(a,k,'F');
    return max(ans1,ans2);
    }