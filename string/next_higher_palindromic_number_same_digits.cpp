//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
public:
  string nextPalin(string N) {
    // complete the function here
    int len = N.size();
    int k = len / 2;
    if (len % 2 != 0) {
      ++k;
    }
    int p = -1;
    for (int i = 1; i < len / 2; ++i) {
      if (N[i] > N[i - 1]) {
        p = i - 1;
      }
    }
    if (p == -1)
      return "-1";
    sort(N.begin() + p + 1, N.begin() + len / 2);
    for (int i = p + 1; i < len / 2; ++i) {
      if (N[i] > N[p]) {
        swap(N[i], N[p]);
        break;
      }
    }
    for (int i = 0; i < len / 2; ++i) {
      N[len - 1 - i] = N[i];
    }
    return N;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    Solution obj;
    cout << obj.nextPalin(s) << endl;
  }
  return 0;
}
// } Driver Code Ends
