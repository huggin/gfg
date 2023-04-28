//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  long long int maximizeSum(long long int a[], int n, int k) {
    // Your code goes here
    sort(a, a + n);
    long long ans = 0;
    long long small = INT_MAX;
    for (int i = 0; i < n; ++i) {
      small = min(small, abs(a[i]));
      if (a[i] < 0 && k-- > 0) {
        ans += (-a[i]);
      } else {
        ans += a[i];
      }
    }
    if (k % 2 == 1) {
      ans -= 2 * small;
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    long long int a[n + 5];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    Solution ob;
    cout << ob.maximizeSum(a, n, k) << endl;
  }

  return 0;
}
// } Driver Code Ends
