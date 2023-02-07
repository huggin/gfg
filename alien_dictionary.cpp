//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    string ans;
    void dfs(int k, vector<int> adj[], vector<int>& v) {
        v[k] = 1;
        for(auto w : adj[k]) {
            if (!v[w]) {
                dfs(w, adj, v);
            } 
        }
        ans.push_back('a'+k);
    }
public:
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        for(int i = 1; i < N; ++i) {
            for(int j = 0; j < dict[i-1].size() && j < dict[i].size(); ++j) {
                if (dict[i-1][j] != dict[i][j]) {
                    adj[dict[i-1][j]-'a'].push_back(dict[i][j]-'a');
                    break;
                }
            }
        }
        vector<int> marked(K);
        for(int i = 0; i < K; ++i) {
            if (!marked[i])
                dfs(i, adj, marked);
        }
        reverse(ans.begin(), ans.end());
        //cout << ans << endl;
        return ans;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
