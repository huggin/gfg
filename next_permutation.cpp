//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  vector<int> nextPermutation(int N, vector<int> arr) {
    // code here
    if (N == 1) return arr;
    int pos = -1;
    for (int i = N - 2; i >= 0; --i) {
      if (arr[i + 1] > arr[i]) {
        pos = i;
        break;
      }
    }
    if (pos == -1) {
      reverse(arr.begin(), arr.end());
      return arr;
    }
    sort(arr.begin() + pos + 1, arr.end());
    for (int i = pos + 1; i < N; ++i) {
      if (arr[pos] < arr[i]) {
        swap(arr[pos], arr[i]);
        break;
      }
    }

    return arr;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++) cin >> arr[i];

    Solution ob;
    vector<int> ans = ob.nextPermutation(N, arr);
    for (int u : ans) cout << u << " ";
    cout << "\n";
  }
  return 0;
}
// } Driver Code Ends
