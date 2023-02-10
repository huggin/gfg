//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    vector<int> visited;
    
    void dfs(int v, vector<int> adj[]) {
        visited[v] = 1;
        for(auto w : adj[v]) {
            if (!visited[w]) {
                dfs(w, adj);
            }
        }
    }
    
    void dfs2(int v, vector<int> adj[], int c, int d) {
        visited[v] = 1;
        for(auto w : adj[v]) {
            if (w == c && v == d || w == d && v == c) continue;
            if (!visited[w]) {
                dfs2(w, adj, c, d);
            }
        }
    }
    
	public:
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        visited.assign(V, 0);
        int total = 0;
        for(int i = 0; i < V; ++i) {
            if (!visited[i]) {
                ++total;
                dfs(i, adj);
            }
        }
        
        visited.assign(V, 0);
        int ans = 0;
        for(int i = 0; i < V; ++i) {
            if (!visited[i]) {
                ++ans;
                dfs2(i, adj, c, d);
            }
        }
        //cout << total << ' ' << ans << endl;
        return ans - 1 == total;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends
