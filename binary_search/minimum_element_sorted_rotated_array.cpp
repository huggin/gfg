//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  int search(int arr[], int lo, int hi) {
    if (lo == hi) {
      return arr[lo];
    }
    if (lo + 1 == hi) {
      if (arr[lo] > arr[hi])
        return arr[hi];
      else
        return arr[lo];
    }
    int mi = lo + (hi - lo) / 2;
    if (arr[lo] < arr[mi])
      return search(arr, mi, hi);
    if (arr[mi] < arr[hi])
      return search(arr, lo, mi);
  }

public:
  int findMin(int arr[], int n) {
    // complete the function here
    if (arr[0] < arr[n - 1])
      return arr[0];
    return search(arr, 0, n - 1);
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int i, a[n];
    for (i = 0; i < n; i++) {
      cin >> a[i];
    }
    Solution ob;
    cout << ob.findMin(a, n) << endl;
  }
  return 0;
}
// } Driver Code Ends
