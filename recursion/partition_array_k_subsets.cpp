//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this method */

class Solution {
  int *A;
  int N;
  int av;
  vector<int> ans;
  bool found;

  void solve(int i) {
    if (found)
      return;
    if (i == N) {
      found = true;
      return;
    };
    for (int j = 0; j < ans.size(); ++j) {
      if (ans[j] + A[i] <= av) {
        ans[j] += A[i];
        solve(i + 1);
        ans[j] -= A[i];
      }
    }
  }

public:
  bool isKPartitionPossible(int a[], int n, int k) {
    // Your code here
    int t = accumulate(a, a + n, 0);
    if (t % k != 0)
      return false;
    av = t / k;
    if (*max_element(a, a + n) > av)
      return false;
    sort(a, a + n, greater<int>());
    A = a;
    N = n;
    ans.resize(k);
    found = false;
    solve(0);
    return found;
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
    for (int i = 0; i < n; i++)
      cin >> a[i];
    int k;
    cin >> k;
    Solution obj;
    cout << obj.isKPartitionPossible(a, n, k) << endl;
  }
}
// } Driver Code Ends
