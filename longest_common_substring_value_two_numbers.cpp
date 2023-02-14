//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
long long int longestCommon(long long int n1, long long int n2);
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n1, n2;
    cin >> n1 >> n2;

    cout << longestCommon(n1, n2) << endl;
  }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends

string getString(long long n) {
  string ans;
  while (n) {
    ans.push_back(n % 2 + '0');
    n /= 2;
  }
  reverse(ans.begin(), ans.end());
  return ans;
}

long long getNumber(const string& s) {
  long long ans = 0;
  for (int i = 0; i < s.size(); ++i) {
    ans = ans * 2 + (s[i] - '0');
  }
  return ans;
}

long long int longestCommon(long long int N, long long int M) {
  // your code here
  string s1 = getString(N);
  string s2 = getString(M);
  // cout << s1 << ' ' << s2 << endl;
  int n1 = s1.size(), n2 = s2.size();
  int maxLen = 0;
  long long ans = 0;
  for (int i = 0; i < n1; ++i) {
    for (int j = i; j < n1; ++j) {
      string t = s1.substr(i, j - i + 1);
      if (s2.find(t) != string::npos) {
        if (maxLen < j - i + 1) {
          maxLen = j + 1 - i;
          ans = getNumber(t);
        } else if (maxLen == j - i + 1) {
          long long temp = getNumber(t);
          if (temp > ans) {
            ans = temp;
          }
        }
      }
    }
  }
  // cout << maxLen << endl;
  return ans;
}
