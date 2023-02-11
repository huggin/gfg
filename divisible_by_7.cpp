//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
 public:
  int isdivisible7(string num) {
    // complete the function here
    int n;
    int r = 0;
    for (int i = 0; i < num.size(); i += 7) {
      stringstream ss;
      ss << num.substr(i, 7);
      ss >> n;

      if (num.size() - i <= 7) {
        n += (int)pow(10, num.size() - i) * r;
      } else {
        n += 10000000 * r;
      }
      r = n % 7;
    }
    if (r == 0) {
      return 1;
    }
    return 0;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    Solution ob;
    cout << ob.isdivisible7(s) << endl;
  }
  return 0;
}
// } Driver Code Ends
