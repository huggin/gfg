//{ Driver Code Starts
#include <iostream>
using namespace std;

// } Driver Code Ends

#include <algorithm>

class Solution {
  long long cNr(int n, int k) {
    long long ans = 1;
    for (int i = 0; i < k; ++i) {
      ans *= (n - i);
    }
    for (int i = 0; i < k; ++i) {
      ans /= (i + 1);
    }
    return ans;
  }

public:
  long posIntSol(string s) {
    int n = count(s.begin(), s.end(), '+') + 1;
    int k = atoi(s.substr(s.find("=") + 1).c_str());
    // cout << n << ' ' << k << endl;
    return cNr(k - 1, n - 1);
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    string s;
    cin >> s;
    Solution ob;
    cout << ob.posIntSol(s) << endl;
  }
  return 0;
}

// } Driver Code Ends
