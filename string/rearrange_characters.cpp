//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution {
public:
  string rearrangeString(string str) {
    // code here
    int c[26] = {0};
    int n = str.size();
    for (int i = 0; i < n; ++i) {
      c[str[i] - 'a']++;
    }
    int m = *max_element(c, c + 26);
    priority_queue<pair<int, char>> Q;
    for (int i = 0; i < 26; ++i) {
      if (c[i] != 0) {
        Q.emplace(c[i], i + 'a');
      }
    }
    if (n % 2 == 0 && m > n / 2)
      return "-1";
    if (m > n / 2 + 1)
      return "-1";
    string ans(n, ' ');
    int k = 0;
    while (!Q.empty()) {
      auto c = Q.top();
      Q.pop();
      auto c2 = Q.top();
      Q.pop();
      ans[k++] = c.second;
      if (k == n)
        break;
      ans[k++] = c2.second;
      if (--c.first != 0) {
        Q.push(c);
      }
      if (--c2.first != 0) {
        Q.push(c2);
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    Solution ob;
    string str1 = ob.rearrangeString(str);
    int flag = 1;
    int c[26] = {0};
    for (int i = 0; i < str.length(); i++)
      c[str[i] - 'a'] += 1;
    int f = 0;
    int x = (str.length() + 1) / 2;
    for (int i = 0; i < 26; i++) {
      if (c[i] > x)
        f = 1;
    }
    if (f) {
      if (str1 == "-1")
        cout << 0 << endl;
      else
        cout << 1 << endl;
    } else {
      int a[26] = {0};
      int b[26] = {0};
      for (int i = 0; i < str.length(); i++)
        a[str[i] - 'a'] += 1;
      for (int i = 0; i < str1.length(); i++)
        b[str1[i] - 'a'] += 1;

      for (int i = 0; i < 26; i++)
        if (a[i] != b[i])
          flag = 0;

      for (int i = 0; i < str1.length(); i++) {
        if (i > 0)
          if (str1[i - 1] == str1[i])
            flag = 0;
      }
      if (flag == 1)
        cout << "1\n";
      else
        cout << "0\n";
    }
  }
  return 0;
}
// } Driver Code Ends
