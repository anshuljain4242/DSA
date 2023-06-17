#include <iostream>
#include <vector>
#include<string>
using namespace std;

bool isPalin(string &s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}
void solve(int idx, string s, vector<string> &partition, vector<vector<string> > &ans)
{
    if (idx == s.length())
    {
        ans.push_back(partition);
        return;
    }
    for (int i = idx; i < s.length(); i++)
    {
        if (isPalin(s, idx, i))
        {
            partition.push_back(s.substr(idx, i - idx + 1));
            solve(i + 1, s, partition, ans);
            partition.pop_back();
        }
    }
}
vector<vector<string> > partition(string s)
{
    vector<vector<string> > ans;
    vector<string> partition;
    solve(0, s, partition, ans);
    return ans;
}