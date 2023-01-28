//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int findMaximum(int arr[], int n) {
	    // code here
	    int lo = 0, hi = n - 1;
	    while(lo < hi) {
	        int mid1 = lo + (hi - lo) / 3;
	        int mid2 = hi - (hi - lo) / 3;
	        if (arr[mid1] <  arr[mid2]) lo = mid1+1;
	        else if (arr[mid1] > arr[mid2]) hi = mid2-1;
	        else {
	            lo = mid1+1;
	            hi = mid2-1;
	        }
	    }

	    return arr[lo];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaximum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
