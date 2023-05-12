//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>

#include <string>

using namespace std;

// } Driver Code Ends
// User function Template for C++

string v[10] = {"",    "",    "abc",  "def", "ghi",
                "jkl", "mno", "pqrs", "tuv", "wxyz"};

class Solution {
  vector<string> ans;
  int n;

  void go(int a[], int k, string s) {
    if (k == n) {
      ans.push_back(s);
      return;
    }
    for (int i = 0; i < v[a[k]].size(); ++i) {
      s.push_back(v[a[k]][i]);
      go(a, k + 1, s);
      s.pop_back();
    }
  }

public:
  // Function to find list of all words possible by pressing given numbers.
  vector<string> possibleWords(int a[], int N) {
    // Your code here
    ans.clear();
    n = N;
    go(a, 0, "");
    return ans;
  }
};

//{ Driver Code Starts.

int main() {
  int T;

  cin >> T; // testcases

  while (T--) { // while testcases exist
    int N;

    cin >> N; // input size of array

    int a[N]; // declare the array

    for (int i = 0; i < N; i++) {
      cin >> a[i]; // input the elements of array that are keys to be pressed
    }

    Solution obj;

    vector<string> res = obj.possibleWords(a, N);
    for (string i : res)
      cout << i << " ";
    cout << endl;
  }

  return 0;
}
// } Driver Code Ends
