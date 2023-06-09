class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
       int V = graph.size();
        vector<vector<int>> revGraph(V);
        vector<int> vis(V, 0);
        vector<int> indegree(V,0);
        for (int i = 0; i < V; i++)
        {
            for (auto it : graph[i])
            {
                revGraph[it].push_back(i);
            }
        }
        queue<int> q;
        for (int i = 0; i < V; i++)
        {
            for (auto it : revGraph[i])
                indegree[it]++;
        }
        for (int i = 0; i < V; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
                vis[i] = 1;
            }
        }
        vector<int> safeNodes;
        while (!q.empty())
        {
            int node = q.front();
            safeNodes.push_back(node);
            q.pop();
            
            for (auto neighbour : revGraph[node])
            {
                indegree[neighbour]--;
                if (!vis[neighbour] and indegree[neighbour] == 0)
                {
                    q.push(neighbour);
                    vis[neighbour] = 1;
                }
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};