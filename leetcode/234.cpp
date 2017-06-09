//
//  234.cpp
//  leetcode
//
//  Created by 追寻梦之碎片 on 2017/6/8.
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
    bool isPalindrome(ListNode* head) {
        if(head==NULL||head->next==NULL) return true;
        ListNode *fast=head;
        ListNode *slow=head;
        while(fast->next&&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        slow->next=reverseList1(slow->next);
        slow=slow->next;
        while(slow&&head->val==slow->val){
            head=head->next;
            slow=slow->next;
        }
        return slow==NULL;
    }
private:
    /*反转链表有两种写法*/
    ListNode *reverseList1(ListNode *head){
        ListNode dump(-1);
        while(head){
            ListNode *next=head->next;
            head->next=dump.next;
            dump.next=head;
            head=next;
        }
        return dump.next;
    }
    ListNode *reverseList2(ListNode *head){
        ListNode *pre=NULL,*cur=head;
        while(head){
            ListNode *next=head->next;
            head->next=pre;
            pre=head;
            head=next;
        }
        return pre;
    }
};

int main(int argc,const char *argv[]){
    vector<ListNode> list={1,2};
    for(int i=0;i<list.size()-1;++i)
        list[i].next=&list[i+1];
    Solution s;
    cout<<s.isPalindrome(&list[0])<<endl;
    return 0;
}
