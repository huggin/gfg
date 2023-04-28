//{ Driver Code Starts
// C++ program to rearrange an array in minimum
// maximum form
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
  // This function wants you to modify the given input
  // array and no need to return anything
  // arr: input array
  // n: size of array
  // Function to rearrange  the array elements alternately.
  void rearrange(long long *arr, int n) {
    // Your code here
    int k = 0;
    int temp = arr[0];
    int temp2 = 0;
    int total = 0;
    vector<int> v(n);
    while (total < n) {
      int nk = -1;
      if (k < n / 2) {
        nk = 2 * k + 1;
        // cout << k << ' ' << nk << endl;

      } else {
        nk = (n - 1 - k) * 2;
        // cout << k << ' ' << nk << endl;
      }
      if (v[nk] == 0) {
        v[nk] = 1;
        temp2 = arr[nk];
        arr[nk] = temp;
        temp = temp2;
        k = nk;
        ++total;
      } else {
        for (int i = 0; i < n; ++i) {
          if (v[i] == 0) {
            k = i;
            temp = arr[i];
            break;
          }
        }
      }
    }
  }
};

//{ Driver Code Starts.

// Driver program to test above function
int main() {
  int t;

  // testcases
  cin >> t;

  while (t--) {
    // size of array
    int n;
    cin >> n;

    long long arr[n];

    // adding elements to the array
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }

    Solution ob;

    // calling rearrange() function
    ob.rearrange(arr, n);

    // printing the elements
    for (int i = 0; i < n; i++)
      cout << arr[i] << " ";

    cout << endl;
  }
  return 0;
}

// } Driver Code Ends
