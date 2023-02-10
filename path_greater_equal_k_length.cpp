//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

struct Edge {
    int v;
    int o;
    int w;
    
    Edge(int vertex, int other, int weight): v(vertex), o(other), w(weight) {}
};

class Solution {
    int n;
    int marked[10];
    int total;
    bool found;
    
    void dfs(int u, vector<Edge*> adj[], int k) {
        if (found) return;
        marked[u] = 1;
        for(auto e : adj[u]) {
            int vertex = e->v;
            if (u == vertex) {
                vertex = e->o;
            }
            
            if (!marked[vertex]) {
                total += e->w;
                if (total >= k) {
                    found = true;
                    return;
                }
                dfs(vertex, adj, k);
                total -= e->w;
            }
            
        }
        marked[u] = 0;
    }
public:
    bool pathMoreThanK(int V, int E, int k, int *a) 
    { 
       //  Code Here
        vector<Edge*> adj[V];
        for(int i = 0; i < E*3; i+=3) {
            Edge* e = new Edge(a[i], a[i+1], a[i+2]);
            adj[a[i]].push_back(e);
            adj[a[i+1]].push_back(e);
        }
        n = V;
        memset(marked, 0, sizeof(marked));
        total = 0;
        found = false;
        
        dfs(0, adj, k);
        
        return found;
    } 
};



//{ Driver Code Starts.


int main() {
	//code
    int t;cin >> t;
    while(t--)
    {
        int V, E, K;
        cin >> V >> E >> K;
        int a[3*E + 1];
        for(int  i=0;i<3*E;i++){
            cin >> a[i];
        }
        
        Solution obj;
        if(obj.pathMoreThanK(V, E, K, a)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
        
    }
	return 0;
}
// } Driver Code Ends
