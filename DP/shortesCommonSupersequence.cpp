#include<iostream>
#include<vector>
#include<string>
using namespace std;

string shortestSupersequence(string a, string b)
{
	int len1 = a.size();
    int len2 = b.size();

    vector<vector<int> > dp(len1+1, vector<int>(len2+1, -1));

    for(int j = 0; j <= len2; j++)
        dp[0][j] = 0;
    for(int i = 0; i <= len1; i++)
        dp[i][0] = 0;

    for(int i = 1; i <= len1; i++){
        for(int j = 1; j <= len2; j++){
            if(a[i-1] == b[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);           
        }
    } 
	int i = len1;
	int j = len2;
	string ans = "";

	while(i >0 && j > 0){
		if(a[i-1] == b[j-1]){
			ans += a[i-1];
			i--, j--;
		}
		else if(dp[i-1][j] > dp[i][j-1]){
			ans += a[i-1];
			i--;
		}
		else{
			ans += b[j-1];
			j--;
		}
	}

	while(i > 0){
		ans += a[i-1];
		i--;
	}
	while(j > 0){
		ans += b[j-1];
		j--;
	}
	string t = ans;
	reverse(t.begin(), t.end());
	return t;
}