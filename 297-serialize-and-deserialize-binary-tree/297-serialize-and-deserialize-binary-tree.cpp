/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        string ans="";
        int l=0;
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty())
        {
            int k=q.size();
        
            for(int i=0;i<k;i++)
            {
                
               TreeNode* t= q.front();
               q.pop();
               
               if(t==NULL)
               {
                   ans+="#,";
                   continue;
               }
                
               ans+=to_string(t->val)+","; 
               l=ans.length();
                
               q.push(t->left);
               q.push(t->right);
                
            }

        }
        ans=ans.substr(0,l);
        // cout<<ans;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        int itr=0,len=data.length(),lvl=0;
        
        if(len==0)
            return NULL;
        
        while(itr<len && data[itr]!=',')
        {
            itr++;
        }
        
        int fnum = stoi(data.substr(0,itr++));
        TreeNode* root=new TreeNode(fnum);
        
        queue<TreeNode*>q;
        q.push(root);
        
        while(!q.empty() && itr<len)
        {
            int lvl_itr=0;
            
            while(!q.empty() && lvl_itr<pow(2,lvl) && itr<len)
            {
               TreeNode* tmp=q.front();
               q.pop();
                
               for(int node=0;node<2;node++)
               {
                   if(itr<len && data[itr]!='#')
                   {
                       int anch=itr;
                       while(itr<len && data[itr]!=',')
                       {
                            itr++;
                       }
                     
                       int cnum=stoi(data.substr(anch,itr++));
                       TreeNode * t=new TreeNode(cnum);
                       
                       if(node==0)
                           tmp->left=t;
                       else
                           tmp->right=t;
                       
                       q.push(t);
                   }
                   else if(data[itr]=='#')
                   {
                       itr=itr+2;
                   }
               }
               lvl_itr++;
            }
            
            lvl++;

        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));