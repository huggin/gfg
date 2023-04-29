//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  vector<int> countDistinct(int A[], int n, int k) {
    // code here.
    unordered_map<int, int> m;
    vector<int> ans(n - k + 1);
    for (int i = 0; i < k; ++i) {
      m[A[i]]++;
    }
    for (int i = k; i < n; ++i) {
      ans[i - k] = m.size();
      if (--m[A[i - k]] == 0) {
        m.erase(A[i - k]);
      }
      m[A[i]]++;
    }

    ans[n - k] = m.size();
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
    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    Solution obj;
    vector<int> result = obj.countDistinct(a, n, k);
    for (int i : result)
      cout << i << " ";
    cout << endl;
  }
  return 0;
}
// } Driver Code Ends
