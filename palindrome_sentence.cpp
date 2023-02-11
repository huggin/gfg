//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution {
 public:
  bool sentencePalindrome(string s) {
    // code here
    int n = s.size();
    int i = 0, j = n - 1;
    while (i < j) {
      while (i < n && !isalpha(s[i])) ++i;
      while (j >= 0 && !isalpha(s[j])) --j;
      if (i >= j) return true;
      if (s[i] != s[j]) return false;
      ++i;
      --j;
    }
    return true;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  cin.ignore();
  while (t--) {
    string str;
    getline(cin, str);
    Solution ob;
    cout << ob.sentencePalindrome(str) << endl;
  }
  return 0;
}

// } Driver Code Ends
