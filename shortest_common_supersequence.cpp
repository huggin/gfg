//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    int dp[101][101];
    int M, N;
    string x, y;
    
    int solve(int i, int j) {
        if (i == M && j == N) return 0;
        if (i == M) return N - j;
        if (j == N) return M - i;
        if (dp[i][j] != -1) return dp[i][j];
        if (x[i] != y[j]) {
            dp[i][j] = min(solve(i+1, j), solve(i, j+1)) + 1;
        } else {
            dp[i][j] = solve(i+1, j+1) + 1;
        }
        //cout << i << ' '<< j << ' ' << dp[i][j] << endl;
        return dp[i][j];
    }
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        //code here
        M = m;
        N = n;
        x = X;
        y = Y;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0);
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends
