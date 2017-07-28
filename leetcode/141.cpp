//
//  141.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/7/23.
//  Copyright © 2017年 追寻梦之碎片. All rights reserved.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution1 {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast,*slow;
        fast=slow=head;
        while(fast&&fast->next){
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow) return true;
        }
        return false;
    }
};

int main(int argc,const char *argv[]){
    return 0;
}
