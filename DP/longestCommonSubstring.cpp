#include<iostream>
#include<vector>
#include<string>
using namespace std;
// Longest common substring
// Tabulation
int lcs(string &str1, string &str2){
	int len1 = str1.size();
    int len2 = str2.size();

    vector<vector<int> > dp(len1+1, vector<int>(len2+1, -1));

    for(int j = 0; j <= len2; j++)
        dp[0][j] = 0;
    for(int i = 0; i <= len1; i++)
        dp[i][0] = 0;
	int ans = 0;
    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
            if(str1[i-1] == str2[j-1]){
				dp[i][j] = 1 + dp[i-1][j-1];
				ans = max(ans, dp[i][j]);
			}
                
            else 
                dp[i][j] = 0;           
        }
    } 
	return ans;     
}

// Space Optimization
int lcsS(string &str1, string &str2){
	int len1 = str1.size();
    int len2 = str2.size();

    vector<int> prev(len2+1, 0), curr(len2+1, 0);

	int ans = 0;
    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
            if(str1[i-1] == str2[j-1]){
				curr[j] = 1 + prev[j-1];
				ans = max(ans, curr[j]);
			}  
            else 
                curr[j] = 0;           
        }
		prev = curr;
    } 
	return ans;     
}