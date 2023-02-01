//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {
        // Complet the function
        int total = 0;
        for(int i = 0; i < n; ++i) {
            if (arr[i] <= k) {
                ++total;
            }
        }
        int bad = 0;
        for(int i = 0; i < total; ++i) {
            if (arr[i] > k) {
                ++bad;
            }
        }
        int ans = bad;
        for(int i = total; i < n; ++i) {
            if (arr[i-total] > k) --bad;
            if (arr[i] > k) ++bad;
            ans = min(ans, bad);
        }
        return ans;
    }
};


//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends
