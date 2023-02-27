//{ Driver Code Starts

// CPP program to print all bitwise
// subsets of N (Efficient approach)

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// fucntion to find bitwise subsets
// Efficient approach
class Solution {
 public:
  vector<int> printSubsets(int n) {
    // Code here
    set<int> s;
    for (int i = 0; i <= n; ++i) s.insert(i & n);
    vector<int> ans(s.rbegin(), s.rend());
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  Solution ob;
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    vector<int> v;
    v = ob.printSubsets(n);
    for (int i : v) cout << i << " ";
    cout << endl;
  }

  return 0;
}

// } Driver Code Ends
