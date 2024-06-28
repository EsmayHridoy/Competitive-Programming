#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int val;
    node* next;
    node(int data)
    {
        val = data;
        next = nullptr;
    }
};

node* head;
class ListNode{
public:
    ListNode(){
        head = nullptr;
    }
    void insert(int data){
        node* new_node = new node(data);
        if(head == nullptr){
            head = new_node;
            return;
        }
        node* ptr;
        ptr = head;
        while(ptr->next != nullptr){
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
};


class Solution {
public:
    node* reverseList(node* head) {
        node* ptr = head->next;
        node* tmp = head;
        tmp->next = nullptr;
        while(ptr->next != nullptr){
            node* t = ptr->next;
            ptr->next = tmp;
            tmp = ptr;
            ptr = t;
        }
        ptr->next = tmp;
        tmp = ptr;

        return tmp;
    }
};


int main()
{
    int n;
    cin>>n;
    ListNode List;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        List.insert(x);
    }
    node* ptr=head;
    while(ptr->next != nullptr){
        cout<<ptr->val<<"->";
        ptr=ptr->next;
    }
    cout<<ptr->val<<endl;
    Solution obj;
    node* ans = obj.reverseList(head);
    while(ans->next != nullptr){
        cout<<ans->val<<"->";
        ans=ans->next;
    }
    cout<<ans->val<<endl;
}