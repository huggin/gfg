//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
    {
        // code here
        vector<int> degree(n);
        vector<int> adj[n];
        for(int i = 0; i < m; ++i) {
            degree[edges[i][1]-1]++;
            adj[edges[i][0]-1].push_back(edges[i][1]-1);
        }
        vector<int> ans(n);
        int k = 1;
        queue<int> Q;
        while(true) {
            for(int i = 0; i < n; ++i) {
                if (degree[i] == 0 && ans[i] == 0) {
                    Q.push(i);
                    ans[i] = k;
                }
            }
            k++;
            if (Q.empty()) break;
            while(!Q.empty()) {
                int c = Q.front();
                Q.pop();
                for(auto w: adj[c]) {
                    degree[w]--;
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
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> edges(m,vector<int>(2));
        for(int i=0;i<m;i++)
            cin>>edges[i][0]>>edges[i][1];
        Solution s;
        vector<int> ans=s.minimumTime(n,edges,m);
        for(auto j:ans)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
