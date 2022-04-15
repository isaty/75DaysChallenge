/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    void  flat(Node* cur)
    {
        Node* cur_child=cur->child;
        Node*cur_next=cur->next;
        Node*itr=cur_child;
        Node*prev=NULL;
        
        while(itr!=NULL)
        {
            prev=itr;
            if(itr->child)
            {
                flat(itr);
            }
            itr=itr->next;
        }
        
        cur->child=NULL;
        
        cur->next=cur_child;
        cur_child->prev=cur;
        
        prev->next=cur_next;
        if(cur_next)
            cur_next->prev=prev;
            
    }
    Node* flatten(Node* head) {
       Node*t=head;
        while(t!=NULL)
        {
            if(t->child)
            {
                flat(t);
            }
            t=t->next;
        }
        return head;
    }
};