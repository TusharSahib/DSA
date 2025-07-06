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
        return NULL;
    }

    Node *prev = head;
    while (prev != NULL)
    {
        if (prev->next->next == NULL)
        {
            Node *temp = prev->next;
            temp->back == nullptr;
            prev->next = nullptr;
            delete temp;
        }

        prev = prev->next;
    }
    return head;
}

Node *removeK(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        if (count == k)
            break;
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *front = temp->next;

    if (prev == NULL || front == NULL)
    {
        delete temp;
        return NULL;
    }
    else if (prev == NULL)
    {
        return removeHead(head);
    }
    else if (front == NULL)
    {
        return removeTail(head);
    }

    prev->next = front;
    front->back = prev;

    temp->back = NULL;
    temp->next = NULL;

    delete temp;
    return head;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    Node *head = ConvertArrToDLL(arr);
    print(head);
    head = removeK(head, 1);
    print(head);
}