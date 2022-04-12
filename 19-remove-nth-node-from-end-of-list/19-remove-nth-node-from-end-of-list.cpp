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
       
       ListNode*prev=NULL;
       ListNode*itr=head;
       ListNode*nthNode=NULL;
        
       while(--n && itr!=NULL)
       {
           itr=itr->next;
       } 
        
       nthNode=head;
       itr=itr->next; 
        
       while(itr!=NULL)
       {
           prev=nthNode;
           nthNode=nthNode->next;
           itr=itr->next;
       } 
        
        if(prev==NULL)
        {
            head=head->next;
        }
        else 
        {
            prev->next=nthNode->next;
        }
        
       return head;
    }
};