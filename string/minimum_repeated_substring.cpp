//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  int minRepeats(string A, string B) {
    // code here
    int n = A.size();
    int m = B.size();
    int d = m / n;
    string s(A);
    s.reserve(m + n);
    for (int i = 1; i <= d + 1; ++i) {
      if (s.find(B) != string::npos) return i;
      s += A;
    }
    return -1;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  scanf("%d ", &t);
  while (t--) {
    string A, B;
    getline(cin, A);
    getline(cin, B);

    Solution ob;
    cout << ob.minRepeats(A, B) << endl;
  }
  return 0;
}
// } Driver Code Ends
