//{ Driver Code Starts
#include <iostream>
#include <cstdio>
using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
};

/* A utility function to insert a node at the beginning of linked list */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node = new node(new_data);
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* A utility function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
void quickSort(struct node **headRef);
int main()
{
	int t,n,x;
	cin>>t;
	while(t--){
		
        
        cin>>n;n=n-1;
		cin>>x;
        node *temp,*head = new node(x);
        temp=head;
        while(n--)
        {
			cin>>x;
          temp->next=new node(x);
          temp=temp->next;
			}
    
    quickSort(&head);
 
    printList(head);
 while(head!= NULL){
     temp=head;
     head=head->next;
     free(temp);
     
 }
	}
    return 0;
}
// } Driver Code Ends


 
/* a node of the singly linked list 
struct node
{
    int data;
    struct node *next;
    
    node(int x){
        data = x;
        next = NULL;
    }
}; */

//you have to complete this function
node* qSort(node* head) {
    if (head == NULL || head->next == NULL) return head;
    
    int pivot = head->data;
    node* left_head = NULL, *left_tail = NULL, *right_head = NULL, *right_tail = NULL;
    node* current = head->next;
    while(current) {
        if (current->data < pivot) {
            if (left_head == NULL) {
                left_head = current;
                left_tail = current;
            } else {
                left_tail->next = current;
                left_tail = current;
            }
        } else {
            if (right_head == NULL) {
                right_head = current;
                right_tail = current;
            } else {
                right_tail->next = current;
                right_tail = current;
            }
        }
        current = current->next;
    }
    if (left_tail)
        left_tail->next = NULL;
    if (right_tail)
        right_tail->next = NULL;
    
    node* left = qSort(left_head);
    node* right = qSort(right_head);
    
    if (!left) {
        head->next = right;
        return head;
    } else {
        node * temp = left;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head;
        head->next = right;
        return left;
    }
    
}

//you have to complete this function
void quickSort(struct node **headRef) {
    if (*headRef == NULL || (*headRef)->next == NULL) return;
    node* head = *headRef;
    *headRef = qSort(head);
}
