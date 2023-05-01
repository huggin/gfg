//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  long long calc(int h[], int cost[], int n, int k) {
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      ans += abs(h[i] - k) * cost[i];
    }
    return ans;
  }

public:
  long long int Bsearch(int n, int h[], int cost[]) {
    // Your code goes here
    auto it = minmax_element(h, h + n);
    long long lo = *it.first, hi = *it.second;
    long long ans = -1;
    while (lo <= hi) {
      int mid1 = lo + (hi - lo) / 3;
      int mid2 = hi - (hi - lo) / 3;
      long long t1 = calc(h, cost, n, mid1);
      long long t2 = calc(h, cost, n, mid2);
      if (t1 < t2) {
        hi = mid2 - 1;
      } else if (t1 > t2) {
        lo = mid1 + 1;
      } else {
        hi = mid2 - 1;
        lo = mid1 + 1;
        ans = t1;
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
    int n;
    cin >> n;

    int h[n], c[n];
    for (int i = 0; i < n; i++)
      cin >> h[i];

    for (int i = 0; i < n; i++)
      cin >> c[i];

    Solution ob;
    cout << ob.Bsearch(n, h, c);

    cout << "\n";
  }
  return 0;
}

// } Driver Code Ends
