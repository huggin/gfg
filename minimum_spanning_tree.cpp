//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> Q;
        vector<int> v(V);
        Q.emplace(0, 0);
        
        int ans = 0;
        for(int i = 0; i < V; ) {
            auto c = Q.top();
            Q.pop();
            if (v[c.second] == 1) continue;
            ++i;
            v[c.second] = 1;
            ans += c.first;
            
            for(int j = 0; j < adj[c.second].size(); ++j) {
                if (v[adj[c.second][j][0]] == 0) {
                    Q.emplace(adj[c.second][j][1], adj[c.second][j][0]);
                }
            }
        }
        return ans;
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends
