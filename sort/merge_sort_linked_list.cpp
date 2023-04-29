//{ Driver Code Starts
#include <bits/stdc++.h>
#include <stdio.h>
#include <stdlib.h>

#include <iostream>
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
/* Structure of the linked list node is as
struct Node
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/

class Solution {
public:
  // Function to sort the given linked list using Merge Sort.
  Node *mergeSort(Node *head) {
    // your code here
    Node *p = head;
    int n = 0;
    while (p) {
      ++n;
      p = p->next;
    }
    if (n == 0 || n == 1)
      return head;
    p = head;
    Node *prev = NULL;
    int k = n / 2;
    while (k > 0) {
      --k;
      prev = p;
      p = p->next;
    }
    prev->next = NULL;
    Node *first = mergeSort(head);
    Node *second = mergeSort(p);
    prev = NULL;
    Node *ans = NULL;
    while (first && second) {
      if (first->data <= second->data) {
        if (ans == NULL) {
          ans = first;
        } else {
          prev->next = first;
        }
        prev = first;
        first = first->next;
      } else {
        if (ans == NULL) {
          ans = second;
        } else {
          prev->next = second;
        }
        prev = second;
        second = second->next;
      }
    }
    if (first == NULL) {
      if (prev != NULL) {
        prev->next = second;
      } else {
        ans = second;
      }
    } else if (second == NULL) {
      if (prev != NULL) {
        prev->next = first;

      } else {
        ans = first;
      }
    }

    return ans;
  }
};

//{ Driver Code Starts.

void printList(Node *node) {
  while (node != NULL) {
    printf("%d ", node->data);
    node = node->next;
  }
  printf("\n");
}

void push(struct Node **head_ref, int new_data) {
  Node *new_node = new Node(new_data);

  new_node->next = (*head_ref);
  (*head_ref) = new_node;
}

int main() {
  long test;
  cin >> test;
  while (test--) {
    struct Node *a = NULL;
    long n, tmp;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> tmp;
      push(&a, tmp);
    }
    Solution obj;
    a = obj.mergeSort(a);
    printList(a);
  }
  return 0;
}
// } Driver Code Ends
