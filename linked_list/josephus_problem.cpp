//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
/*You are required to complete this method */

struct Node {
  int val;
  Node *next;

  Node(int v, Node *p = NULL) : val(v), next(p) {}
};

class Solution {
public:
  int josephus(int n, int k) {
    // Your code here
    if (k == 1)
      return n;
    Node *head = NULL, *prev = NULL;
    for (int i = 1; i <= n; ++i) {
      Node *p = new Node(i);
      if (head == NULL) {
        head = p;
      }
      if (prev != NULL) {
        prev->next = p;
      }
      prev = p;
    }
    prev->next = head;
    Node *p = head;
    while (p->next != p) {
      for (int i = 1; i < k - 1; ++i) {
        p = p->next;
      }
      Node *q = p->next;
      p->next = p->next->next;
      p = p->next;
      delete q;
    }
    return p->val;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t; // testcases
  while (t--) {
    int n, k;
    cin >> n >> k; // taking input n and k

    // calling josephus() function
    Solution ob;
    cout << ob.josephus(n, k) << endl;
  }
  return 0;
}
// } Driver Code Ends
