//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  int solve(const vector<int> &a, int k) {
    vector<int> c(a.size() + 1);
    int ans = 0;
    for (int i = 0, j = 0; i < a.size(); ++i) {
      if (c[a[i]]++ == 0) {
        --k;
      }
      if (k >= 0)
        ans += i - j + 1;
      else {
        while (--c[a[j]] != 0) {
          ++j;
        }
        ++j;
        ++k;
        ans += i - j + 1;
      }
    }
    return ans;
  }

public:
  int subarrayCount(vector<int> &arr, int N, int k) {
    // code here
    if (k == 0)
      return solve(arr, 1);
    return solve(arr, k) - solve(arr, k - 1);
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, k;
    cin >> N >> k;

    vector<int> arr(N);
    for (int i = 0; i < N; i++)
      cin >> arr[i];

    Solution obj;
    cout << obj.subarrayCount(arr, N, k) << endl;
  }
  return 0;
}
// } Driver Code Ends
