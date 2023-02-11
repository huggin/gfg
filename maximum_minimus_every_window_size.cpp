//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  // Function to find maximum of minimums of every window size.
  vector<int> maxOfMin(int arr[], int n) {
    // Your code here
    int left[n + 1], right[n + 1];
    for (int i = 0; i <= n; ++i) {
      left[i] = -1;
      right[i] = n;
    }
    stack<int> s1, s2;
    for (int i = 0; i < n; ++i) {
      while (!s1.empty() && arr[s1.top()] >= arr[i]) s1.pop();
      if (!s1.empty()) left[i] = s1.top();
      s1.push(i);
    }

    for (int i = n - 1; i >= 0; --i) {
      while (!s2.empty() && arr[s2.top()] >= arr[i]) s2.pop();
      if (!s2.empty()) right[i] = s2.top();
      s2.push(i);
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      int len = right[i] - left[i] - 1;
      ans[len - 1] = max(ans[len - 1], arr[i]);
    }

    for (int i = n - 2; i >= 0; --i) {
      if (ans[i] < ans[i + 1]) ans[i] = ans[i + 1];
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
    int a[n];
    for (int i = 0; i < n; i++) cin >> a[i];
    Solution ob;
    vector<int> res = ob.maxOfMin(a, n);
    for (int i : res) cout << i << " ";
    cout << endl;
  }
  return 0;
}

// } Driver Code Ends
