#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Using Trie
struct Node
{
    Node *links[26];
    bool flag = false;
    int cntPrefix = 0;

    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void increaseCntPrefix()
    {
        cntPrefix++;
    }

    int getCntPrefix()
    {
        return cntPrefix;
    }

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increaseCntPrefix();
        }
        node->setEnd();
    }

    void getLCP(string word, string &ans, int n)
    {

        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
            {
                break;
            }
            else
            {
                node = node->get(word[i]);
                if (node->getCntPrefix() == n)
                {
                    ans.push_back(word[i]);
                }
            }
            if (node->isEnd())
                break;
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    Trie trie;

    for (auto s : arr)
    {
        trie.insert(s);
    }

    string first = arr[0];
    string ans = "";
    trie.getLCP(first, ans, n);

    return ans;
}

// using sorting
string longestCommonPrefix(vector<string> &strs)
{
    sort(strs.begin(), strs.end());
    int n = strs.size();
    string s = strs[0], e = strs[n - 1];
    string ans = "";
    for (int i = 0; i < strs[0].size(); i++)
    {
        if (s[i] == e[i])
        {
            ans = ans + s[i];
        }
        else
            break;
    }
    return ans;
}
