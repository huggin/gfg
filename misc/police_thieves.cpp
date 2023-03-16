//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  int catchThieves(char arr[], int n, int k) {
    // Code here
    int ans = 0;
    for (int i = 0, j = 0; i < n && j < n;) {
      while (i < n && arr[i] != 'T') {
        ++i;
      }
      while (j < n && arr[j] != 'P') {
        ++j;
      }
      if (i == n || j == n) break;
      if (abs(i - j) <= k) {
        ++ans;
        arr[i] = '\0';
        arr[j] = '\0';
        ++i;
        ++j;
      } else {
        if (i < j) {
          ++i;
        } else {
          ++j;
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
    char arr[n];
    for (int i = 0; i < n; ++i) cin >> arr[i];
    Solution obj;
    cout << obj.catchThieves(arr, n, k) << endl;
  }
  return 0;
}

// } Driver Code Ends
