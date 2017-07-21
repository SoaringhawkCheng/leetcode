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
        while(head){
            ListNode *tmp=head;
            head=head->next;
            tmp->next=dummy.next;
            dummy.next=tmp;
        }
        return dummy.next;
    }
};

class Solution2 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *prev=NULL;
        ListNode *cur=head;
        while(cur){
            ListNode *tmp=cur;
            cur=cur->next;
            tmp->next=prev;
            prev=tmp;
        }
        return prev;
    }
};

int main(int argc,const char *argv[]){
    
}
