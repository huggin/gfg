//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
	public:
	long long getCount(int N)
	{
		// Your code goes here
		vector<int> d[10] = { {0, 8}, {1, 2, 4}, {1, 2, 3, 5}, {3, 2, 6},
		    {1, 4, 5, 7}, {2, 5, 8, 4, 6}, {3, 5, 6, 9}, {4, 7, 8},
		    {5, 8, 0, 7, 9}, {6, 8, 9}};
		long long dp[30][10];
		for(int i = 0; i <= 9; ++i) {
		    dp[1][i] = 1;
		}
		for(int i = 2; i <= N; ++i) {
		    for(int j = 0; j<10; ++j) {
		        dp[i][j] = 0;
		        for(int k = 0; k < d[j].size(); ++k) {
		            dp[i][j] += dp[i-1][d[j][k]];
		        }
		    }
		}
		return accumulate(dp[N], dp[N]+10, 0LL);
	}

};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
