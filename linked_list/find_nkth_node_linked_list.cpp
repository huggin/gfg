//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

int fractional_node(struct Node *head, int k);

struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

int main() {
  int t;
  cin >> t;
  while (t--) {
    Node *ptr, *start = NULL, *ptr1;
    int n, i;
    cin >> n;

    for (i = 0; i < n; i++) {
      int value;
      cin >> value;

      ptr = new Node(value);

      if (start == NULL) {
        start = ptr;
        ptr1 = ptr;
      } else {
        ptr1->next = ptr;
        ptr1 = ptr1->next;
      }
    }
    ptr1->next = NULL;
    int k;
    cin >> k;
    int p = fractional_node(start, k);
    cout << p << endl;
  }
}

// } Driver Code Ends

/*The structure of the node is
struct Node
{
    int data;
    struct Node *next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/
int fractional_node(struct Node *head, int k) {
  // your code here
  int t = 0;
  Node *p = head;
  while (p) {
    ++t;
    p = p->next;
  }
  int n = 0;
  if (t % k == 0) {
    n = t / k;
  } else {
    n = t / k + 1;
  }
  while (--n > 0) {
    head = head->next;
  }
  return head->data;
}
