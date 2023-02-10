//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    vector<vector<int>> c;
    vector<int> marked;
    int path;
    int ans;
    
    void dfs(int k, int nv) {
        if (nv == c.size()) {
            ans = min(ans, path + c[k][0]);
            return;
        }
        marked[k] = 1;
        for(int i = 1; i < c.size(); ++i) {
            if (!marked[i]) {
                path += c[k][i];
                dfs(i, nv+1);
                path -= c[k][i];
            }
        }
        marked[k] = 0;
    }
    
public:
int total_cost(vector<vector<int>>cost){
    // Code here
    c = cost;
    int n = cost.size();
    marked.assign(n, 0);
    path = 0;
    ans = INT_MAX;
    dfs(0, 1);
    return ans;
}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>cost(n, vector<int>(n, 0));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)cin >> cost[i][j];
		Solution obj;
		int ans = obj.total_cost(cost);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
