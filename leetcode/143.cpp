//
//  143.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/23.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* &head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL) return;
        ListNode *fast,*slow;
        fast=slow=head;
        while(fast->next&&fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *head2=slow->next;
        slow->next=NULL;
        head2=reverselist(head2);
        ListNode *curr=head;
        while(head2){
            ListNode *temp=head2;
            head2=head2->next;
            temp->next=curr->next;
            curr->next=temp;
            curr=temp->next;
        }
    }
private:
    ListNode *reverselist(ListNode *head2){
        ListNode *prev=NULL;
        ListNode *curr=head2;
        while(curr){
            ListNode *temp=curr;
            curr=curr->next;
            temp->next=prev;
            prev=temp;
        }
        return prev;
    }
};

int main(int argc,const char *argv[]){
    vector<ListNode> list={0,1,2,3,4,5,6};
    list[0].next=&list[1];
    list[1].next=&list[2];
    list[2].next=&list[3];
    list[3].next=&list[4];
    list[4].next=&list[5];
    list[5].next=&list[6];
    ListNode *head=&list[0];
    Solution s;
    s.reorderList(head);
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}
