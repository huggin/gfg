//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  bool prime(int n) {
    if (n < 2)
      return false;
    for (int i = 2; i * i <= n; ++i)
      if (n % i == 0)
        return false;
    return true;
  }

public:
  vector<int> removeDuplicate(vector<int> &arr, int n) {
    // code here
    vector<int> ans;
    unordered_set<int> p;
    for (int i = 0; i < n; ++i) {
      if (p.find(arr[i]) != p.end())
        continue;
      if (prime(arr[i])) {
        ans.push_back(arr[i]);
        p.insert(arr[i]);
      }
    }
    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) {
      cin >> A[i];
    }
    Solution obj;
    vector<int> result = obj.removeDuplicate(A, N);
    for (int i = 0; i < result.size(); i++)
      cout << result[i] << " ";
    cout << endl;
  }
}

// } Driver Code Ends
