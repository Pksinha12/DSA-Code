class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis)
    {
        vis[node] = 1;
        for (auto neighbours : adj[node])
        {
            if (!vis[neighbours])
                dfs(neighbours, adj, vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n =  isConnected.size();
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        int count = 0;
        // matrix to adjancecy list
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1 and i != j)
                {
                    adj[i].push_back(j);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (!vis[i]) 
            {
                dfs(i, adj, vis);
                count++;
            }
        }
        return count;
    }
};