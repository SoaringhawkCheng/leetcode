//
//  19.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/22.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(-1);
        dummy.next=head;
        ListNode *fast=head;
        ListNode *slow=&dummy;
        for(int i=0;i<n;++i)
            fast=fast->next;
        while(fast){
            fast=fast->next;
            slow=slow->next;
        }
        ListNode *tmp=fast->next;
        fast->next=fast->next->next;
        delete tmp;
        return head;
    }
};

int main(int argc,const char *argv[]){
    return 0;
}
