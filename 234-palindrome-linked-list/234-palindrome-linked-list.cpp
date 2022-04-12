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
    bool isPalindrome(ListNode* head) {
        
        if(head->next==NULL)
            return true;        
        
        ListNode*rev_head=NULL;

        int n=0;
        ListNode*t=head;
        while(t!=NULL)
        {
            t=t->next;
            n++;
        }
        
        t=head;
        int k=0;
        while(k<n/2 && t!=NULL)
        {
            if(rev_head==NULL)
            {
                rev_head=t;
                t=t->next;
                rev_head->next=NULL;
            }
            else
            {
                ListNode* m=t;
                t=t->next;
                m->next=rev_head;
                rev_head=m;
            }
            k++;
        }
        
        if(n%2!=0)
            t=t->next;
        
        while(t!=NULL && rev_head!=NULL)
        {
            if(t->val!=rev_head->val)
                return false;
            
            t=t->next;
            rev_head=rev_head->next;
        }
        return true;
        
    }
};