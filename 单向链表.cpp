#include<iostream>
using namespace std;

//链表节点:
class Node
{
    public:
        int date;
        Node* next;
};
void PrintLinkedList(Node* n);
int main()
{
    Node* head = NULL;
    Node* second = NULL;
    Node* third = NULL;
    //在heap中申请3个空间：
    head = new Node();
    second = new Node();
    third = new Node();
    //对每个表赋值，并讲它们链接在一起
    head->date = 1;
    head->next = second;
    second->date = 2;
    second->next = third;
    third->date = 3;
    third->next = NULL;
    //打印链表
    PrintLinkedList(head);
    
    return 0;
}
void PrintLinkedList(Node* n)
{
    while(n!=NULL)
    {
        cout<<n->date<<endl;
        n = n->next;
    }
}
