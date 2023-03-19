//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  int findWinner(int n, int A[]) {
    // code here
    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i) {
      m[A[i]]++;
    }
    int total = 0;
    for (auto &p : m) {
      total += p.second % 2;
    }
    return total % 2 ? 2 : 1;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
      cin >> A[i];

    Solution ob;
    cout << ob.findWinner(n, A) << "\n";
  }
  return 0;
}
// } Driver Code Ends
