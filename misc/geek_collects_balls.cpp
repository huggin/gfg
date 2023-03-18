//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int maxBalls(int N, int M, vector<int> a, vector<int> b) {
    // code here
    int ans[2] = {0, 0};
    int i = 0, j = 0;
    while (i < N || j < M) {
      if (j == M)
        ans[0] += a[i++];
      else if (i == N)
        ans[1] += b[j++];
      else if (a[i] < b[j])
        ans[0] += a[i++];
      else if (a[i] > b[j])
        ans[1] += b[j++];
      else {
        int c = a[i], ii = 0, jj = 0;
        while (i < N && a[i] == c)
          ii++, i++;
        while (j < M && b[j] == c)
          jj++, j++;
        int t0 = max(ans[0] + ii * c, ans[1] + (jj + ii - 1) * c);
        int t1 = max(ans[1] + jj * c, ans[0] + (ii + jj - 1) * c);
        if (ii > 1 && jj > 1) {
          t0 = max(ans[0] + (ii + jj - 2) * c, ans[1] + (ii + jj - 1) * c);
          t1 = max(ans[1] + (ii + jj - 2) * c, ans[0] + (ii + jj - 1) * c);
        }
        ans[0] = t0;
        ans[1] = t1;
      }
    }
    return max(ans[0], ans[1]);
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int N, M;
    cin >> N >> M;
    vector<int> a(N), b(M);
    for (int i = 0; i < N; i++)
      cin >> a[i];
    for (int i = 0; i < M; i++)
      cin >> b[i];

    Solution ob;
    cout << ob.maxBalls(N, M, a, b) << "\n";
  }
  return 0;
}
// } Driver Code Ends
