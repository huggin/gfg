//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template in C++

class Solution {
public:
  // Function to return the position of the first repeating element.
  int firstRepeated(int arr[], int n) {
    // code here
    int ans = INT_MAX;
    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i) {
      if (m.find(arr[i]) == m.end()) {
        m[arr[i]] = i + 1;
      } else {
        ans = min(ans, m[arr[i]]);
      }
    }
    if (ans == INT_MAX)
      return -1;
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

    int arr[n];

    for (int i = 0; i < n; ++i)
      cin >> arr[i];
    Solution ob;
    cout << ob.firstRepeated(arr, n) << "\n";
  }

  return 0;
}

// } Driver Code Ends
