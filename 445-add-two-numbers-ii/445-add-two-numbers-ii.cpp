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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        stack<ListNode*>s1;
        stack<ListNode*>s2;
        ListNode*head=NULL;
        
        ListNode* t=l1;
        
        while(t!=NULL)
        {
            s1.push(t);
            t=t->next;
        }
        
        t=l2;
        while(t!=NULL)
        {
            s2.push(t);
            t=t->next;
        }
        int c=0;
        while(!s1.empty() && !s2.empty())
        {
           int a=s1.top()->val;
           int b=s2.top()->val;
           int sm=(a+b+c);
            
           c=sm/10;
           a=sm%10; 
           // cout<<a<<" "<<c<<"\n";
           if(head==NULL)
           {
                head=new ListNode(a);   
           }
           else
           {
                ListNode*m=new ListNode(a);
                m->next=head;
                head=m;
           }
             // cout<<head->val<<"\n"; 
            s1.pop();
            s2.pop();
            
        }
        
        while(!s1.empty())
        {
            int a=s1.top()->val+c;
            c=a/10;
            a=a%10;
            if(head==NULL)
           {
                head=new ListNode(a);   
           }
           else
           {
                ListNode*m=new ListNode(a);
                m->next=head;
                head=m;
           }   
            s1.pop();
        }
        
        while(!s2.empty())
        {
            int a=s2.top()->val+c;
            c=a/10;
            a=a%10;
            if(head==NULL)
           {
                head=new ListNode(a);   
           }
           else
           {
                ListNode*m=new ListNode(a);
                m->next=head;
                head=m;
           }
            s2.pop();
        }
        
        if(c>0)
        {
                ListNode*m=new ListNode(1);
                m->next=head;
                head=m;
        }
        return head;    
    }
};