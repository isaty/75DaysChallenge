/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* head=NULL;
        ListNode* tail=NULL;
        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>>pq;
        
        for(ListNode* i:lists)
        { 
            if(i!=NULL)
            pq.push({i->val,i});
        }
        
        while(!pq.empty())
        {
            pair<int,ListNode*>curr=pq.top();
            pq.pop();
            if(head==NULL)
            {
                head=curr.second;
                tail=head;
            }
            else
            {
                tail->next=curr.second;
                tail=tail->next;
            }
            
            if(curr.second->next!=NULL)
                pq.push({curr.second->next->val,curr.second->next});
            
            tail->next=NULL;
        }
        
        return head;
    }
};