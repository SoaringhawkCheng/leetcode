//
//  83.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/21.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pos=head;
        while(pos&&pos->next){
            if(pos->val==pos->next->val){
                ListNode *next=pos->next;
                pos->next=pos->next->next;
                delete next;
            }
            else
                pos=pos->next;
        }
        return head;
    }
};
