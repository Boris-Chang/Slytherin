
#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};
void printList(Node* head);
void push(Node **head_ref , int data);
int main()
{
    //初始化一个空链表
    Node* head = NULL;
    //Created Linked list will be 11->2->56->12
    push(&head,12);
    push(&head,56);
    push(&head,2);
    push(&head,11);

    //Print链表
    cout<<"Content of Circular Linked list"<<endl;
    printList(head);
    
    return 0;
}
void printList(Node* head)
{
    Node* temp = head;
    if(head!=NULL)
    {
        do
        {
            cout<<temp->data<<endl;
            temp = temp->next;
        } while (temp != head);
    }
}

void push(Node **head_ref , int data)
{
    Node *ptr1 = new Node();
    Node *temp = *head_ref;
    ptr1->data = data;
    ptr1->next = *head_ref;

    if(*head_ref != NULL)
    {
        while(temp->next != *head_ref)
        {
            temp = temp->next;
        }
        temp->next = ptr1;
    }
    else
    {
        ptr1->next = ptr1;
    }
    *head_ref = ptr1;
}
