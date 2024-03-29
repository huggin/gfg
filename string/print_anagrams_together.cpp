//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  vector<vector<string>> Anagrams(vector<string> &s) {
    // code here
    vector<vector<string>> ans;
    map<string, int> m;
    vector<string> s2 = s;
    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
      sort(s[i].begin(), s[i].end());
      if (m.find(s[i]) == m.end()) {
        m[s[i]] = count++;
        ans.push_back(vector<string>{s2[i]});
      } else {
        int line = m[s[i]];
        ans[line].push_back(s2[i]);
      }
    }

    sort(ans.begin(), ans.end());
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> string_list(n);
    for (int i = 0; i < n; ++i)
      cin >> string_list[i];
    Solution ob;
    vector<vector<string>> result = ob.Anagrams(string_list);
    sort(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
      for (int j = 0; j < result[i].size(); j++) {
        cout << result[i][j] << " ";
      }
      cout << "\n";
    }
  }

  return 0;
}

// } Driver Code Ends
