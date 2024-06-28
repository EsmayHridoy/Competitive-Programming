#include<bits/stdc++.h>

using namespace std;


class node{

public:
    int data;
    node* next;

    node(int val){
        data = val;
        next = nullptr;
    }
};

node* head;

class LinkedList{    
public:
    LinkedList()
    {
        head = nullptr;
    }

    void insert(int val)
    {
        node* new_node = new node(val);
        if(head == nullptr){
            head = new_node;
            return;
        }
        node* tmp = head;

        while(tmp->next != nullptr)
        {
            tmp = tmp->next;
        }

        tmp->next = new_node;
    }
};

class Solution {
public:
    int getDecimalValue(Node* head) {
        vector<int>vc;
        Node* ptr = head;

        while(ptr->next != nullptr){
            int x=ptr->data;
            ptr = ptr->next;
            vc.push_back(x);
        }
        int x = ptr->data;
        vc.push_back(x);

        

        reverse(vc.begin(),vc.end());

        int ans = 0;
        int pw = 1;
        for(auto x:vc){
            ans += (pw * x);
            pw = pw<<1;
        }
        return ans;
    }
};

int main()
{
    
    LinkedList LIST;

    for(int i=0; i<5; i++){
        int x;
        cin>>x;
        LIST.insert(x);
    }

    node* ptr = head;

    while(ptr->next != nullptr){
        cout<<ptr->data<<"->";
        ptr = ptr->next;
    }
    cout<<ptr->data<<endl;

    Solution obj;

    int ans = obj.getDecimalValue(head);
    cout<<ans<<endl;

    return 0;
}