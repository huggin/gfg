//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return maximum XOR subset in set[]

class Solution {
 public:
  int maxSubsetXOR(int arr[], int N) {
    // Your code here
    int ans = 0;
    while (true) {
      int ma = *max_element(arr, arr + N);
      if (ma == 0) return ans;
      ans = max(ans, ans ^ ma);
      for (int i = 0; i < N; ++i) {
        arr[i] = min(arr[i], arr[i] ^ ma);
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t, n, a[100004], k;
  scanf("%d", &t);
  while (t--) {
    // cin>>n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }
    Solution obj;
    printf("%d\n", obj.maxSubsetXOR(a, n));
    // cout<<bin(a,0,n-1,k)<<endl;
  }
}
// } Driver Code Ends
