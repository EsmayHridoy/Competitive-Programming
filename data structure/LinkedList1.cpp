#include<bits/stdc++.h>
using namespace std;

class node{
public:
    int val;
    node* next;

    node(int data){
        val = data;
        next = nullptr;
    }
};

node* head;


class LinkedNode{

public:
    LinkedNode()
    {
        head = nullptr;
    }
    void Insert(int val)
    {
        node* new_node = new node(val);
        if(head == nullptr){
            head = new_node;
            return;
        }
        
        node* ptr = head;
        while(ptr->next != nullptr){
            ptr = ptr->next;
        }
        ptr->next = new_node;
    }
};

class Solution {
public:
    node* middleNode(node* head) {
        node* ptr = head;
        vector<int>array;
        while(ptr->next != nullptr)
        {
            int val = ptr->val;
            ptr = ptr->next;
            array.push_back(val);               
            
        }
        array.push_back(ptr->val);
        int sz = array.size();
        int mid =(sz)/2;
        int cnt = 0;
        ptr = head;
        while(ptr->next != nullptr)
        {
            int val = ptr->val;
            ptr = ptr->next;
            cnt++;
            if(cnt == mid){
                head = ptr;
                break;
            }
        }
        return head;
    }
};

int main()
{
    int n;
    cin>>n;

    LinkedNode List;
    for(int i=0; i<n;i++){
        int x;
        cin>>x;
        List.Insert(x);
    }
    Solution obj;
    node* ptr = obj.middleNode(head);

    while(ptr->next != nullptr){
        int x = ptr->val;
        ptr = ptr->next;
        cout<<x<<"->";
    }
    int x = ptr->val;

    cout<<x<<endl;
    

}