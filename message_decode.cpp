//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

bool decode(string s);
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    cout << decode(s) << endl;
  }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends

bool decode(string S) {
  // your code here
  string p = "hello";
  int n = S.size();
  int j = 0;
  for (int i = 0; i < n && j < p.size(); ++i) {
    if (S[i] == p[j]) {
      ++j;
    }
  }
  if (j == p.size()) return true;
  return false;
}
