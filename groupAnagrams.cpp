#include<iostream>
#include<unordered_map>
#include<map>
#include<vector>
#include<string>
#include<array>
using namespace std;

/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original 
letters exactly once.
Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
*/

/*
Create a hash map. 
Take a string one by one from strs and sort it. Basic Intuition - All the anagrams will be same word if sorted.
Ex -
"aet" -> ["eat", "tea", "ate"]
"ant" -> ["tan", "nat"]
"abt" -> ["bat"]
TC -> O(m * nlogn)
*/
vector<vector<string> > groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string> > mp;

    for(auto s : strs){
        string word = s;
        sort(word.begin(), word.end());
        mp[word].push_back(s);
    }

    vector<vector<string> > ans;
    for(auto x: mp){
        ans.push_back(x.second);
    }
    return ans;
}

vector<vector<string> > groupAnagramsT(vector<string>& strs) {

    // mapping character count to list on Anagrams
    map<vector<int>, vector<string> > mp;

    for(string s:strs){
        vector<int> count(26, 0);
        for(char c : s){
            count[c - 'a']++;
        }
        mp[count].push_back(s);
    }
    vector<vector<string> > ans;
    for(auto it:mp){
        ans.push_back(it.second);
    }
    return ans;

}