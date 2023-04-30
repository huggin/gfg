//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  long long nthFortunateNum(int n) {
    // code here
    vector<long long> v{3,  5,  7,  13, 23, 17, 19, 23,
                        37, 61, 67, 61, 71, 47, 107};
    return v[n - 1];
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;

    cin >> n;

    Solution ob;
    cout << ob.nthFortunateNum(n) << endl;
  }
  return 0;
}
// } Driver Code Ends
