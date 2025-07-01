#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

Node* ConvertArrToLL(vector<int> arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

Node* printLL(Node* head){
    Node* temp=head;
    while(temp){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    return head;
}

Node* deleteHead(Node* head){
    if(head==NULL) return head;
    Node* temp=head;
    head=head->next;
    delete temp; // free(temp) // same use
    return head;
}

Node* deleteTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;

    Node* temp =head;

    while(head->next->next != NULL){
        temp=temp->next;
    }
    delete temp->next; //free(temp->next);
    temp->next=nullptr;
    return head;
}

Node* deleteK(Node* head,int k){
    if(head==NULL) return head;

    if(k==1){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    int cnt=0;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=ConvertArrToLL(arr);
    // head=deleteHead(head);
    deleteK(head,3);
    printLL(head);
}