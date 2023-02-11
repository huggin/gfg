//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  int Maximize(int a[], int n) {
    // Complete the function
    const int M = 1e9 + 7;
    sort(a, a + n);
    long long ans = 0;
    for (long long i = n - 1; i >= 0; --i) {
      ans += i * a[i];
    }
    return ans % M;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    Solution ob;
    cout << ob.Maximize(a, n) << endl;
  }
}
// } Driver Code Ends
