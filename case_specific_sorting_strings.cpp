//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  // Function to perform case-specific sorting of strings.
  string caseSort(string str, int n) {
    // your code here
    string up, lo;
    for (char c : str) {
      if (isupper(c)) {
        up.push_back(c);
      } else {
        lo.push_back(c);
      }
    }
    sort(begin(up), end(up));
    sort(begin(lo), end(lo));
    int i = 0, j = 0;
    for (char& c : str) {
      if (isupper(c)) {
        c = up[i++];
      } else {
        c = lo[j++];
      }
    }
    return str;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string str;
    cin >> str;
    Solution obj;
    cout << obj.caseSort(str, n) << endl;
  }
}
// } Driver Code Ends
