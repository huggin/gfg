//{ Driver Code Starts
// Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  long long maxTripletProduct(long long arr[], int n) {
    // Complete the function
    sort(arr, arr + n);
    long long ans = LLONG_MIN;
    ans = max(ans, arr[0] * arr[1] * arr[2]);
    ans = max(ans, arr[n - 1] * arr[n - 2] * arr[n - 3]);
    ans = max(ans, arr[0] * arr[1] * arr[n - 1]);
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
    long long arr[n];
    for (i = 0; i < n; i++)
      cin >> arr[i];
    Solution ob;
    cout << ob.maxTripletProduct(arr, n);
    cout << "\n";
  }
  return 0;
}
// } Driver Code Ends
