//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int Search(vector<int>, int);

// User code will be pasted here

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> vec(n);

    for (int i = 0; i < n; i++)
      cin >> vec[i];

    int target;
    cin >> target;

    cout << Search(vec, target) << "\n";
  }
}
// } Driver Code Ends

// User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find
int Search(vector<int> vec, int K) {
  // code here
  int lo = 0, hi = vec.size() - 1;
  while (lo <= hi) {
    int mi = lo + (hi - lo) / 2;
    if (vec[mi] == K)
      return mi;
    if (vec[lo] < vec[mi]) {
      if (vec[lo] <= K && K < vec[mi]) {
        hi = mi - 1;
      } else {
        lo = mi + 1;
      }
    } else {
      if (vec[mi] < K && K <= vec[hi]) {
        lo = mi + 1;
      } else {
        hi = mi - 1;
      }
    }
  }
  return -1;
}
