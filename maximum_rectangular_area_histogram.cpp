//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
 public:
  // Function to find largest rectangular area possible in a given histogram.
  long long getMaxArea(long long arr[], int n) {
    // Your code here
    vector<int> left(n), right(n);
    stack<int> s, s2;
    for (int i = 0; i < n; ++i) {
      while (!s.empty() && arr[s.top()] >= arr[i]) {
        s.pop();
      }

      left[i] = s.empty() ? 0 : s.top() + 1;
      s.push(i);
    }

    for (int i = n - 1; i >= 0; --i) {
      while (!s2.empty() && arr[s2.top()] >= arr[i]) {
        s2.pop();
      }

      right[i] = s2.empty() ? n - 1 : s2.top() - 1;
      s2.push(i);
    }

    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      // cout << left[i] << ' ' << right[i] << endl;
      ans = max(ans, (right[i] - left[i] + 1) * arr[i]);
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  long long t;

  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    long long arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution ob;
    cout << ob.getMaxArea(arr, n) << endl;
  }
  return 0;
}

// } Driver Code Ends
