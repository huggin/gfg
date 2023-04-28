//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  int countFlips(int a[], int n) {
    // code here.
    int ans = 0;
    int prev = 1;
    for (int i = 0; i < n; ++i) {
      if (a[i] != prev) {
        ++ans;
        prev = a[i];
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
      cin >> a[i];
    Solution ob;
    cout << ob.countFlips(a, n) << endl;
  }
  return 0;
}

// } Driver Code Ends
