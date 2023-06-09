//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  private:
  vector<int> vis;
  stack<int> st;
  void toposort(int node, vector<vector<pair<int,int>>>& adj)
  {
      vis[node] = 1;
      for (auto it : adj[node])
      {
          int neighbour = it.first;
          int wt = it.second;
          if (!vis[neighbour])
          {
              toposort(neighbour, adj);
          }
      }
      st.push(node);
  }
  public:
     vector<int> shortestPath(int V,int E, vector<vector<int>>& edges){
        // code here
        vis.resize(V,0);
        vector<vector<pair<int,int>>> adj(V);
        for (int i = 0; i < E; i++)
        {
            int node1 = edges[i][0];
            int node2 = edges[i][1];
            int weight = edges[i][2];
            adj[node1].push_back({node2,weight});
        }
        for (int i = 0; i < V; i++)
        {
            if (!vis[i])
            {
                toposort(i, adj);
            }
        }
        vector<int> dis(V,1e9);
        dis[0] = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            
            for (auto it : adj[node])
            {
                int v = it.first;
                int wt = it.second;
                dis[v] = min(dis[v],dis[node]+wt);
            }
        }
        for (int i = 0; i < V; i++)
        {
            if (dis[i] == 1e9) dis[i] = -1;
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends