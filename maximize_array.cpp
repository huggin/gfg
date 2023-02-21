//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>

#include <unordered_map>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
 public:
  vector<int> maximizeArray(int arr1[], int arr2[], int n) {
    // code here
    priority_queue<int> Q;
    unordered_set<int> s;
    for (int i = 0; i < n; ++i) {
      Q.emplace(arr1[i]);
      Q.emplace(arr2[i]);
    }
    while (s.size() != n && !Q.empty()) {
      auto c = Q.top();
      Q.pop();
      if (s.find(c) == s.end()) s.insert(c);
    }
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
      auto it = s.find(arr2[i]);
      if (it != s.end()) {
        ans.push_back(arr2[i]);
        s.erase(it);
      }
    }
    for (int i = 0; i < n; ++i) {
      auto it = s.find(arr1[i]);
      if (it != s.end()) {
        ans.push_back(arr1[i]);
        s.erase(it);
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
    int n, i;
    cin >> n;
    int arr1[n], arr2[n];
    for (i = 0; i < n; i++) {
      cin >> arr1[i];
    }
    for (i = 0; i < n; i++) {
      cin >> arr2[i];
    }
    Solution ob;
    auto ans = ob.maximizeArray(arr1, arr2, n);
    for (auto x : ans) {
      cout << x << " ";
    }
    cout << "\n";
  }
  return 0;
}
// } Driver Code Ends
