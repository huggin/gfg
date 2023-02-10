//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    vector<int> v;
    int count;
    void dfs(int k, vector<int> adj[], vector<int>& f) {
        v[k] = 1;
        for(int i = 0; i < adj[k].size(); ++i) {
            if (v[adj[k][i]] == 0) {
                dfs(adj[k][i], adj, f);
            }
        }
        f[k] = count++;
    }
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Code here
	    vector<int> f(V);
	    v.assign(V, 0);
	    count = 0;
	    for(int i = 0; i < V; ++i) {
	        v.assign(V, 0);
	        count = 0;
	        dfs(i, adj, f);
	        if (f[i] == V-1) return i;
	    }
	    
	    return -1;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
