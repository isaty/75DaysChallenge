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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL)
            return NULL;
        
        vector<ListNode*>ar;
        ListNode* itr=head;
        
        while(itr!=NULL)
        {
            ar.push_back(itr);
            itr=itr->next;
        }
        
        int n=ar.size();
        k=k%n;
        
        if(k==0)
            return head;
        
        ar[n-1]->next=head;
        ar[n-k-1]->next=NULL;
        head=ar[n-k];
        
        return head;
    }
};