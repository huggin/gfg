//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000

// } Driver Code Ends
/*You are required to complete this method*/

class Solution {
  int getMaxArea(int* arr, int n) {
    // Your code here
    int ans = 0;
    stack<int> s;
    int i = 0;
    while (i < n) {
      while (!s.empty() && arr[s.top()] > arr[i]) {
        int tp = s.top();
        s.pop();
        if (s.empty()) {
          ans = max(ans, arr[tp] * i);
        } else {
          ans = max(ans, arr[tp] * (i - s.top() - 1));
        }
      }
      s.push(i++);
    }

    while (!s.empty()) {
      int tp = s.top();
      s.pop();
      if (s.empty())
        ans = max(ans, arr[tp] * n);
      else
        ans = max(ans, arr[tp] * (n - s.top() - 1));
    }
    return ans;
  }

 public:
  int maxArea(int M[MAX][MAX], int n, int m) {
    // Your code here
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      ans = max(ans, getMaxArea(M[i], m));
    }

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (M[i][j]) M[i][j] += M[i - 1][j];
      }
      ans = max(ans, getMaxArea(M[i], m));
    }

    return ans;
  }
};

//{ Driver Code Starts.
int main() {
  int T;
  cin >> T;

  int M[MAX][MAX];

  while (T--) {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> M[i][j];
      }
    }
    Solution obj;
    cout << obj.maxArea(M, n, m) << endl;
  }
}

// } Driver Code Ends
