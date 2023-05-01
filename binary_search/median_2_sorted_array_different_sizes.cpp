//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int> &array1, vector<int> &array2);

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
  double MedianOfArrays(vector<int> &array1, vector<int> &array2) {
    // Your code goes here
    int n = array1.size(), m = array2.size();
    if (n < m)
      return MedianOfArrays(array2, array1);
    int k = (n + m + 1) / 2;

    int lo = 0, hi = m;
    double ans = 0;
    while (lo <= hi) {
      int i = lo + (hi - lo) / 2;
      int j = k - i;

      int left2 = i > 0 ? array2[i - 1] : INT_MIN;
      int right2 = i < m ? array2[i] : INT_MAX;
      int left1 = j > 0 ? array1[j - 1] : INT_MIN;
      int right1 = j < n ? array1[j] : INT_MAX;
      // cout << left1 << ' ' << right1 << ' ' << left2 << ' ' << right2 <<
      // endl;
      if (left1 <= right2 && left2 <= right1) {
        if ((n + m) % 2 == 1) {
          return max(left1, left2);
        } else {
          return (max(left1, left2) + min(right1, right2)) / 2.0;
        }
      } else if (right2 < left1) {
        lo = i + 1;
      } else {
        hi = i - 1;
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
    int m, n;
    cin >> m;
    vector<int> array1(m);
    for (int i = 0; i < m; ++i) {
      cin >> array1[i];
    }
    cin >> n;
    vector<int> array2(n);
    for (int i = 0; i < n; ++i) {
      cin >> array2[i];
    }
    Solution ob;
    cout << ob.MedianOfArrays(array1, array2) << endl;
  }
  return 0;
}

// } Driver Code Ends
