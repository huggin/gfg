//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  int find(int parent[], int i) {
    while (parent[i] != i) {
      parent[i] = parent[parent[i]];
      i = parent[i];
    }
    return i;
  }

  void merge(int parent[], int i, int j) {
    i = find(parent, i);
    j = find(parent, j);
    if (i == j)
      return;
    if (i < j)
      parent[j] = i;
    else
      parent[i] = j;
  }

public:
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    // code here

    int n = accounts.size();
    int parent[n];
    for (int i = 0; i < n; ++i)
      parent[i] = i;

    vector<unordered_set<string>> vus;
    for (auto &a : accounts) {
      unordered_set<string> s(a.begin() + 1, a.end());
      vus.emplace_back(s);
    }

    for (int i = 1; i < n; ++i) {
      bool found = false;
      for (int j = 0; j < i; ++j) {
        if (accounts[i][0] != accounts[j][0])
          continue;
        if (vus[j].empty())
          continue;
        for (int k = 1; k < accounts[i].size(); ++k) {
          if (vus[j].find(accounts[i][k]) != vus[j].end()) {
            merge(parent, i, j);
          }
        }
      }
    }

    vector<vector<string>> ans;
    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i) {
      if (parent[i] == i) {
        ans.push_back(accounts[i]);
        m[i] = ans.size() - 1;
      } else {
        int id = find(parent, i);
        for (int j = 1; j < accounts[i].size(); ++j) {
          ans[m[id]].push_back(accounts[i][j]);
        }
      }
    }
    for (int i = 0; i < ans.size(); ++i) {
      sort(ans[i].begin() + 1, ans[i].end());
      auto it = unique(ans[i].begin() + 1, ans[i].end());
      ans[i].erase(it, ans[i].end());
    }
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
    vector<vector<string>> accounts;

    for (int i = 0; i < n; i++) {
      vector<string> temp;
      int x;
      cin >> x;

      for (int j = 0; j < x; j++) {
        string s1;
        cin >> s1;
        temp.push_back(s1);
      }
      accounts.push_back(temp);
    }

    Solution obj;
    vector<vector<string>> res = obj.accountsMerge(accounts);
    sort(res.begin(), res.end());
    cout << "[";
    for (int i = 0; i < res.size(); ++i) {
      cout << "[";
      for (int j = 0; j < res[i].size(); j++) {
        if (j != res[i].size() - 1)
          cout << res[i][j] << ","
               << " ";
        else
          cout << res[i][j];
      }
      if (i != res.size() - 1)
        cout << "], " << endl;
      else
        cout << "]";
    }
    cout << "]" << endl;
  }
}
// } Driver Code Ends
