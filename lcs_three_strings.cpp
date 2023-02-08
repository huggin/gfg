//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int LCSof3 (string A, string B, string C, int n1, int n2, int n3);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        cout << LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

int dp[21][21][21];
int na, nb, nc;
string a, b, c;

int solve(int i, int j, int k) {
    if (i == na || j == nb || k == nc) return 0;
    if (dp[i][j][k] != -1) return dp[i][j][k];
    if (a[i] == b[j] && a[i] == c[k]) return dp[i][j][k] = solve(i+1, j+1, k+1) + 1;
    int& ans = dp[i][j][k];
    ans = solve(i+1, j, k);
    ans = max(ans, solve(i, j+1, k));
    ans = max(ans, solve(i, j, k+1));
    return ans;
}

int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
{
    // your code here
    memset(dp, -1, sizeof(dp));
    na = n1;
    nb = n2;
    nc = n3;
    a = A;
    b = B;
    c = C;
    return solve(0, 0, 0);
    
}
