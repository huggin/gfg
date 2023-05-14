//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  bool ok(int c1[], int c2[]) {
    for (int i = 0; i < 256; ++i) {
      if (c1[i] != 0 && c2[i] == 0)
        return false;
    }
    return true;
  }

public:
  int findSubString(string str) {
    // Your code goes here
    int count[256] = {0};
    int count2[256] = {0};
    for (int i = 0; i < str.size(); ++i) {
      count[str[i]]++;
    }

    // cout << t << endl;
    int i = 0, j = 0;
    int ans = str.size();
    for (; i < str.size(); ++i) {
      count2[str[i]]++;
      if (ok(count, count2)) {
        // cout << i << ' ' << j << endl;
        ans = min(ans, i - j + 1);
        while (--count2[str[j]] > 0) {
          ++j;
          ans = min(ans, i - j + 1);
        }
        ++j;
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.
// Driver code
int main() {
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    Solution ob;
    cout << ob.findSubString(str) << endl;
  }
  return 0;
}
// } Driver Code Ends
