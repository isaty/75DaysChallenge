/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        //detecting cycle (turtle - hare) approach
        ListNode*slow=head;
        ListNode*fast=head;
        
        while(fast!=NULL && slow!=NULL)
        {
            slow=slow->next;
            
            if(fast->next!=NULL)
               fast=fast->next->next;
            else
               fast=fast->next; 
            
            if(fast==slow)
                break;
        }
        
        if(fast==NULL)
            return NULL;
        
        //head of cycle
        ListNode*start=head;
        
        while(start!=slow)
        {
            start=start->next;
            slow=slow->next;
        }
        
        return start;
        
    }
};