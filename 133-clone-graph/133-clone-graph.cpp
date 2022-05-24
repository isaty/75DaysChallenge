/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        
        if(node==NULL)
            return NULL;
        unordered_map<Node*,Node*>mp;
        // unordered_set<Node*>vis;
        
        Node*root=new Node(1);
        mp[node]=root;
        
        queue<Node*>q;
        q.push(node);
        
        while(!q.empty())
        {
            Node* t=q.front();
            q.pop();
            Node* copy=mp[t];
            
            for(Node* i:t->neighbors)
            {
                Node* clone=NULL;
                if(mp.find(i)!=mp.end())
                {
                     clone=mp[i];
                }
                else
                {
                    Node *tmp=new Node(i->val);
                    mp[i]=tmp;
                    clone=tmp;
                    q.push(i);
                }
                
                copy->neighbors.push_back(clone);
            }
        }
        
        return root;
    }
};