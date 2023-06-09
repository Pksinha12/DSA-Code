class Solution {
private:
    int V = 0;
    vector<int> vis;
    vector<int> pathVis;
    vector<int> safeNodes;
    
    bool dfsCheck(int i, vector<vector<int>>& graph)
    {
        vis[i] = 1;
        pathVis[i] = 1;
        
        for(auto neighbour : graph[i])
        {
            if (!vis[neighbour])
            {
                if (dfsCheck(neighbour, graph) == true) 
                {
                    return true;
                }
                    
            }
            else if (pathVis[neighbour])
            {
                return true;
            }
        }
        pathVis[i] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        V = graph.size();
        vis.resize(V, 0);
        pathVis.resize(V, 0);
        
        for (int i = 0; i < V; i++)
        {
            if (!vis[i]) dfsCheck(i, graph);
        }
        for (int i = 0; i < V; i++)
        {
            if (pathVis[i] == 0) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};