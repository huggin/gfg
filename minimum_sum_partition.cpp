//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int total = accumulate(arr, arr+n, 0);
        vector<int> dp(total + 1);
        dp[0] = 1;
	    for(int i=0; i<n; ++i) {
	        for(int j=dp.size()-1; j-arr[i]>=0; --j) {
	            if (dp[j - arr[i]] == 1) {
	                dp[j] = 1;
	            }
	        }
	    }
	    int ans = INT_MAX;
	    for(int i=0; i<dp.size(); ++i) {
	        if (dp[i] == 1) {
	            //cout << i << endl;
	            ans = min(ans, abs(total - i - i));
	        }
	    }
	    return ans;
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

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
