//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node* next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

void printList(Node* node) {
  while (node != NULL) {
    cout << node->data;
    node = node->next;
  }
  cout << "\n";
}

// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  int add(Node* p) {
    if (!p->next) {
      if (++p->data == 10) {
        p->data = 0;
        return 1;
      } else {
        return 0;
      }
    } else {
      int k = add(p->next);
      if (k == 0) return 0;
      if (++p->data == 10) {
        p->data = 0;
        return 1;
      }
    }
  }

 public:
  Node* addOne(Node* head) {
    // Your Code here
    // return head of list after adding one
    if (add(head)) {
      Node* p = new Node(1);
      p->next = head;
      return p;
    }
    return head;
  }
};

//{ Driver Code Starts.

int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    Node* head = new Node(s[0] - '0');
    Node* tail = head;
    for (int i = 1; i < s.size(); i++) {
      tail->next = new Node(s[i] - '0');
      tail = tail->next;
    }
    Solution ob;
    head = ob.addOne(head);
    printList(head);
  }
  return 0;
}

// } Driver Code Ends
