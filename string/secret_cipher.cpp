//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

// return a string formed by compressing string s
// do not print anything

class Solution {
public:
  string compress(string s) {
    // Your code goes here
    int n = s.size();
    vector<long long> hash(n);
    int p = 31;
    int m = 1e9 + 9;
    vector<long long> ppow(n, 1);
    hash[0] = s[0] - 'a' + 1;

    for (int i = 1; i < n; i++) {
      ppow[i] = (ppow[i - 1] * p) % m;
      hash[i] = (hash[i - 1] + (s[i] - 'a' + 1) * ppow[i]) % m;
    }

    string ans = "";
    int i = n - 1;

    while (i >= 0) {
      if (i % 2 == 1) {
        if ((long long)hash[i / 2] * ppow[i / 2 + 1] % m ==
            (hash[i] - hash[i / 2] + m) % m) {
          ans += '*';
          i /= 2;
          continue;
        }
      }

      ans += s[i--];
    }

    reverse(ans.begin(), ans.end());
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    Solution obj;
    cout << obj.compress(s) << "\n";
  }
  return 0;
}

// } Driver Code Ends
