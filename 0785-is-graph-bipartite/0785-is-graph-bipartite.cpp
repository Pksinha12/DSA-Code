class Solution {
private:
    vector<int> vis;
    int v;
    bool check(int start, vector<vector<int>>& graph)
    {
        vis[start] = 1;
        queue<int> q;
        q.push(start);
        
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for (auto neighbour : graph[node])
            {
                if (vis[neighbour] == -1)
                {
                    q.push(neighbour);
                    vis[neighbour] = !vis[node];
                }
                else if (vis[neighbour] == vis[node]) return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        v = graph.size();
        vis.resize(v, -1);
        for (int i = 0; i < v; i++)
        {
            if (vis[i] == -1 and check(i, graph) == false) return false;
        }
        return true;
    }
};