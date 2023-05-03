//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  bool isPrimeString(int N, string str) {
    // code here.
    int n = accumulate(str.begin(), str.end(), 0);
    if (n == 0 || n == 1)
      return false;
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0)
        return false;
    }
    return true;
  }
};

//{ Driver Code Starts.

int main() {
  int T;
  cin >> T;
  while (T--) {
    string str;
    int n;
    cin >> n >> str;
    Solution ob;
    if (ob.isPrimeString(n, str))
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
  return 0;
}

// } Driver Code Ends
