//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    int mem[1001][1001];
    string s1, s2;
public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        memset(mem, -1, sizeof(mem));
        s1 = S1;
        s2 = S2;
        return dp(n-1, m-1);
    }
    
    int dp(int i, int j) {
        if (i < 0 || j < 0) {
            return 0;
        }
        if (mem[i][j] != -1) {
            return mem[i][j];
        }
        int& ans = mem[i][j];
        ans = max(dp(i-1, j), dp(i, j-1));
        if (s1[i] == s2[j]) {
            int t = 0;
            for(int ii=i, jj=j; ii>=0 && jj>=0; ii--, jj--) {
                if (s1[ii] == s2[jj]) {
                    ++t;
                } else {
                    break;
                }
            }
            ans = max(t, ans);
        } 
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends
