#include <iostream>
#include <string>
#include <map>
#include <queue>
using namespace std;

/*
Given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

Return any possible rearrangement of s or return "" if not possible.

Example 1:

Input: s = "aab"
Output: "aba"
Example 2:

Input: s = "aaab"
Output: ""

*/

class Solution
{
public:
    string reorganizeStringOptimal(string s)
    {
        int n = s.length();

        // Storing the frequency of each char
        int countArray[26] = {0};
        for (int i = 0; i < n; i++)
        {
            countArray[s[i] - 'a'] += 1;
        }

        // finding the max freq char and it's freq
        int maxFreq = -1;
        char maxFreqChar = '#';
        for (int i = 0; i < 26; i++)
        {
            if (maxFreq < countArray[i])
            {
                maxFreq = countArray[i];
                maxFreqChar = 'a' + i;
            }
        }

        if (maxFreq > (n + 1) / 2)
            return "";

        // placing the maxFreqChar at alternate indices of the string 
        int idx = 0;
        while (maxFreq > 0 && idx < n)
        {
            s[idx] = maxFreqChar;
            idx += 2;
            maxFreq--;
        }
        // updating the freq of maxFreqChar to 0
        countArray[maxFreqChar - 'a'] = 0;

        // placing the remaining characters at the next alternate indices
        for (int i = 0; i < 26; i++)
        {
            while (countArray[i] > 0)
            {
                if (idx >= n)
                    idx = 1;

                s[idx] = 'a' + i;
                idx += 2;
                countArray[i]--;
            }
        }
        return s;
    }

    string reorganizeString(string s)
    {

        map<char, int> mp;
        for (auto i : s)
            mp[i]++;

        priority_queue<pair<int, char> > pq;

        for (auto i : mp)
            pq.push(make_pair(i.second, i.first));

        string ans = "";

        while (!pq.empty())
        {
            auto curr = pq.top();
            pq.pop();
            int freq = curr.first;
            char ch = curr.second;

            if (ans.size() == 0)
            {
                ans += ch;
                freq--;
                if (freq > 0)
                    pq.push(make_pair(freq, ch));
            }

            else if (ans[ans.size() - 1] == ch)
            {
                if (pq.empty())
                    return "";

                auto next = pq.top();
                pq.pop();
                int freq1 = next.first;
                char ch1 = next.second;
                ans += ch1;
                freq1--;
                if (freq1 > 0)
                    pq.push(make_pair(freq1, ch1));
                pq.push(make_pair(freq, ch));
            }
            else
            {
                ans += ch;
                freq--;
                if (freq > 0)
                    pq.push(make_pair(freq, ch));
            }
        }
        return ans;
    }
};