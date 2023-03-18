//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
  int data;
  Node* next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};

void push(struct Node** head_ref, int new_data) {
  struct Node* new_node = new Node(new_data);

  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

int countTriplets(struct Node* head, int x);

/* Driver program to test count function*/
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x, i, num;
    struct Node* head = NULL;
    cin >> n >> x;
    for (i = 0; i < n; i++) {
      cin >> num;
      push(&head, num);
    }

    /* Check the count function */
    cout << countTriplets(head, x) << endl;
  }
  return 0;
}
// } Driver Code Ends

// User function Template for C++

int countTriplets(struct Node* head, int x) {
  // code here.
  unordered_set<int> s;
  Node* p = head;
  while (p) {
    s.insert(p->data);
    p = p->next;
  }
  int n = s.size();
  if (n < 3) return 0;
  int ans = 0;
  for (Node* i = head; i != NULL; i = i->next) {
    for (Node* j = i->next; j != NULL; j = j->next) {
      int t = x - i->data - j->data;
      if (t == i->data || t == j->data) continue;
      if (s.find(t) != s.end()) {
        // cout << t << ' ' << i->data << ' ' << j->data << endl;
        ++ans;
      }
    }
  }
  return ans / 3;
}
