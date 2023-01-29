//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    long long dp[501], dp2[501];
	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long ans = LONG_LONG_MIN;
	    
	    vector<int> a{0};
	    copy(arr.begin(), arr.end(), back_inserter(a));
	    for(int i = 1; i <= n; ++i) {
	        if (a[i-1] != 0) {
	            if (a[i] < 0) {
	                dp[i] =  dp2[i-1] * a[i];
	                dp2[i] = min((long long)a[i], dp[i-1] * a[i]);
	            } else if (a[i] > 0) {
	                dp[i] =  max((long long)a[i], dp[i-1] * a[i]);
	                dp2[i] = dp2[i-1] * a[i];
	            } else {
	                dp[i] = dp2[i] = 0;
	            }
	            ans = max(ans, dp[i]);
	        } else {
	            if (a[i] > 0) {
	                dp[i] = a[i];
	                dp2[i] = 0;
	            } else if (a[i] < 0) {
	                dp2[i] = a[i];
	                dp[i] = 0;
	            } else {
	                dp[i] = 0;
	                dp2[i] = 0;
	            } 
	            ans = max(ans, (long long)a[i]);
	        }
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
