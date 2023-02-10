//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
    vector<int> marked;
    vector<int> low;
    vector<int> dist;
    vector<int> onStack;
    int count = 0;
    
    vector<vector<int>> ans;
    stack<int> S;
    
    void dfs(int i, vector<int> adj[]) {
        marked[i] = 1;
        dist[i] = count++;
        low[i] = dist[i];
        onStack[i] = 1;
        S.push(i);
        
        for(auto w : adj[i]) {
            if (!marked[w]) {
                dfs(w, adj);
                low[i] = min(low[i], low[w]);
            } else if (onStack[w]) {
                low[i] = min(low[i], dist[w]);
            }
        }
        if (low[i] == dist[i]) {
            vector<int> v;
            while(!S.empty()) {
                int c = S.top();
                S.pop();
                v.push_back(c);
                onStack[c] = 0;
                if (c == i) break;
            }
            sort(v.begin(), v.end());
            ans.push_back(v);
        }
    }
public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        //code here
        marked.assign(V, 0);
        low.assign(V, 0);
        dist.assign(V, 0);
        onStack.assign(V, 0);
        count = 0;
        ans.clear();
        
        for(int i = 0; i < V; ++i) {
            if (!marked[i]) {
                dfs(i, adj);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends
