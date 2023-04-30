//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
  string chooseandswap(string a) {
    // Code Here
    int c[26] = {0};
    for (int i = 0; i < a.size(); ++i) {
      ++c[a[i] - 'a'];
    }
    char c1 = '\0', c2 = '\0';
    for (int i = 0; i < a.size(); ++i) {
      for (int j = 0; j < 26; ++j) {
        if (c[j] == 0)
          continue;
        if (j + 'a' == a[i]) {
          c[j] = 0;
          break;
        } else if (j + 'a' < a[i]) {
          c1 = 'a' + j;
          c2 = a[i];
          break;
        }
      }
      if (c1 != '\0')
        break;
    }
    // cout << c1 << ' ' << c2 << endl;
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] == c1) {
        a[i] = c2;
      } else if (a[i] == c2) {
        a[i] = c1;
      }
    }
    return a;
  }
};

//{ Driver Code Starts.

int main() {
  Solution obj;
  int t;
  cin >> t;
  while (t--) {
    string a;
    cin >> a;
    cout << obj.chooseandswap(a) << endl;
  }
  return 0;
}

// } Driver Code Ends
