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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *t=headA;
        while(t!=NULL)
        {
            t->val=(-1) * (t->val) ;
            t=t->next;
        }
        
        ListNode *ans=NULL;
        t=headB;
        bool found=false;
        while(t!=NULL)
        {
            if(t->val<0)
            {
                ans=t;
                break;
            }
            t=t->next;
        }
        t=headA;
        while(t!=NULL)
        {
           t->val=abs(t->val);
            t=t->next; 
        }
        return ans;
    }
};