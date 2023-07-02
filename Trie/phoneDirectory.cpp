#include <iostream>
#include <string>
#include <vector>
using namespace std;

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

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }

    bool isNode(int i)
    {
        return links[i] != NULL;
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
        }
        node->setEnd();
    }

    vector<string> getContactsDFS(string prefix)
    {
        vector<string> result;
        Node *node = root;
        for (char ch : prefix)
        {
            if (node->containsKey(ch))
            {
                node = node->get(ch);
            }
            else
            {
                return result;
            }
        }
        dfsHelper(node, result, prefix);
        return result;
    }

    void dfsHelper(Node *node, vector<string> &result, string prefix)
    {
        if (node->isEnd())
            result.push_back(prefix);

        for (int i = 0; i < 26; i++)
        {
            if (node->isNode(i))
            {
                char c = 'a' + i;
                dfsHelper(node->get(c), result, prefix + c);
            }
        }
    }
};

vector<vector<string> > phoneDirectory(vector<string> &contactList, string &queryStr)
{
    Trie trie;
    vector<vector<string> > ans;

    for (auto &it : contactList)
    {
        trie.insert(it);
    }

    for (int i = 0; i < queryStr.size(); i++)
    {
        vector<string> temp = trie.getContactsDFS(queryStr.substr(0, i + 1));
        if (temp.size())
            ans.push_back(temp);
    }
    
    return ans;
}