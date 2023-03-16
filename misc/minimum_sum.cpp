//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
 public:
  string solve(int arr[], int n) {
    // code here
    sort(arr, arr + n);
    vector<int> a, b;

    for (int i = 0; i < n; i += 2) {
      a.push_back(arr[i]);
      if (i + 1 < n) {
        b.push_back(arr[i + 1]);
      }
    }

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    char c[n / 2 + 2];
    int more = 0;
    for (int i = 0; i < b.size(); ++i) {
      int t = (a[i] + b[i] + more);
      if (t >= 10) {
        more = 1;
        c[i] = t - 10 + '0';
      } else {
        more = 0;
        c[i] = t + '0';
      }
    }
    int len_c = b.size();
    if (a.size() > b.size()) {
      int t = more + a[a.size() - 1];
      if (t >= 10) {
        c[a.size() - 1] = t - 10 + '0';
        c[a.size()] = '1';
        more = 0;
        len_c = a.size() + 1;
      } else {
        c[a.size() - 1] = t + '0';
        more = 0;
        len_c = a.size();
      }
    }
    if (more == 1) {
      c[len_c] = 1 + '0';
      len_c++;
    }
    while (c[len_c - 1] == '0') {
      --len_c;
    }
    reverse(c, c + len_c);
    return string(c, c + len_c);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    Solution ob;
    auto ans = ob.solve(arr, n);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
