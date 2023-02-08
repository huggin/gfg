//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
     void dfs(vector<int> adj[], int k, vector<int>& v) {
        for(auto c : adj[k]) {
            if (v[c] == 0) {
                v[c] = 1;
                dfs(adj, c, v);
            }
        }
    }
    public:
    int isCircle(int N, vector<string> A)
    {
        // code here
        vector<int> adj[26];
        vector<int> V(26);
        vector<int> in(26);
        int s = A[0][0]-'a';
        for(int i = 0; i < A.size(); ++i) {
            adj[A[i][0]-'a'].push_back(A[i][A[i].size()-1]-'a');
            in[A[i][A[i].size()-1]-'a']++;
            V[A[i][0]-'a'] = V[A[i][A[i].size()-1]-'a'] = 1;
        }
        vector<int> v(26);
        v[s] = 1;
        dfs(adj, s, v);
        for(int i = 0; i < 26; ++i) {
            if (v[i] == 0 && V[i] == 1) return 0;
        }
        for(int i = 0; i < 26; ++i) {
            if (V[i] == 1) {
                if (adj[i].size() != in[i]) return 0;
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends
