//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size) {
  for (int i = 0; i < size; i++) cout << arr[i] << " ";
}

// } Driver Code Ends
// User function Template for C++

class Solution {
 public:
  // Function to merge k sorted arrays.
  vector<int> mergeKArrays(vector<vector<int>> arr, int K) {
    // code here
    vector<int> ans;
    vector<int> pos(K, 1);
    priority_queue<pair<int, int>, vector<pair<int, int>>,
                   greater<pair<int, int>>>
        Q;
    for (int i = 0; i < K; ++i) {
      Q.emplace(arr[i][0], i);
    }
    while (!Q.empty()) {
      auto c = Q.top();
      Q.pop();
      ans.push_back(c.first);
      if (pos[c.second] < arr[c.second].size()) {
        Q.emplace(arr[c.second][pos[c.second]], c.second);
        pos[c.second]++;
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
    int k;
    cin >> k;
    vector<vector<int>> arr(k, vector<int>(k, 0));
    for (int i = 0; i < k; i++) {
      for (int j = 0; j < k; j++) {
        cin >> arr[i][j];
      }
    }
    Solution obj;
    vector<int> output = obj.mergeKArrays(arr, k);
    printArray(output, k * k);
    cout << endl;
  }
  return 0;
}

// } Driver Code Ends
