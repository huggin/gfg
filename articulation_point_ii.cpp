//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    vector<int> marked;
    vector<int> ans;
    vector<int> prev;
    vector<int> low;
    vector<int> dis;
    int count;
    
    void dfs(int u, vector<int> adj[]) {
        dis[u] = count++;
        low[u] = dis[u];
        marked[u] = 1;
        int d = 0;
        for(auto w : adj[u]) {
            if (!marked[w]) {
                ++d;
                prev[w] = u;
                dfs(w, adj);
                if (low[w] >= dis[u] && prev[u] != -1) {
                    ans.push_back(u);
                } else {
                    low[u] = min(low[u], low[w]); 
                }
            } else {
                if (w == prev[u]) continue;
                low[u] = min(low[u], dis[w]);  
            }
        }
        
        if (prev[u] == -1 && d > 1) {
            ans.push_back(u);
        } 
    }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        marked.assign(V, 0);
        prev.assign(V, 0);
        dis.assign(V, -1);
        low.assign(V, -1);
        ans.clear();
        count = 0;
        
        for(int i = 0; i < V; ++i) {
            if (!marked[i]) {
                prev[i] = -1;
                dfs(i, adj);
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        if(ans.size() == 0) return vector<int>{-1};
        return ans;
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
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends
