//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  void multi(int ans[], const string& s1, const string& s2, int k, int more) {
    int d = s1[k] - '0';
    for (int i = 0; i < s2.size(); ++i) {
      int t = ans[i + k] + (s2[i] - '0') * d + more;
      more = t / 10;
      ans[k + i] = t % 10;
    }
    if (more > 0) {
      ans[s2.size() + k] = more;
    }
  }

 public:
  /*You are required to complete below function */
  string multiplyStrings(string s1, string s2) {
    // Your code here
    int f = 1;
    if (s1[0] == '-') {
      f *= -1;
    }
    if (s2[0] == '-') {
      f *= -1;
    }
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    if (s1[s1.size() - 1] == '-') s1.pop_back();
    if (s2[s2.size() - 1] == '-') s2.pop_back();

    int ans[2001] = {0};
    int more = 0;
    for (int i = 0; i < s1.size(); ++i) {
      multi(ans, s1, s2, i, more);
    }
    string s;
    for (int i = 0; i < 2001; ++i) {
      s.push_back(ans[i] + '0');
    }

    while (s[s.size() - 1] == '0') {
      s.pop_back();
    }
    if (s.size() == 0) return "0";
    if (f == -1) s.push_back('-');
    reverse(s.begin(), s.end());
    return s;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    string a;
    string b;
    cin >> a >> b;
    Solution obj;
    cout << obj.multiplyStrings(a, b) << endl;
  }
}
// } Driver Code Ends
