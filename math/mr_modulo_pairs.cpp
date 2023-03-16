//{ Driver Code Starts
#include <bits/stdc++.h>
#include <math.h>
#include <stdio.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  int printPairs(int arr[], int n, int k) {
    // code here.
    int ans = 0;
    unordered_set<int> s;
    for (int i = 0; i < n; ++i) s.insert(arr[i]);

    for (int i = 0; i < n; ++i) {
      if (arr[i] == k) {
        ans += count_if(arr, arr + n, [=](int x) { return x > k; });
      } else if (arr[i] > k) {
        int d = arr[i] - k;
        for (int j = 1; j * j <= d; ++j) {
          if (d % j == 0) {
            if (j > k) ans += s.count(j);
            if (j * j != d && d / j > k) ans += s.count(d / j);
          }
        }
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
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; ++i) cin >> a[i];
    Solution ob;
    cout << ob.printPairs(a, n, k) << endl;
  }
  return 0;
}

// } Driver Code Ends
