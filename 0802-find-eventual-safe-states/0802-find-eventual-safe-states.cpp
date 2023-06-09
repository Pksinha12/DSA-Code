class Solution {
private:
    int V = 0;
    vector<int> vis;
    vector<int> check;
    vector<int> pathVis;
    vector<int> safeNodes;
    bool dfsCheck(int i, vector<vector<int>>& graph)
    {
        vis[i] = 1;
        check[i] = 0;
        pathVis[i] = 1;
        
        for(auto neighbour : graph[i])
        {
            if (!vis[neighbour])
            {
                if (dfsCheck(neighbour, graph) == true) 
                {
                    //check[i] = 0;
                    return true;
                }
                    
            }
            else if (pathVis[neighbour])
            {
                //check[i] = 0;
                return true;
            }
        }
        check[i] = 1;
        pathVis[i] = 0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) 
    {
        V = graph.size();
        vis.resize(V, 0);
        check.resize(V, 0);
        pathVis.resize(V, 0);
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                dfsCheck(i, graph);
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (check[i] == 1) safeNodes.push_back(i);
        }
        return safeNodes;
    }
};