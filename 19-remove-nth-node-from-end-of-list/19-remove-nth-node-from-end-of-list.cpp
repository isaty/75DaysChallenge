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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        vector<ListNode*>ar;
        ListNode*t=head;
        
        while(t!=NULL)
        {
           ar.push_back(t);
           t=t->next;
        }
        
        int sz=ar.size();
        
        int pos=sz-n;
        
        if(pos==0)
            head=ar[0]->next;
        else
            ar[pos-1]->next=ar[pos]->next;
        
        return head;
    }
};