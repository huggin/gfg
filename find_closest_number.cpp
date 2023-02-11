//{ Driver Code Starts
#include <bits/stdc++.h>

#include <iostream>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  int findClosest(int arr[], int n, int target) {
    // Complete the function
    int lo = 0, hi = n - 1;
    int value = INT_MAX;
    int ans = -1;

    while (lo <= hi) {
      int mi = lo + (hi - lo) / 2;
      if (value > abs(arr[mi] - target) ||
          value == abs(arr[mi] - target) && arr[mi] > ans) {
        value = abs(arr[mi] - target);
        ans = arr[mi];
      }
      if (arr[mi] == target) return arr[mi];
      if (arr[mi] < target) {
        lo = mi + 1;
      } else {
        hi = mi - 1;
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
    int n, target;
    cin >> n >> target;
    int arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    Solution ob;
    cout << ob.findClosest(arr, n, target) << endl;
  }
}

// } Driver Code Ends
