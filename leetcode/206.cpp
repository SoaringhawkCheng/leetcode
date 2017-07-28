//
//  206.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/21.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode dummy(-1);
        dummy.next=head;
        ListNode *curr=head;
        while(curr){
            ListNode *temp=curr;
            curr=curr->next;
            temp->next=dummy.next;
            dummy.next=temp;
        }
        return dummy.next;
    }
};

class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=NULL;
        ListNode *curr=head;
        while(curr){
            ListNode *temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        return prev;
    }
};

int main(int argc,const char *argv[]){
    
}
