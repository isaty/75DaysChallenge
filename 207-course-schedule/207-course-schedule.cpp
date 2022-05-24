class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    
        vector<int>in(numCourses,0);
        vector<int>adj[numCourses];
        for(vector<int>i:prerequisites)
        {
            adj[i[1]].push_back(i[0]);
            in[i[0]]++;
        }
        
        queue<int>q;
        for(int i=0;i<numCourses;i++)
        {
            if(in[i]==0)
            {
                q.push(i);
            }
        }
        int course=0;
        while(!q.empty())
        {
            int tmp=q.front();
            q.pop();
            course++;
            for(int u:adj[tmp])
            {
                in[u]--;
                if(in[u]==0)
                   q.push(u); 
            }
            
        }
        
        return course==numCourses;
    }
};