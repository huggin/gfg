//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    int dp[1001][1001];
    int solve(const string&s, int i, int j) {
        if (j == s.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int& ans = dp[i][j];
        ans = 0;
        ans = solve(s, i, j+1);
        for(int k = i; k < j; ++k) {
            if (s[k] == s[j]) {
                return ans = max(ans, solve(s, k+1, j+1) + 1);
            } else {
                ans = max(ans, solve(s, k+1, j));
            }
        }
        return ans;
    }
public:
	int LongestRepeatingSubsequence(string str){
		   // Code here
	    memset(dp, -1, sizeof(dp));
	    return solve(str, 0, 1);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
