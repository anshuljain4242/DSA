#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node
{
    Node *links[2];

    bool containsKey(int bit)
    {
        return (links[bit] != NULL);
    }

    void put(int bit, Node *node)
    {
        links[bit] = node;
    }

    Node *get(int bit)
    {
        return links[bit];
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

    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit))
            {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMax(int num)
    {
        Node *node = root;
        int maxNum = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (node->containsKey(!bit))
            {
                maxNum = maxNum | (1 << i);
                node = node->get(!bit);
            }
            else
            {
                node = node->get(bit);
            }
        }
        return maxNum;
    }
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int> > &queries)
{
    // O(Nlog N)
    sort(arr.begin(), arr.end());

    vector<pair<int, pair<int, int> > > oq; // offline Queries
    int q = queries.size();
    for (int i = 0; i < q; i++)
    {
        oq.push_back(make_pair(queries[i][1], make_pair(queries[i][0], i)));
    }
    // o(Qlog Q)
    sort(oq.begin(), oq.end());

    Trie trie;
    vector<int> ans(q, 0);
    int idx = 0;
    int n = arr.size();
    
    // O(Q * 32 + N * 32)
    for (int i = 0; i < q; i++)
    {
        int ai = oq[i].first;
        int xi = oq[i].second.first;
        int qIdx = oq[i].second.second;

        while (idx < n && arr[idx] <= ai)
        {
            trie.insert(arr[idx]);
            idx++;
        }
        if (idx == 0)
            ans[qIdx] = -1;
        else
            ans[qIdx] = trie.getMax(xi);
    }

    return ans;
}