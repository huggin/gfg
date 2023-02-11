//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution {
 public:
  int shortestDistance(vector<string> &s, string word1, string word2) {
    // Your code goes here
    int ans = s.size();
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] != word1 && s[i] != word2) {
        continue;
      } else if (s[i] == word1) {
        for (int j = i; j < s.size(); ++j) {
          if (s[j] == word2) {
            ans = min(ans, abs(i - j));
          }
        }
      } else {
        // cout << "haha"  << s[i] << endl;
        for (int j = i; j < s.size(); ++j) {
          if (s[j] == word1) {
            ans = min(ans, abs(i - j));
          }
        }
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    string word1, word2;

    cin >> word1 >> word2;

    Solution ob;

    cout << ob.shortestDistance(s, word1, word2) << "\n";
  }

  return 0;
}
// } Driver Code Ends
