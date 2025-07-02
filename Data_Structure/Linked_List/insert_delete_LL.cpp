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
    public:
    Node(int data2,Node* temp){
        data=data2;
        next=temp;
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

Node* deleteValue(Node* head,int val){
    if(head==NULL) return head;

    if(head->data==val){
        Node* temp=head;
        head=head->next;
        delete temp;
        return head;
    }
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        if(temp->data==val){
            prev->next=prev->next->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

Node* insertHead(Node* head,int val){
    Node* temp=new Node(val,head); // return new Node(val,head);
    return temp;
}

Node* insertTail(Node* head,int val){
    if(head==NULL){
        return new Node(val);
    }
    Node* temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=new Node(val);
    return head;
}

Node* insertK(Node* head,int k,int val){
    if(head==NULL){
        if(k==1) return new Node(val);
        else return NULL;
    }
    if(k==1){
        return new Node(val,head);
    }
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k-1){
            Node* x=new Node(val);
            x->next=temp->next;
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}

Node* insertVal(Node* head,int k,int val){
    if(head==NULL){
        return NULL;
    }
    if(head->data==k){
        return new Node(val,head);
    }
    Node* temp=head;
    while(temp!=NULL){
        if(temp->next->data==k){
            Node* x=new Node(val);
            x->next=temp->next;
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=ConvertArrToLL(arr);
    // head=deleteHead(head);
    // deleteValue(head,5);
    head=insertHead(head,10);
    insertTail(head,12);
    insertK(head,3,13);
    insertVal(head,4,14);
    printLL(head);
}