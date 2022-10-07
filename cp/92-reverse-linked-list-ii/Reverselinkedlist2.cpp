/*
Here I will use recursive method to reverse a linked list
Algorithm :
Node* reverseList(Node* start) {
    if(!start || !(start->next))  return start;
    auto res = reverseList(start->next);
    start->next->next = start;
    start->next = NULL;
    return res;
}
*/
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

struct LinkedList
{
    Node *head;
    LinkedList()
    {
        head = NULL;
    }

    /* Function to reverse the linked list */
    Node *reverse(Node *node)
    {
        if (node == NULL)
            return NULL;
        if (node->next == NULL)
        {
            head = node;
            return node;
        }
        Node *node1 = reverse(node->next);
        node1->next = node;
        node->next = NULL;
        return node;
    }

    /* Function to print linked list */
    void print()
    {
        struct Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void push(int data)
    {
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};
int main()
{
    int t;
    cin >> t;
    LinkedList ll;
    while (t--)
    {
        long long x;
        cin >> x;
        ll.push(x);
    }

    cout << "Given linked list\n";
    ll.print();

    ll.reverse(ll.head);

    cout << "\nReversed Linked list \n";
    ll.print();
    return 0;
}