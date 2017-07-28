//
//  24.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/22.
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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode dummy(-1);
        dummy.next=head;
        ListNode *prev=&dummy;
        ListNode *cur=dummy.next;
        while(cur&&cur->next){
            ListNode *next=cur->next;
            cur->next=next->next;
            prev->next=next;
            next->next=cur;
            prev=cur;
            cur=cur->next;
        }
        return dummy.next;
    }
};

int main(int argc,const char *argv[]){
    vector<ListNode> list={1,2,3,4};
    list[0].next=&list[1];
    list[1].next=&list[2];
    list[2].next=&list[3];
    ListNode *head=&list[0];
    Solution s;
    head=s.swapPairs(head);
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
    return 0;
}
