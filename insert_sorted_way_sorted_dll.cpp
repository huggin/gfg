//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *prev, *next;
};

struct Node* getNode(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->prev = newNode->next = NULL;
  return newNode;
}

void printList(struct Node* head) {
  while (head != NULL) {
    cout << head->data << " ";
    head = head->next;
  }
}

bool isChecked(Node* head) {
  int lengthF = 0;
  int lengthB = 0;
  Node* temp = head;
  while (temp->next) {
    temp = temp->next;
    lengthF++;
  }

  while (temp->prev) {
    temp = temp->prev;
    lengthB++;
  }

  return lengthF == lengthB;
}

Node* sortedInsert(Node* head, int x);

int main() {
  int t;
  cin >> t;
  while (t--) {
    struct Node* new_node = NULL;
    int n, tmp, x;
    cin >> n;
    Node *head = NULL, *tail = NULL;
    cin >> x;
    head = getNode(x);
    tail = head;

    for (int i = 0; i < n - 1; i++) {
      cin >> x;
      Node* temp = getNode(x);
      tail->next = temp;
      temp->prev = tail;
      tail = temp;
    }
    cin >> x;
    head = sortedInsert(head, x);

    if (isChecked(head))
      printList(head);
    else
      cout << "The node has not been inserted correctly. Please fix the prev "
              "and next pointers";
    cout << endl;
  }
  return 0;
}

// } Driver Code Ends

/*structure of the node of the DLL is as
struct Node {
        int data;
        struct Node* prev, *next;
};
*/
// function should insert a new node in sorted way in
// a sorted doubly linked list
// Return the head after insertion
Node* sortedInsert(Node* head, int x) {
  // Code here
  Node* p = getNode(x);
  if (head == NULL) return p;
  if (x <= head->data) {
    p->next = head;
    head->prev = p;
    return p;
  }

  Node* q = head;
  Node* pre = NULL;
  while (q && x >= q->data) {
    pre = q;
    q = q->next;
  }
  pre->next = p;
  p->next = q;
  p->prev = pre;
  if (q) q->prev = p;
  return head;
}
