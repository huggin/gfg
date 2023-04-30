//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int checkMirrorTree(int n, int e, int A[], int B[]) {
    // code here

    vector<int> adj_A[n + 1], adj_B[n + 1];
    for (int i = 0; i < e * 2; i += 2) {
      adj_A[A[i]].push_back(A[i + 1]);
      adj_B[B[i]].push_back(B[i + 1]);
    }
    for (int i = 1; i <= n; ++i) {
      if (adj_A[i].size() != adj_B[i].size())
        return 0;
      int m = adj_A[i].size();
      for (int j = 0; j < m; ++j) {
        if (adj_A[i][j] != adj_B[i][m - 1 - j])
          return 0;
      }
    }

    return 1;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, e;

    cin >> n >> e;
    int A[2 * e], B[2 * e];

    for (int i = 0; i < 2 * e; i++)
      cin >> A[i];

    for (int i = 0; i < 2 * e; i++)
      cin >> B[i];

    Solution ob;
    cout << ob.checkMirrorTree(n, e, A, B) << endl;
  }
  return 0;
}
// } Driver Code Ends
