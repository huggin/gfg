//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
 public:
  // Function to rotate a linked list.
  Node *rotate(Node *head, int k) {
    // Your code here
    Node *p = head;
    Node *prev = NULL;
    for (int i = 0; p != NULL && i < k; ++i) {
      prev = p;
      p = p->next;
    }
    if (p == NULL) return head;
    prev->next = NULL;
    Node *q = p;
    while (q->next != NULL) {
      q = q->next;
    }
    q->next = head;
    return p;
  }
};

//{ Driver Code Starts.

void printList(Node *n) {
  while (n != NULL) {
    cout << n->data << " ";
    n = n->next;
  }
  cout << endl;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, val, k;
    cin >> n;

    cin >> val;
    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < n - 1; i++) {
      cin >> val;
      tail->next = new Node(val);
      tail = tail->next;
    }

    cin >> k;

    Solution ob;
    head = ob.rotate(head, k);
    printList(head);
  }
  return 1;
}

// } Driver Code Ends
