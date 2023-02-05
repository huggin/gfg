//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    bool overflow;

    long long dfs(vector<int> adj[], int s, int prev, int* c, vector<long long>& d) {
        vector<long long> children;
        for(int w : adj[s]) {
            if (w == prev) continue;
            children.push_back(dfs(adj, w, s, c, d));
        }
        if (children.size() == 0) return d[s] = c[s];
        d[s] = c[s] + children.size() * (*max_element(children.begin(), children.end()));
        if (d[s] > 1e18) overflow = true;
        return d[s];
    }
public:
    long long minimum_amount(vector<vector<int>> &Edges, int N, int S, int *Cap){
       // Code here
        vector<int> adj[N];
        for(auto& e : Edges) {
            adj[e[0]-1].push_back(e[1]-1);
            adj[e[1]-1].push_back(e[0]-1);
        }
        
        vector<long long> d(N);
        overflow = false;
        dfs(adj, S-1, -1, Cap, d);
        if (overflow) return -1;
        return d[S-1];
    }
};

//{ Driver Code Starts.


int main()
 {
	int T;
	cin>> T;
	while (T--)
	{
	    int num, start;
	    cin>>num>>start;
	    int cap[num];
	    for(int i = 0; i<num; i++)
	        cin>>cap[i];
	    
	    vector<vector<int>> Edges(num-1);
	    for(int i=1;i < num;i++){
	        int u, v; cin >> u >> v;
	        Edges[i-1].push_back(u);
	        Edges[i-1].push_back(v);
	    }
	    
	    
    	Solution obj;
	    long long ans = obj.minimum_amount(Edges, num, start, cap);
	    cout << ans << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends
