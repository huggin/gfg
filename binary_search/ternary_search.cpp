//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
 public:
  // Function to find element in sorted array
  // arr: input array
  // N: size of array
  // K: element to be searche
  int ternarySearch(int arr[], int N, int K) {
    // Your code here
    int lo = 0, hi = N - 1;
    while (lo <= hi) {
      int mid1 = lo + (hi - lo) / 3;
      int mid2 = hi - (hi - lo) / 3;
      if (arr[mid1] == K || arr[mid2] == K) return 1;
      if (arr[mid1] > K)
        hi = mid1 - 1;
      else if (arr[mid2] < K)
        lo = mid2 + 1;
      else {
        lo = mid1 + 1;
        hi = mid2 - 1;
      }
    }
    return -1;
  }
};

//{ Driver Code Starts.
int main(void) {
  int t;
  cin >> t;
  while (t--) {
    int N, K;
    cin >> N >> K;

    int arr[N];

    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }
    Solution ob;
    cout << ob.ternarySearch(arr, N, K) << endl;
  }

  return 0;
}

// } Driver Code Ends
