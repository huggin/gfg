//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  int ans;
public:
  void merge(vector<int> &a, int lo, int hi, int mi) {
    vector<int> b(hi - lo + 1, 0);
    int i = lo, j = mi + 1, k = 0;
    while (i <= mi || j <= hi) {
      if (i > mi) {
        b[k] = a[j];
        j++;
      } else if (j > hi) {
        b[k] = a[i];
        i++;
      } else if (a[i] < a[j]) {
        b[k] = a[i];
        i++;
      } else {
        b[k] = a[j];
        j++;
      }
      k++;
    }
    i = lo, j = mi + 1;
    while (i <= mi && j <= hi) {
      if (a[i] > 2 * a[j]) {
        ans += mi - i + 1;
        j++;
      } else {
        i++;
      }
    }
    copy(b.begin(), b.end(), a.begin() + lo);
  }

  void mergeSort(vector<int> &a, int lo, int hi) {
    if (lo >= hi) {
      return;
    }
    int mi = (lo + hi) / 2;
    mergeSort(a, lo, mi);
    mergeSort(a, mi + 1, hi);
    merge(a, lo, hi, mi);
  }

  int countRevPairs(int N, vector<int> &arr) {
    ans = 0;
    mergeSort(arr, 0, N - 1);
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
    vector<int> arr;

    for (int i = 0; i < n; ++i) {
      int x;
      cin >> x;
      arr.push_back(x);
    }

    Solution obj;
    cout << obj.countRevPairs(n, arr) << endl;
  }
  return 0;
}
// } Driver Code Ends
