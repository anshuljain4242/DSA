#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    struct Compare{
        bool operator()(ListNode* a, ListNode* b)
        {
            return a -> val > b -> val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue< ListNode*, vector<ListNode*>, Compare > pq;

        int k = lists.size();
        for(int i=0; i<k; i++)
        {
            if(lists[i])
                pq.push(lists[i]);
        }
        
        ListNode* head = NULL;
        ListNode* tail = NULL;

        while(!pq.empty())
        {
            ListNode* temp = pq.top();
            pq.pop();

            if(head == NULL)
            {
                head = temp;
                tail = temp;
            }
            else
            {
                tail -> next = temp;
                tail = temp;
            }

            if(temp -> next)
                pq.push(temp -> next);      
        }
        return head;

    }
};