//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template 

class Solution{
    const int mod = 1000000007;
    string S;
    int n;
    long long dp[100001][3];
    int last_c = -1;
    
    int solve(int k, int u) {
        if (k > last_c) return 0;
        if (k == last_c) {
            if (u==2) 
                return 1;
            else
                return 0;
        }
        if (dp[k][u] != -1) return dp[k][u];
        if (u == 0) {
            if (S[k] == 'a') {
                dp[k][u] = ((solve(k+1, u) * 2) % mod  + solve(k+1, u+1)) % mod;
            } else {
                dp[k][u] = solve(k+1, u) % mod;
            }
        } else if (u==1) {
            if (S[k] == 'b') {
                dp[k][u] = ((solve(k+1, u) * 2) % mod + solve(k+1, u+1)) % mod;
            } else {
                dp[k][u] = solve(k+1, u) % mod;
            }
        } else {
            if (S[k] == 'c') {
                if (k == last_c) return dp[k][u] = 1;
                if (k > last_c) return dp[k][u] = 0;
                dp[k][u] = (2 * solve(k+1, u) + 1) % mod;
            } else {
                dp[k][u] = solve(k+1, u) % mod;
            }
        }
        return dp[k][u];
    }
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) {
        //code here
        S = s;
        n = s.size();
        memset(dp, -1, sizeof(dp));
        
        for(int i = n-1; i>=0; --i) {
            if (s[i] == 'c') {
                last_c = i;
                break;
            }
        }
        if (last_c == -1) return 0;
        
        return solve(0, 0);
    }
};

//{ Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends
