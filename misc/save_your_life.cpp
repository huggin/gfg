//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  string maxSum(string w, char x[], int b[], int n) {
    // code here
    int sz = w.size();
    vector<int> a(sz);
    for (int j = 0; j < sz; ++j) {
      int i = 0;
      for (; i < n; ++i) {
        if (w[j] == x[i]) {
          a[j] = b[i];
          break;
        }
      }
      if (i == n) {
        a[j] = w[j];
      }
    }

    int ans = INT_MIN;
    int start = -1;
    int end = -1;
    int prefix = 0;

    int start2 = 0;
    for (int i = 0; i < sz; ++i) {
      if (prefix + a[i] >= 0) {
        prefix += a[i];
        if (prefix > ans) {
          ans = prefix;
          start = start2;
          end = i;
        }
      } else {
        prefix = 0;
        start2 = i + 1;
        if (a[i] > ans) {
          ans = a[i];
          start = i;
          end = i;
        }
      }
    }

    // cout << ans << ' ' << start << ' ' << end << endl;
    return w.substr(start, end - start + 1);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    string w;
    cin >> w;
    int n;
    cin >> n;
    char x[n];
    int b[n];
    for (int i = 0; i < n; i++)
      cin >> x[i];
    for (int i = 0; i < n; i++)
      cin >> b[i];
    Solution ob;
    cout << ob.maxSum(w, x, b, n) << endl;
  }
  return 0;
}
// } Driver Code Ends
