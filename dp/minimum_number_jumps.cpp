//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
 public:
  int minJumps(int arr[], int n) {
    // Your code here
    int curr = 0;
    int ans = 0;
    int start = 0;
    while (curr < n - 1) {
      ++ans;
      int ma = 0;
      for (int i = start; i <= curr; ++i) {
        ma = max(ma, i + arr[i]);
      }
      start = curr + 1;
      if (ma <= curr) return -1;
      curr = ma;
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i, j;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    Solution obj;
    cout << obj.minJumps(arr, n) << endl;
  }
  return 0;
}

// } Driver Code Ends
