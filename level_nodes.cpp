//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    if (X >= V) return -1;
	    vector<int> v(V);
	    v[0] = 1;
	    
	    vector<int> level(V, -1);
	    queue<int> Q;
	    Q.push(0);
	    Q.push(0);
	    while(!Q.empty()) {
	        int c = Q.front();
	        Q.pop();
	        int l = Q.front();
	        Q.pop();
	        for(auto w : adj[c]) {
	            if (!v[w]) {
	                v[w] = 1;
	                level[w] = l + 1;
	                Q.push(w);
	                Q.push(l+1);
	            }
	        }
	    }
	    return level[X];
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends
