#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    
    // Way 1 to pass data
    // public:
    // Node(int data1,Node* next1){
    //     data=data1;
    //     next=next1;
    // }
    
    // Way 2 to pass data
    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

Node* ConvertArrToLL(vector<int> &arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node* temp=new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}

int LengthOfLL(Node* head){
    int count=0;
    Node* temp=head;
    while(temp){
        // cout<<temp->data<<" "; // printing array
        temp=temp->next;
        count++;
    }
    return count;
}

int SearchInLL(Node* head,int val){
    Node* temp=head;
    while(temp){
        if(temp->data == val) return 1;
        temp=temp->next;
    }
    return -1;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=ConvertArrToLL(arr);
    cout<<LengthOfLL(head)<<endl;
    cout<<SearchInLL(head,3)<<endl;
}
