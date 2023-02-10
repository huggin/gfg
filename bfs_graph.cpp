//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
	vector<int> bfsOfGraph(int V, vector<int> adj[]){
	    // Code here
	    queue<int> q;
	    vector<int> visited(V);
	    vector<int> res;
	    q.push(0);
	    while(!q.empty()) {
	        int c = q.front();
	        q.pop();
	        res.push_back(c);
	        visited[c] = 1;
	        for(int i = 0; i < adj[c].size(); ++i) {
	            if (!visited[adj[c][i]]) {
	                q.push(adj[c][i]);
	                visited[adj[c][i]] = 1;
	            }
	        }
	    }
	    return res;
	}
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
