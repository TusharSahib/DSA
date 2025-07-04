#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;
    
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
        back=nullptr;
    }
    public:
    Node(int data2,Node* next1,Node* back1){
        data=data2;
        next=next1;
        back=back1;
    }
};

Node* ConvertArrToDLL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* prev=head;
    
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i],nullptr,prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

void print(Node* head){
    while (head!=NULL)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    
}

int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=ConvertArrToDLL(arr);
    print(head);
}