//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  // function to do operations of rotate and delete
  // v: input vector
  // n: size of vector
  int rotateDelete(vector<long long> v, int n) {

    // Your code here
    if (n == 1)
      return v[0];
    if (n & 1) {
      return v[(n - 3) / 4 + 2];
    }
    return v[(n - 2) / 4 + 1];
  }
};

//{ Driver Code Starts.

int main() {
  int i, n, t, te;
  cin >> te;

  while (te--) {
    cin >> n;
    vector<long long> v;
    for (i = 0; i < n; i++) {
      cin >> t;
      v.push_back(t);
    }
    Solution ob;
    cout << ob.rotateDelete(v, n) << endl;
  }

  return 0;
}
// } Driver Code Ends
