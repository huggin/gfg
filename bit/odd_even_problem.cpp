//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for c++
class Solution {
public:
  string oddEven(string S) {
    // code here
    vector<int> cnt(26);
    for (char c : S)
      cnt[c - 'a']++;

    int ans = 0;
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] == 0)
        continue;
      if (cnt[i] % 2 == 1 && i % 2 == 0 || cnt[i] % 2 == 0 && i % 2 == 1)
        ++ans;
    }
    return ans % 2 ? "ODD" : "EVEN";
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    string S;
    cin >> S;
    Solution ob;
    cout << ob.oddEven(S) << endl;
  }
  return 0;
}

// } Driver Code Ends
