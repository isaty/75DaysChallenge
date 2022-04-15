/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       
       map<Node*,Node*>mp;
       Node*t=head;
       Node* nw_h=NULL; 
       Node* nw_t=NULL; 
        
       while(t!=NULL)
       {
           if(nw_h==NULL)
           {
               nw_h=new Node(t->val);
               nw_t=nw_h;
           }
           else
           {
               nw_t->next=new Node(t->val);
               nw_t=nw_t->next;
           }           
           mp[t]=nw_t;
           t=t->next;

       } 
        
        t=head;
        while(t!=NULL)
        {
            Node*rn=t->random;
            Node*cp=mp[t];
            
            cp->random=mp[rn];
            
            t=t->next;
        }
        return nw_h;
    }
};