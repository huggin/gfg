//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
 public:
  vector<int> nearestPerfectSquare(int N) {
    // code here
    int i = sqrt(N);
    if (i * i == N) return vector<int>{N, 0};
    int a = N - i * i;
    int b = (i + 1) * (i + 1) - N;
    if (a > b) return vector<int>{b + N, b};
    return vector<int>{N - a, a};
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    Solution ob;
    vector<int> ans = ob.nearestPerfectSquare(N);
    cout << ans[0] << " " << ans[1] << "\n";
  }
}
// } Driver Code Ends
