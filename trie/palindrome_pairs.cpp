//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

bool isPalindrome(const string& s, int k) {
  int n = s.size();
  for (int i = k, j = 0; i < n; ++i, ++j) {
    if (s[i] != s[n - 1 - j]) return false;
  }
  return true;
}

struct Node {
  bool leaf;
  int size;
  Node* next[26];
  Node(bool t) : leaf(t), size(0) { memset(next, 0, sizeof(next)); }
};

Node* put(Node* p, const string& key, int val, int d) {
  if (!p) p = new Node(0);
  if (d == key.size()) {
    p->leaf = true;
    ++p->size;
    return p;
  }
  char c = key[d] - 'a';
  p->next[c] = put(p->next[c], key, val, d + 1);
  return p;
}

bool get(Node* p, const string& key, int d) {
  if (!p) return false;
  if (d == key.size()) {
    if (p->leaf && (p->size >= 2 || !isPalindrome(key, 0))) return true;
    return false;
  }
  if (p->leaf && isPalindrome(key, d)) return true;

  char c = key[d] - 'a';
  return get(p->next[c], key, d + 1);
}

bool solve(string arr[], string rev[], int N) {
  Node* root = new Node(0);
  for (int i = 0; i < N; ++i) {
    root = put(root, arr[i], 1, 0);
  }
  for (int i = 0; i < N; ++i) {
    bool flag = get(root, rev[i], 0);
    if (flag) return true;
  }
  return false;
}

class Solution {
 public:
  // Function to check if a palindrome pair exists
  bool palindromepair(int N, string arr[]) {
    // code here
    if (N < 2) return 0;
    string rev[N];
    for (int i = 0; i < N; ++i) {
      rev[i].assign(arr[i].rbegin(), arr[i].rend());
    }
    return solve(arr, rev, N) || solve(rev, arr, N);
  }
};

//{ Driver Code Starts.
int main() {
  int t;
  cin >> t;
  while (t--) {
    int N;
    cin >> N;
    string arr[N];
    for (int i = 0; i < N; i++) {
      cin >> arr[i];
    }

    Solution ob;
    cout << ob.palindromepair(N, arr) << endl;
  }
  return 0;
}

// } Driver Code Ends
