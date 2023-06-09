//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  private:
      vector<int> vis;
      vector<int> pathVis;
      bool check(int start, vector<int> adj[])
      {
        vis[start] = 1;
        pathVis[start] = 1;
        for (auto neighbour : adj[start])
        {
            if (!vis[neighbour])
            {
                if (check(neighbour, adj)==true) return true;
            }
            else if (pathVis[neighbour] == 1)
            {
                return true;
            }
            
        }
        pathVis[start]=0;
        return false;
      }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) 
    {
        vector<int> vis(V,0);
	    vector<int> toposort;
	    vector<int> indegree(V, 0);
	    
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
	    if (toposort.size() != V) return true;
	    return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends