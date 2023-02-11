//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
 public:
  // Function to find the minimum indexed character.
  int minIndexChar(string str, string patt) {
    // Your code here
    sort(patt.begin(), patt.end());
    auto it = unique(patt.begin(), patt.end());
    patt.resize(it - patt.begin());
    for (int i = 0; i < str.size(); ++i) {
      for (int j = 0; j < patt.size(); ++j) {
        if (str[i] == patt[j]) return i;
      }
    }
    return -1;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    string str;
    string patt;
    cin >> str;
    cin >> patt;
    Solution obj;
    cout << obj.minIndexChar(str, patt) << endl;
  }
  return 0;
}

// } Driver Code Ends
