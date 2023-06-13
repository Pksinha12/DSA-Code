//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<long long> ways(n, 0);
        vector<long long> dist(n, LLONG_MAX);
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        vector<vector<pair<long long, long long>>> adj(n);
        for (auto it : roads)
        {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        
        long long mod = (long long)(1e9 + 7);
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;
        
        while (!pq.empty())
        {
            auto it = pq.top();
            pq.pop();
            long long dis = it.first;
            long long node = it.second;
            
            for (auto itr : adj[node])
            {
                long long adjNode = itr.first;
                long long edgeWt = itr.second;
                
                if (dis + edgeWt < dist[adjNode])
                {
                    dist[adjNode] = dis + edgeWt;
                    pq.push({dis + edgeWt, adjNode});
                    ways[adjNode] = ways[node] % mod;
                }
                else if (dis + edgeWt == dist[adjNode])
                {
                    ways[adjNode] += ways[node] % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends