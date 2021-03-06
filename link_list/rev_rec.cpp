/*
Code : Reverse LL (Recursive)
Send Feedback
Given a linked list, reverse it using recursion.
You don't need to print the elements, just reverse the LL duplicates and return the head of updated LL.
Input format : Linked list elements (separated by space and terminated by -1)`

Sample Input 1 :
1 2 3 4 5 -1
Sample Output 1 :
5 4 3 2 1
*/

#include <iostream>
class node{
public:
    int data;
    node * next;
    node(int data){
        this->data=data;
        this->next=NULL;
    }
};

using namespace std;
// #include "solution.h"
node* takeinput(){
    int data;
    cin>>data;
    node* head=NULL,*tail=NULL;
    while(data!=-1){
        node *newnode=new node(data);
        if(head==NULL)                  {
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}

void print(node *head)
{
    node*temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

node *reverse_linked_list_rec(node *head)
{
    //write your recursive code here
    if(head->next == NULL){
        return new node(head->data);
    }else{
        node* nwHead = reverse_linked_list_rec(head->next);
        node* nwTail = new node(head->data);
        node* temp = nwHead;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = nwTail;
        return nwHead;
    }
}



int main(){
    node* head=takeinput();
    head=reverse_linked_list_rec(head);
    print(head);
    return 0;
}



