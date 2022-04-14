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
    ListNode* reverseKGroup(ListNode* head, int k) {
        
          ListNode* res_head=NULL;
          ListNode* res_tail=NULL;
          
          int sz=0;
          ListNode*t=head;
          while(t!=NULL){t=t->next;sz++;}
        
          t=head;
          int grp=sz/k;
        
          while(grp-- && t!=NULL)
          {
              ListNode* khead=NULL;
              ListNode* ktail=NULL;
              int n=k;
              
              //reverse in grp
              while(t!=NULL && n--)
              {
                  if(khead==NULL)
                  {
                      khead=t;
                      ktail=t;
                      t=t->next;
                  }
                  else
                  {
                      ListNode*m=t;
                      t=t->next;
                      m->next=khead;
                      khead=m;
                  }
              }
              
              //linking with new list
              if(res_head==NULL)
              {
                  res_head=khead;
                  res_tail=ktail;
                  res_tail->next=NULL;
              }
              else
              {
                  res_tail->next=khead;
                  res_tail=ktail;
                  res_tail->next=NULL;
              }
               
          }
        
           res_tail->next=t;
           return res_head;
    }
};