//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    vector<int> v;
    vector<int> post;
    
    void dfs(int i, vector<int> adj[]) {
        v[i] = 1;
        for(auto w : adj[i]) {
            if (!v[w]) {
                dfs(w, adj);
            }
        }
        post.push_back(i);
    }
  public:
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int source, int destination) {
        // Code here
        vector<int> paths(V);
        paths[source] = 1;
        v.assign(V, 0);
        for(int i = 0; i < V; ++i) {
            if (!v[i]) {
                dfs(i , adj);
            }
        }
        int i = V-1;
        for(i = V-1; i>=0; --i) {
            if (post[i] == source) {
                break;
            }
        }
        for(int j = i; j>=0; --j) {
            for(auto w : adj[post[j]]) {
                paths[w] += paths[post[j]];
            }
        }
        return paths[destination];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}
// } Driver Code Ends
