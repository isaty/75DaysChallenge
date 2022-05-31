class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        
        vector<vector<int>>graph(n,vector<int>(n,-1));
        
        for (vector<int>edge: edges) {
            graph[edge[0]][edge[1]] = edge[2];
            graph[edge[1]][edge[0]] = edge[2];
        }
        
        int ans  = 0;
        vector<int>vis(n,0);
        
        priority_queue<pair<int,int>>q;
        q.push({maxMoves,0});

        while (!q.empty()) {
            int node=q.top().second;
            int maxMovesRemaining=q.top().first;
            q.pop();
            
            if (vis[node]) {
                continue;
            }
            
            vis[node] = 1;
            // beacuse you are visiting the curr node 
            ans++;

            for (int nei = 0; nei < n; nei++) {
                if (graph[node][nei] != -1) {

                     if (!vis[nei] && maxMovesRemaining >= graph[node][nei] + 1) {
                         q.push({maxMovesRemaining - graph[node][nei] - 1,nei});
                    }
                    int movesCost = min(maxMovesRemaining, graph[node][nei]);
                    graph[nei][node] -= movesCost;
                    graph[node][nei] -= movesCost;
                    ans += movesCost;
                }
            }
        }

        return ans;
    }
};