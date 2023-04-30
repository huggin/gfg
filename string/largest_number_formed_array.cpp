//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
// User function template for C++
bool comp(const string &l, const string &r) {
  string s = l + r;
  string t = r + l;
  return s > t;
}

class Solution {
public:
  // The main function that returns the arrangement with the largest value as
  // string.
  // The function accepts a vector of strings
  string printLargest(vector<string> &arr) {
    // code here
    sort(arr.begin(), arr.end(), comp);
    stringstream ss;
    for (int i = 0; i < arr.size(); ++i) {
      ss << arr[i];
    }
    return ss.str();
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, i;
    cin >> n;
    vector<string> arr(n);
    for (i = 0; i < n; i++) {
      cin >> arr[i];
    }
    Solution ob;
    auto ans = ob.printLargest(arr);
    cout << ans << "\n";
  }
  return 0;
}
// } Driver Code Ends
