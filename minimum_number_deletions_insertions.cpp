//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
	short dp[1001][1001];
    string s1, s2;
    
    int solve(int i, int j) {
        if (i < 0 && j < 0) return 0;
        if (i < 0 && j >= 0) return j + 1;
        if (i >= 0 && j < 0) return i + 1;
        if (dp[i][j] != -1) return dp[i][j];
        short& ans = dp[i][j];
        if (s1[i] == s2[j]) return solve(i - 1, j - 1);
        return ans = min(solve(i-1, j), solve(i, j-1)) + 1;
    }
	public:
	int minOperations(string str1, string str2) 
	{ 
	    // Your code goes here
	    memset(dp, -1, sizeof(dp));
	    s1 = str1;
	    s2 = str2;
	    return solve(str1.size(), str2.size());
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
