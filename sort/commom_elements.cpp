//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// Back-end complete function Template for C++

class Solution {
public:
  vector<int> common_element(vector<int> v1, vector<int> v2) {
    // Your code here
    sort(begin(v1), end(v1));
    sort(begin(v2), end(v2));
    vector<int> ans;
    for (int i = 0, j = 0; i < v1.size() && j < v2.size();) {
      if (v1[i] < v2[j]) {
        ++i;
      } else if (v1[i] > v2[j]) {
        ++j;
      } else {
        ans.push_back(v1[i]);
        ++i;
        ++j;
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
    int n;
    cin >> n;
    vector<int> v1(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> v1[i];
    }
    int m;
    cin >> m;
    vector<int> v2(m, 0);
    for (int i = 0; i < m; i++) {
      cin >> v2[i];
    }
    Solution ob;
    vector<int> result;
    result = ob.common_element(v1, v2);
    for (auto i : result) {
      cout << i << " ";
    }
    cout << endl;
  }
}
// } Driver Code Ends
