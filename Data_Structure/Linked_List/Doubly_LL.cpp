#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }

public:
    Node(int data2, Node *next1, Node *back1)
    {
        data = data2;
        next = next1;
        back = back1;
    }
};

Node *ConvertArrToDLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

Node *removeHead(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *prev = head;
    head = head->next;

    head->back = nullptr;
    prev->next = nullptr;

    delete prev;
    return head;
}

Node *removeTail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        delete head;
        return NULL;
    }

    Node *temp = head;
    while (temp->next->next != NULL)
        temp = temp->next;

    Node *last = temp->next;
    temp->next = NULL;
    delete last;
    return head;
}


Node *removeK(Node *head, int k)
{
    if (head == NULL)
        return NULL;

    Node *temp = head;
    int count = 1;
    while (temp != NULL && count < k)
    {
        temp = temp->next;
        count++;
    }

    if (temp == NULL)
        return head; // k is out of bounds

    if (temp->back == NULL)
        return removeHead(head);
    else if (temp->next == NULL)
        return removeTail(head);
    else
    {
        Node *prev = temp->back;
        Node *front = temp->next;

        prev->next = front;
        front->back = prev;

        delete temp;
        return head;
    }
}


int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    Node *head = ConvertArrToDLL(arr);
    head = removeK(head, 5);
    print(head);
}