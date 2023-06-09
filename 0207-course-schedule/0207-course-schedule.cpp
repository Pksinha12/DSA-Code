class Solution {
public:
    bool canFinish(int V, vector<vector<int>>& prerequisites) {
        vector<int> vis(V,0);
	    vector<int> toposort;
	    vector<int> indegree(V, 0);
	    vector<vector<int>> adj(V);
        for (int i = 0; i < prerequisites.size(); i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
	    for (int i = 0; i < V; i++)
	    {
	        for (auto it : adj[i])
	        {
	            indegree[it]++;
	        }
	    }
	    queue<int> q;
	    for (int i = 0; i < V; i++)
	    {
	        if (indegree[i] == 0) 
	        {
	            q.push(i);
	            vis[i] = 1;
	        }
	    }
	    
	    while (!q.empty())
	    {
	        int node = q.front();
	        toposort.push_back(node);
	        q.pop();
	        
	        for (auto i : adj[node])
	        {
	            indegree[i]--;
	            if (!vis[i] and indegree[i] == 0)
	            {
	                q.push(i);
	                vis[i] = 1;
	            }
	        }
	    }
	    if (toposort.size() == V) return true;
	    return false;
    }
};